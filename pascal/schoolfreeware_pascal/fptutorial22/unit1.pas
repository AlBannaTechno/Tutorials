unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Shape1: TShape;
    Timer1: TTimer;
    procedure FormCreate(Sender: TObject);
    procedure FormKeyPress(Sender: TObject; var Key: char);
    procedure Timer1Timer(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
    MoveRight, MoveUp: Boolean;
  end; 

var
  Form1: TForm1; 

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  if MoveRight = True then
    Shape1.Left := Shape1.Left + 1
  else
    Shape1.Left := Shape1.Left - 1;

  if Shape1.Left <= 0 then
    MoveRight := True;

  if Shape1.Left + Shape1.Width >= Form1.Width then
    MoveRight := False;

  if MoveUp = True then
    Shape1.Top := Shape1.Top - 1
  else
    Shape1.Top := Shape1.Top + 1;

  if Shape1.Top <= 0 then
    MoveUp := False;

  if Shape1.Top + Shape1.Height >= Form1.Height then
    MoveUp := True;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  Form1.DoubleBuffered := True;
end;

procedure TForm1.FormKeyPress(Sender: TObject; var Key: char);
begin
  if ((Key = 'p') or (Key = 'P')) and (Timer1.Enabled = True) then
    Timer1.Enabled := False
  else if ((Key = 'p') or (Key = 'P')) and (Timer1.Enabled = False) then
    Timer1.Enabled := True;
end;

end.

