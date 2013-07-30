program fptutorial9a;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
var
  FirstName: array[0..4] of string;
  x: integer;
  
begin
  FirstName[0] := 'Joe';
  FirstName[1] := 'Jim';
  FirstName[2] := 'Jill';
  FirstName[3] := 'Joan';
  FirstName[4] := 'Jan';
  
  for x := 0 to 4 do
  begin
    writeln(FirstName[x]);
  end;
  
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end.
