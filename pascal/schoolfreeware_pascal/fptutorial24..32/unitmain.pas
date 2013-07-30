unit UnitMain;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TfrmMain }

  TfrmMain = class(TForm)
    btnSubmit: TButton;
    edMin: TEdit;
    edHour: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    lblCorrect: TLabel;
    procedure btnSubmitClick(Sender: TObject);
    procedure edHourKeyPress(Sender: TObject; var Key: char);
    procedure edMinKeyPress(Sender: TObject; var Key: char);
    procedure FormPaint(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
    hour: integer;
    min: integer;
    correct: integer;
    question: integer;
    procedure CheckAnswer;
    procedure DrawClock;
    procedure GetHourMin;
  end; 

var
  frmMain: TfrmMain;

implementation

{$R *.lfm}

{ TfrmMain }

procedure TfrmMain.CheckAnswer;
begin
  if (hour = StrToInt(edHour.Text)) and (min = StrToInt(edMin.Text)) then
  begin
    correct := correct + 1;
  end
  else
  begin
    if min = 0 then
      ShowMessage('The Time is: ' + IntToStr(hour) + ':00')
    else if min = 5 then
      ShowMessage('The Time is: ' + IntToStr(hour) + ':05')
    else
      ShowMessage('The Time is: ' + IntToStr(hour) + ':' + IntToStr(min));
  end;

  question := question + 1;
  lblCorrect.Caption := 'Correct: ' + IntToStr(correct) + '/' + IntToStr(question);

  edMin.Clear;
  edHour.Clear;
  edHour.SetFocus;
  refresh;
end;

procedure TfrmMain.DrawClock;
var
  AdjHours: real;
const
  Pie = 3.14;
begin

  { draw empty clock }
  Canvas.Pen.Color := clBlack;
  Canvas.Pen.Width := 10;
  Canvas.Brush.Color := clLtGray;
  Canvas.Ellipse(50,50,500,500);
  Canvas.Font.Size := 30;

  Canvas.TextOut(254, 59, '12');
  Canvas.TextOut(362, 83, '1');
  Canvas.TextOut(425, 153, '2');
  Canvas.TextOut(457, 250, '3');
  Canvas.TextOut(425, 347, '4');
  Canvas.TextOut(362, 417, '5');
  Canvas.TextOut(260, 440, '6');
  Canvas.TextOut(165, 417, '7');
  Canvas.TextOut(95, 347, '8');
  Canvas.TextOut(70, 250, '9');
  Canvas.TextOut(95, 153, '10');
  Canvas.TextOut(165, 83, '11');

  { draw hour hand }
  AdjHours := hour + min / 60;
  Canvas.Pen.Color := clRed;
  Canvas.Pen.Width := 25;
  Canvas.Line(275, 275, trunc(130 * cos((Pi) / 180 * (30 * AdjHours - 90)) + 275),
    trunc(135 * sin((Pi) / 180 * (30 * AdjHours - 90)) + 275));

  { draw minute hand }
  Canvas.Pen.Color := clGreen;
  Canvas.Pen.Width := 10;
  Canvas.Line(275, 275, trunc(175 * cos((Pi) / 180 * (6 * min - 90)) + 275),
    trunc(160 * sin((Pi) / 180 * (6 * min - 90)) + 275));

  { draw cirle in middle }
  Canvas.Pen.Color := clBlack;
  Canvas.Pen.Width := 20;
  Canvas.Ellipse(265, 265, 285, 285);
end;

procedure TfrmMain.GetHourMin;
begin
  randomize;
  hour := random(12) + 1;
  randomize;
  repeat
    min := random(60);
  until min mod 5 = 0;
end;

procedure TfrmMain.btnSubmitClick(Sender: TObject);
begin
  if (edHour.Text <> '') and (edMin.Text <> '') then
    CheckAnswer;
  refresh;
end;

procedure TfrmMain.edHourKeyPress(Sender: TObject; var Key: char);
begin
  if (edHour.Text <> '') and (edMin.Text <> '') and (Key = Chr(13)) then
  begin
    Key := ' ';
    CheckAnswer;
  end;
end;

procedure TfrmMain.edMinKeyPress(Sender: TObject; var Key: char);
begin
  if (edHour.Text <> '') and (edMin.Text <> '') and (Key = Chr(13)) then
  begin
    Key := ' ';
    CheckAnswer;
  end;
end;

procedure TfrmMain.FormPaint(Sender: TObject);
begin
  GetHourMin;
  DrawClock;
end;

end.

