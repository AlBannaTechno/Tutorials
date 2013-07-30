unit UnitSplash; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls,
  StdCtrls;

type

  { TfrmSplash }

  TfrmSplash = class(TForm)
    Image1: TImage;
    Label1: TLabel;
    Timer1: TTimer;
    procedure FormCreate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
    x: integer;
  end; 

var
  frmSplash: TfrmSplash;

implementation

{$R *.lfm}

{ TfrmSplash }

procedure TfrmSplash.Timer1Timer(Sender: TObject);
begin
  if x < 5 then
    x := x + 1
  else
    frmSplash.Close;
end;

procedure TfrmSplash.FormCreate(Sender: TObject);
begin
  frmSplash.AutoScroll := False;
  x := 0;
end;

end.

