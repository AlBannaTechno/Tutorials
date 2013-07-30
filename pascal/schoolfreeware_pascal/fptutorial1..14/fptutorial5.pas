program FPTutorial5;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this};

var
  num1: integer;
  num2: integer;

begin
  write('Enter First Number: ');
  readln(num1);
  write('Enter Second Number: ');
  readln(num2);
  writeln;

  if num1 > num2 then
  begin
    writeln(num1, ' is greater than ', num2);
  end { num 1 > num 2 }
  else if num1 < num2 then
  begin
    writeln(num1, ' is less than ', num2);
  end (* num1 < num2 *)
  else
  begin
    writeln('The numbers are the same');
  end; // else
  writeln;
  writeln;
  writeln('Press <Enter> to Quit');
  readln();
end.
