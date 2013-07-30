program FPTutorial4;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };

var
  name: string;
  address: string;
  birthdate: string;
  num1: real;
  num2: real;
  total: real;

begin
  writeln('Enter Name: ');
  readln(name);
  writeln('Enter Address: ');
  readln(address);
  writeln('Enter Birth Date: ');
  readln(birthdate);
  writeln('Enter First Number: ');
  readln(num1);
  writeln('Enter Second Number: ');
  readln(num2);
  total := num1 + num2;
  writeln;
  writeln('The sum of the Numbers is: ', total:0:2);
  writeln;
  writeln('Nice to Meet You, ', name);
  writeln('Address: ' + address + ' | Birthday: ' + birthdate);
  writeln;
  writeln;
  writeln('Press <Enter> to Quit');
  readln();
end.
