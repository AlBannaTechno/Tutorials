program fptutorial13d;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
type
  creature = record
    Name: string;
    Armor, Health, Magic, Power: integer;
  end;
  
var
  hero, JellBall: creature;
  
procedure LoadSettings;
begin
  with Hero do
  begin
    Name := 'Sir Bill';
    Armor := 0;
    Health := 10;
    Magic := 2;
    Power := 5;
  end;
  
  with JellBall do
  begin
    Name := 'JellBall';
    Armor := 0;
    Health := 1;
    Magic := 0;
    Power := 1;
  end;
end;

procedure PrintSettings;
begin
  with Hero do
  begin
    writeln('Name: ', Name);
    writeln('Armor: ', Armor);
    writeln('Health: ', Health);
    writeln('Magic: ', Magic);
  end;
  
  writeln; writeln;
  
  with JellBall do
  begin
    writeln('Name: ', Name);
    writeln('Armor: ', Armor);
    writeln('Health: ', Health);
    writeln('Magic: ', Magic);
  end;
end;

procedure StopProgram;
begin
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end;

begin
  LoadSettings;
  PrintSettings;
  StopProgram;
end.
