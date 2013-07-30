unit Unit1; 

{$mode delphi}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, Variants, DateUtils;

type

  { an interface definition }
  IRecyclable = Interface(IInterface)
    { a single function supporting the property }
    function GetIsRecyclable: Boolean;
    { a single property }
    property isRecyclable: Boolean read GetIsRecyclable;
  end;

  { define car class }
  TCar = class(TInterfacedObject, IRecyclable)
  private
    carName: String;
    carAge: Byte;
    carIsRecyclable: boolean;
    function GetIsRecyclable: Boolean; { added for IRecyclable}
  public
    { car propertyies }
    property name: String read carName;
    property Age: Byte read carAge write carAge;
    { added for IRecyclable }
    property isRecyclable: Boolean read GetIsRecyclable;
    { car constructor }
    constructor Create(name: String);
  end;

  { define bicycle class }
  TBicycle = class(TInterFacedObject, IRecyclable)
  private
    bikeIsMale: Boolean;
    bikeWheelSize: Byte;
    function GetIsRecyclable: Boolean; { added for IRecyclable }
  public
    { bicycles properties }
    property isMale: Boolean read bikeIsMale;
    property wheelSize: Byte read bikeWheelSize write bikeWheelSize;
    { added for IRecyclable }
    property isRecyclable: Boolean read GetIsRecyclable;
    { bicycle constructor }
    constructor Create(isMale: Boolean; wheelSize: Byte);
  end;

  { TForm1 }

  TForm1 = class(TForm)
    procedure FormCreate(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  Form1: TForm1; 

implementation

{$R *.lfm}

{ constructor implementation for the clar class }
constructor TCar.Create(name: String);
begin
  { save the car name and set default age and miles }
  carName := name;
  carAge := 0;
  carIsRecyclable := True; { sets the recyclable indicator }
end;

{ car function required for isRecyclable attribute }
function TCar.GetIsRecyclable: Boolean;
begin
  Result := carIsRecyclable;
end;

{ constructor implementation for the bicycle class }
constructor TBicycle.Create(isMale: Boolean; wheelSize: Byte);
begin
  { save the passed parameters }
  bikeIsMale := isMale;
  bikeWheelSize := wheelSize;
end;

{ bicycle function required for IsRecyclable attribute }
function TBicycle.GetIsRecyclable: Boolean;
begin
  { only make bicycles are recyclable }
  if self.isMale
  then Result := True
  else Result := false;
end;

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
var
  mumsBike: TBicycle;
  dadsCar: TCar;
begin
  { instantiate our bike and car objects }
  mumsBike := TBicycle.Create(False, 24);
  dadsCar := TCar.Create('Nissan Bluebird');

  { ask if each is recyclable }
  if dadsCar.isRecyclable
  then ShowMessage('Dads car is recyclable')
  else ShowMessage('Dads car is not recyclable');

  if mumsBike.isRecyclable
  then ShowMessage('Mums bike is recyclable')
  else ShowMessage('Mums bike is not recyclable');
end;

end.

