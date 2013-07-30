program fptutorial11b;
{ procedure example 2 }

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
var 
  x: integer;
  
procedure proc1;
begin
  writeln('X in Proc1 = ', x);
end;

procedure proc2;
var
  x: integer;
begin
  x := 20;
  writeln('X in Proc2 = ', x);
end;

procedure StopProgram;
begin
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln();
end;

begin
  x := 35;
  proc1;
  proc2;
  StopProgram;
end.
