program fptutorial14;
{ rpg game to show off record use }

{$mode objfpc}{$H+}

uses
  crt, sysutils,
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

type
  creature = record
    name: string;
    armor, health, magic, power: integer;
  end;

var
  hero, jellball, smallspider, largespider, opponent: creature;
  enemNum: integer; { used to select the opponent monster }
  selection: string; { used for user input }
  score: integer; { keeps score }

procedure LoadSettings;
begin
  score := 0;

  with hero do
  begin
    name := 'Sir Bill';
    armor := 0;
    health := 10;
    magic := 2;
    power := 5;
  end;

  with jellball do
  begin
    name := 'JellBall';
    armor := 0;
    health := 1;
    magic := 0;
    power := 1;
  end;

  with smallspider do
  begin
    name := 'Small Spider';
    armor := 0;
    health := 1;
    magic := 0;
    power := 2;
  end;

  with largespider do
  begin
    name := 'Large Spider';
    armor := 0;
    health := 2;
    magic := 0;
    power := 2;
  end;
end;

procedure GetEnemy;
begin
  randomize;
  enemNum := random(3) + 1;

  if enemNum = 1 then
    opponent := jellball
  else if enemNum = 2 then
    opponent := smallspider
  else
    opponent := largespider;
end;

procedure WriteStats;
begin
  with hero do
  begin
    writeln(name, '  Score = ', score);
    writeln('Health: ', health);
    writeln('Armor: ', armor);
    writeln('Magic: ', magic);
    writeln('Power: ', power);
  end;

  writeln; writeln;

  with opponent do
  begin
    writeln('Opponent: ', name);
    writeln('Health: ', health);
    writeln('Armor: ', armor);
    writeln('Magic: ', magic);
    writeln('Power: ', power);
  end;
end;

procedure Menu;
begin
  repeat
    writeln;
    writeln('(F)ight');
    writeln('(M)agic');
    write('Selection: ');
    readln(selection);
    selection := UpperCase(selection);
    randomize;

    if selection = 'F' then
    begin
      hero.health := hero.health - random(opponent.power + 1);
      opponent.health := opponent.health - random(hero.power + 1);
    end
    else if (selection = 'M') and (hero.magic > 0) then
    begin
      opponent.health := opponent.health - 10;
      hero.magic := hero.magic - 1;
      if opponent.health > 0 then
        hero.health := hero.health - random(opponent.power + 1);
    end;
  until (selection = 'F') or (selection = 'M');
end;

procedure Battle;
begin
  GetEnemy;

  repeat
    clrscr();
    WriteStats;
    Menu;
  until (hero.health <= 0) or (opponent.health <= 0);

  if opponent.health <= 0 then
  begin
    writeln(opponent.name, ' was killed!');
    score := score + opponent.power;
    sleep(1000);
  end;
end;

begin { main statement }
  repeat
    LoadSettings;

    repeat
      Battle;
    until hero.health <= 0;

    clrscr();
    writeln(Hero.name, ' was killed');
    writeln('Final Score: ', score);

    repeat
      write('Play Again Y/N: ');
      readln(selection);
      selection := UpperCase(selection);
    until (selection = 'Y') or (selection = 'N');
  until selection = 'N';
end.
