program fptutorial11a;
{ procedure example 1 }

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
procedure StopProgram;
begin
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end; { the end of the StopProgram procedure }

begin { main }
  writeln('5 * 5 = ', 5 * 5);
  StopProgram;
end.
