program FPTutorial7;

{$mode objfpc}{$H+}

uses
  crt, sysutils,
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var
  answer, guess, cnt: integer;
  game: string;

begin
  repeat
    repeat
      clrscr(); { Clears the screen, needs crt }
      writeln('Please Select a Game: ');
      writeln;
      writeln('A) 10 ');
      writeln('B) 100 ');
      writeln('C) 1000 ');
      writeln;
      write('Selection: ');
      readln(game);
      game := UpperCase(game);  { Converts to uppercase, needs sysutils }
      randomize;  { Needed to get random numbers }
    until (game = 'A') or (game = 'B') or (game = 'C');  { checks for a correct response }
    
    clrscr();
    
    if game = 'A' then
    begin
      answer := random(10) + 1;  { random(10) gets 0 - 9, so add one for 1 - 10 }
      writeln('Game 1 - 10');
    end
    else if game = 'B' then
    begin
      answer := random(100) + 1;
      writeln('Game 1 - 100');
    end
    else if game = 'C' then
    begin
      answer := random(1000) + 1;
      writeln('Game 1 - 1000');
    end;  { end of game statement }
    
    cnt := 0;  { set the counter to zero }
    
    repeat
      write('Please Enter a Guess: ');
      readln(guess);
      cnt := cnt + 1;
      
      if guess < answer then
        writeln('Too Low!')
      else if guess > answer then 
        writeln('Too High!')
      else
        writeln('You guessed my number in ', cnt, ' guesses!');
        
    until guess = answer;  { repeat until the computer's number is guessed }
    
    repeat
      writeln;
      write('Play Again Y/N: ');
      readln(game);
      game := UpperCase(game);  { convert to uppercase }
    until (game = 'Y') or (game = 'N');  { repeat until the response is correct }
    
  until game = 'N';  { repeat until the user selects N to quit the game }
  
end.
