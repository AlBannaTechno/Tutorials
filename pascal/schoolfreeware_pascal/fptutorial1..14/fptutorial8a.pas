program fptutorial8a;

{$mode objfpc}{$H+}

uses
  sysutils,
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads;
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var
  sel: char;

begin
  write('Please select a key (A, B, C, D): ');
  readln(sel);

  writeln;

  case sel of
    'A', 'a': begin
               writeln('A was selected');
              end;

    'B', 'b': begin
               writeln('B was selected');
              end;

    'C', 'c': begin
               writeln('C was selected');
              end;

    'D', 'd': begin
               writeln('D was selected');
              end;
  end; { end of case }

  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end.
