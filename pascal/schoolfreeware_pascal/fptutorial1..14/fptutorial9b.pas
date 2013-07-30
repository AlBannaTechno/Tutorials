program fptutorial9b;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
var
  nums: array[0..5] of integer;
  x: integer;
  sum: integer;
  
begin
  nums[0] := 5;
  nums[1] := 4;
  nums[2] := 9;
  nums[3] := -1;
  nums[4] := 2;
  nums[5] := 15;
  
  sum := 0;
  
  for x := 0 to 5 do
  begin
    sum := sum + nums[x];
  end;
  
  writeln('The sum of the array is: ', sum);
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln();
end.
