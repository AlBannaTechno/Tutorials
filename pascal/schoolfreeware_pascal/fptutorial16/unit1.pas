unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Label1MouseEnter(Sender: TObject);
    procedure Label1MouseLeave(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  Form1: TForm1; 

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
begin
  with Label1 do
  begin
    Caption := 'Button1 was Clicked';
    Font.Color := clBlue;
    Font.Size := 12;
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  with Label1 do
  begin
    Caption := 'Button2 was Clicked';
    Font.Color := clRed;
    Font.Size := 17;
  end;
end;

procedure TForm1.Label1MouseEnter(Sender: TObject);
begin
  Label1.Caption := 'Mouse Over Me!';
end;

procedure TForm1.Label1MouseLeave(Sender: TObject);
begin
  Label1.Caption := 'The Mouse Left!';
end;

end.

