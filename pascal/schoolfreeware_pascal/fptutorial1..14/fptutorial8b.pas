program fptutorial8b;
// Grade using if statements

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
  write('Enter score: ');
  readln(score);
  writeln;
  
  if score <= 59 then
  begin
    writeln('Grade F');
  end
  else if (score < 63) and (score >= 60) then
  begin
    writeln('Grade D-');
  end
  else if (score < 67) and (score >= 63) then
  begin
    writeln('Grade D');
  end
  else if (score < 70) and (score >= 67) then
  begin
    writeln('Grade D+');
  end
  else if (score < 73) and (score >= 70) then
  begin
    writeln('Grade C-');
  end
  else if (score < 77) and (score >= 73) then
  begin
    writeln('Grade C');
  end
  else if (score < 80) and (score >= 77) then
  begin
    writeln('Grade C+');
  end
  else if (score < 83) and (score >= 80) then
  begin
    writeln('Grade B-');
  end
  else if (score < 87) and (score >= 83) then
  begin
    writeln('Grade B');
  end
  else if (score < 90) and (score >= 87) then
  begin
    writeln('Grade B+');
  end
  else if (score < 93) and (score >= 90) then
  begin
    writeln('Grade A-');
  end
  else if (score < 97) and (score >= 93) then
  begin
    writeln('Grade A');
  end
  else
  begin
    writeln('Grade A+');
  end;
  
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end.
