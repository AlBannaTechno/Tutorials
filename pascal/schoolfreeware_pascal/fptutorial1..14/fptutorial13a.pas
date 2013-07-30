program fptutorial13a;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this};
  
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
  employee.fname := 'Joe';
  employee.lname := 'Smith';
  employee.gender := 'M';
  employee.wage := 35000.00;
end;

procedure PrintData;
begin
  writeln('Name: ', employee.fname, ' ', employee.lname);
  writeln('Gender: ', employee.gender);
  writeln('Wage: $', employee.wage:0:2);
end;

begin
  LoadData;
  PrintData;
  StopProgram;
end.
