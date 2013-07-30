program fptutorial13b;
{ records using with }

{$mode objfpc}{$H+}

uses
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
  employee: person;
  
procedure StopProgram;
begin
  writeln; writeln;
  writeln('Press <Enter> to Quit');
  readln;
end;

procedure LoadData;
begin
  with employee do
  begin
    fname := 'Joe';
    lname := 'Smith';
    gender := 'M';
    wage := 35000.00;
  end; {with}
end;

procedure PrintData;
begin
  with employee do
  begin
    writeln('Name: ', fname, ' ', lname);
    writeln('Gender: ', gender);
    writeln('Wage: $', wage:0:2);
  end; {with}
end;

begin
  LoadData;
  PrintData;
  StopProgram;
end.
