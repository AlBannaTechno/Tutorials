program fptutorial10;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var
  x: integer;
  y: integer;
  suit: array[0..3] of string;
  rank: array[0..12] of string;
  cards: array[0..3, 0..12] of string; { this is the multi-demensional array }

begin
  suit[0] := 'D'; {Diamonds}
  suit[1] := 'S'; {Spades}
  suit[2] := 'H'; {Hearts}
  suit[3] := 'C'; {Clubs}

  rank[0] := '2';
  rank[1] := '3';
  rank[2] := '4';
  rank[3] := '5';
  rank[4] := '6';
  rank[5] := '7';
  rank[6] := '8';
  rank[7] := '9';
  rank[8] := '10';
  rank[9] := 'Jack';
  rank[10] := 'Queen';
  rank[11] := 'King';
  rank[12] := 'Ace';

  for x := 0 to 3 do
  begin
    for y := 0 to 12 do
    begin
      cards[x, y] := suit[x] + rank[y];
    end;
  end;

  for x := 0 to 3 do
  begin
    for y := 0 to 12 do
    begin
      write(cards[x, y], ' ');
    end;
  end;

  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln();
end.
