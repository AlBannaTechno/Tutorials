unit UnitMain; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls, StrUtils;

type

  { TForm1 }
  TheMisSpelled = (TEH, ETH, EHT); { enumeration of 'the' miss-spellings }
  TForm1 = class(TForm)
    LoadButton: TButton;
    SaveButton: TButton;
    CorrectButton: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    MemoBox: TMemo;
    procedure CorrectButtonClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure LoadButtonClick(Sender: TObject);
    procedure SaveButtonClick(Sender: TObject);
  private
    { private declarations }
    function ChangeText(var fText: String; theType: TheMisSpelled): Boolean;
  public
    { public declarations }
  end; 

var
  Form1: TForm1;
  fileName: String;
  fileData: TStringList;
  openDialog: TOpenDialog;

implementation

{$R *.lfm}

{ TForm1 }

function TForm1.ChangeText(var fText: String; theType: TheMisSpelled): Boolean;
var
  tChanged: Boolean;
begin
  { indicate no changes yet }
  tChanged := False;

  { first see if the string contains the desired string }
  case theType of
    TEH:
      if AnsiContainsStr(fText, 'teh') or AnsiContainsStr(fText, 'Teh') then
      begin
        fText := AnsiReplaceStr(fText, 'teh', 'the');
        fText := AnsiReplaceStr(fText, 'Teh', 'The');
        tChanged := True;
      end;
    ETH:
      if AnsiContainsStr(fText, 'eth') then
      begin
        fText := AnsiReplaceStr(fText, 'eth', 'the');
        tChanged := True;
      end;
    EHT:
      if AnsiContainsStr(fText, 'eht') then
      begin
        fText := AnsiReplaceStr(fText, 'eht', 'the');
        tChanged := True;
      end;
  end;

  { returns the changed status }
  Result := tChanged;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  { set the title of the form - our application title }
  Form1.Caption := 'Very Simple Spelling Corrector';

  { disable all except the load file button }
  SaveButton.Enabled := False;
  CorrectButton.Enabled := False;

  { clear the file display box }
  MemoBox.Clear;

  { Enable scroll bars for this memo box }
  MemoBox.ScrollBars := ssBoth;

  { do not allow the user to directly type into the displayed file text }
  MemoBox.ReadOnly := True;

  { set the font of the memo box to a mono-spaced one to ease reading }
  MemoBox.Font.Name := 'Courier New';

  { set all of the labels to blank }
  Label1.Caption := '';
  Label2.Caption := '';
  Label3.Caption := '';
  Label4.Caption := '';

  { create the open dialog object - used by the GetTextFile routine }
  openDialog := TOpenDialog.Create(self);

  { ask for only files that exist }
  openDialog.Options := [ofFileMustExist];

  { ask for only text files }
  openDialog.Filter := 'Text Files|*.txt';

  { create the string object that holds the file contents }
  fileData := TStringList.Create;
end;

procedure TForm1.CorrectButtonClick(Sender: TObject);
var
  fText: String;
  line: Integer;
  changeCounts: array[TEH..EHT] of Integer;
begin
  { set the changed line counts }
  changeCounts[TEH] := 0;
  changeCounts[ETH] := 0;
  changeCounts[EHT] := 0;

  { process each line of the file one at a time }
  for line := 0 to fileData.Count - 1 do
  begin
    { store the current line in a single variable }
    fText := fileData[line];

    { change the 3 chosen basic ways of misspelling 'the' }
    if ChangeText(fText, TEH) then Inc(changeCounts[TEH]);
    if ChangeText(fText, ETH) then Inc(changeCounts[ETH]);
    if ChangeText(fText, EHT) then Inc(changeCounts[EHT]);

    { and store this padded string back into the string list }
    fileData[line] := fText;
  end;

  { redisplay the file }
  MemoBox.Text := fileData.Text;

  { Display the changed line totals }
  if changeCounts[TEH] = 1
  then Label1.Caption := 'Teh/teh changed on 1 line'
  else Label1.Caption := 'Teh/teh changed on ' + IntToStr(changeCounts[TEH]) + ' lines';

  if changeCounts[ETH] = 1
  then Label2.Caption := 'eth changed on 1 line'
  else Label2.Caption := 'eth changed on ' + IntToStr(changeCounts[ETH]) + ' lines';

  if changeCounts[EHT] = 1
  then Label3.Caption := 'eht changed on 1 line'
  else Label3.Caption := 'eht changed on ' + IntToStr(changeCounts[EHT]) + ' lines';

  { finally, indicate that the file is now eligible for saving }
  SaveButton.Enabled := True;

  { and that no more corrections are necessary }
  CorrectButton.Enabled := False;
end;

procedure TForm1.LoadButtonClick(Sender: TObject);
begin
  { display the file selection dialog }
  if openDialog.Execute then
  begin
    { save the file name }
    fileName := openDialog.FileName;

    { now that we have the file loaded, enable the text correction button }
    CorrectButton.Enabled := True;

    { load the file into our stringlist }
    fileData.LoadFromFile(fileName);
  end;

  { display the file in the file display box }
  MemoBox.Text := fileData.Text;

  { clear the changed lines information }
  Label1.Caption := '';
  Label2.Caption := '';
  Label3.Caption := '';

  { display the number of lines in the file }
  Label4.Caption := fileName + ' has ' + IntToStr(fileData.Count) + ' lines of text';
end;

procedure TForm1.SaveButtonClick(Sender: TObject);
begin
  { simply save the contents of the file string list }
  if fileName <> '' then
    fileData.SaveToFile(fileName);

  { and disable the file save button }
  SaveButton.Enabled := False;
end;

end.

