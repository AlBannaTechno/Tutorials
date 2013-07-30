unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Shape1: TShape;
    Shape2: TShape;
    Shape3: TShape;
    Shape4: TShape;
    Shape5: TShape;
    Shape6: TShape;
    Timer1: TTimer;
    procedure FormCreate(Sender: TObject);
    procedure FormKeyPress(Sender: TObject; var Key: char);
    procedure Timer1Timer(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
    Shape: Array[0..5] of TShape;
    MoveRight: Array[0..5] of Boolean;
    MoveUp: Array[0..5] of Boolean;
  end; 

var
  Form1: TForm1;
  x: integer;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  for x := 0 to 5 do
  begin
    if MoveRight[x] = True then
      Shape[x].Left := Shape[x].Left + 1
    else
      Shape[x].Left := Shape[x].Left - 1;

    if Shape[x].Left <= 0 then
      MoveRight[x] := True;

    if Shape[x].Left + Shape[x].Width >= Form1.Width then
      MoveRight[x] := False;

    if MoveUp[x] = True then
      Shape[x].Top := Shape[x].Top - 1
    else
      Shape[x].Top := Shape[x].Top + 1;

    if Shape[x].Top <= 0 then
      MoveUp[x] := False;

    if Shape[x].Top + Shape[x].Height >= Form1.Height then
      MoveUp[x] := True;
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  Form1.DoubleBuffered := True;

  Shape[0] := Shape1;
  Shape[1] := Shape2;
  Shape[2] := Shape3;
  Shape[3] := Shape4;
  Shape[4] := Shape5;
  Shape[5] := Shape6;
end;

procedure TForm1.FormKeyPress(Sender: TObject; var Key: char);
begin
  if ((Key = 'p') or (Key = 'P')) and (Timer1.Enabled = True) then
    Timer1.Enabled := False
  else if ((Key = 'p') or (Key = 'P')) and (Timer1.Enabled = False) then
    Timer1.Enabled := True;
end;

end.

