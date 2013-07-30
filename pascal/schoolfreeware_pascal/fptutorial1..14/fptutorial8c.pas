program fptutorial8c;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
var 
  score: integer;
  
begin
  writeln('Enter A Score: ');
  readln(score);
  writeln;
  
  case score of
    0..59: begin
            writeln('Grade F');
           end;
    60..62: begin
             writeln('Grade D-');
            end;
    63..66: begin
             writeln('Grade D');
            end;
    67..69: begin
             writeln('Grade D+');
            end;
    70..72: begin
             writeln('Grade C-');
            end;
    73..76: begin
             writeln('Grade C');
            end;
    77..79: begin
             writeln('Grade C+');
            end;
    80..82: begin
             writeln('Grade B-');
            end;
    83..86: begin
             writeln('Grade B');
            end;
    87..89: begin
             writeln('Grade B+');
            end;
    90..92: begin
             writeln('Grade A-');
            end;
    93..96: begin
             writeln('Grade A');
            end;
    else
      writeln('Grade A+');
    end; { ends the case }
    
    writeln; writeln;
    writeln('Press <Enter> to Quit');
    readln;
end.
