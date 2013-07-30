program fptutorial12;

{$mode objfpc}{$M+}

uses 
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads.
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
var 
  number: integer;
  
procedure StopProgram;
begin
  writeln; writeln;
  writeln('Press <Enter> to quit');
  readln;
end;

function squared(var x: integer): integer;
begin
  squared := x * x;
end;

function abs(var x: integer): integer;
begin
  if x >= 0 then
    abs := x;
  else 
    abs := x * -1;
end;

begin {main}
  write('Enter an Integer: ');
  readln(number);
  writeln('The number squared is: ', squared(number));
  writeln('The Absolute Value is: ', abs(number));
  StopProgram;
end.
