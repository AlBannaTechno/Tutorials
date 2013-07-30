program fptutorial13c;

{$mode objfpc}{$H+}

uses
  crt,
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  
type
  person = record
    fname, lname: string;
    gender: char;
    wage: real;
  end;
  
var
  employee: array[0..2] of person;
  
procedure StopProgram;
begin
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end;

procedure EnterData;
var
  x: integer;
begin
  for x := 0 to 2 do
  begin
    with employee[x] do
    begin
      clrscr();
      writeln('Employee Number: ', x + 1);
      writeln; writeln;
      write('Enter First Name: ');
      readln(fname);
      write('Enter Last Name: ');
      readln(lname);
      write('Enter Gender M/F: ');
      readln(gender);
      write('Enter Wage: $');
      readln(wage);
      writeln;
    end; {with}
  end; {for}
end; {procedure}

procedure PrintData;
var
  x: integer;
begin
  for x := 0 to 2 do
  begin
    with employee[x] do
    begin
      writeln('Employee Number: ', x + 1);
      writeln('First Name: ', fname);
      writeln('Last Name: ', lname);
      writeln('Gender: ', gender);
      writeln('Wage: $', wage:0:2);
      writeln;
    end; {with}
  end; {for}
end; {procedure}

begin
  EnterData;
  clrscr();
  PrintData;
  StopProgram;
end.
