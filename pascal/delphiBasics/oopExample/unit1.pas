{ Full Unit Code.
  --------------------------------------------------
  Must be stored in a unit called Unit1 with a form called Form1 that has an OnCreate event called
  FormCreate.
}
unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, Variants;

type
  { define a ball class }
  TBall = class
  protected
    ballSize: Byte;
    ballSpeed: Byte;
  public
    procedure Kick(power: Byte); virtual;
    function GetSpeed: Byte;
    constructor Create(size: Byte);
  end;

  { define a specialized ball }
  TFootball = class(TBall)
  private
    ballPanels: Byte;
  public
    { override of the TBall Kick method to take into account the number of panels of the ball }
    procedure Kick(power: Byte); virtual;
    { different constructor needed to include panels }
    constructor Create(size: Byte; panels: Byte);
  end;

  { TForm1 }

  TForm1 = class(TForm)
    procedure FormCreate(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1; 

implementation

{$R *.lfm}

{ ball method implementations }
procedure TBall.Kick(power: Byte);
begin
  ballSpeed := (power * ballSize) DIV 4;
end;

function TBall.GetSpeed: Byte;
begin
  Result := ballSpeed;
end;

constructor TBall.Create(size: Byte);
begin
  ballSize := size;
  ballSpeed := 0;
end;

{ football method implementation }
procedure TFootball.Kick(power: Byte);
begin
  { Now take the number of panels into account }
  ballSpeed := (power * ballSize * ballPanels) DIV 24;
end;

constructor TFootball.Create(size: Byte; panels: Byte);
begin
  Inherited Create(size);  { call the parent constructor first }
  ballPanels := panels;
end;

{ the form OnCreate implementation }
procedure TForm1.FormCreate(Sender: TObject);
var
  beachBall: TBall;
  soccerBall: TFootball;
begin
  { create the two balls }
  beachBall := TBall.Create(5);
  soccerBall := TFootball.Create(5, 12);

  { how fast are they at the moment? }
  ShowMessageFmt('Beach ball is moving at speed: %d', [beachBall.GetSpeed]);
  ShowMessageFmt('Soccer ball is moving at speed: %d', [soccerBall.GetSpeed]);

  { now kick each bakk with a power of 10 }
  beachBall.Kick(10);
  soccerBall.Kick(10);

  { how fast are they moving now? }
  ShowMessageFmt('Beach ball is moving at speed: %d', [beachBall.GetSpeed]);
  ShowMessageFmt('Soccer ball is moving at speed: %d', [soccerBall.GetSpeed]);
end;

end.

