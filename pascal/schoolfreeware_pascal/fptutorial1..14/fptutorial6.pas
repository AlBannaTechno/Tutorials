program FPTutorial6;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var
  x: integer;

begin
  x := 1;  { starts x equal to 1 }

  { while loop example }
  while x <= 10 do
  begin
    writeln(x, ' * 2 = ', x * 2);
    x := x + 1;
  end;  { ends while loop }

  writeln;
  x := 1;

  { repeat loop example }
  repeat
    writeln(x, ' * 2 = ', x * 2);
    x := x + 1;
  until x > 10; { ends repeat loop }

  writeln;

  { for loop example }
  for x := 1 to 10 do  { to go backwards: for x := 10 downto 1 do }
  begin
    writeln(x, ' * 2 = ', x * 2);
  end;  { ends for loop }

  writeln;
  writeln;
  writeln('Press <Enter> to Quit.');
  readln();

end.
