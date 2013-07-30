unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  ExtCtrls;

type

  { TFrmMain }

  TFrmMain = class(TForm)
    btnSubmit: TButton;
    btnClear: TButton;
    edFirst: TEdit;
    edSecond: TEdit;
    edAnswer: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    rBtnAdd: TRadioButton;
    rBtnSub: TRadioButton;
    rBtnMult: TRadioButton;
    rBtnDiv: TRadioButton;
    rgpOperator: TRadioGroup;
    procedure btnClearClick(Sender: TObject);
    procedure btnSubmitClick(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  FrmMain: TFrmMain;

implementation

{$R *.lfm}

{ TFrmMain }

procedure TFrmMain.btnSubmitClick(Sender: TObject);
begin
  try
    if rBtnAdd.Checked = True then
      edAnswer.Text := FloatToStr(StrToFloat(edFirst.Text) + StrToFloat(edSecond.Text))
    else if rBtnSub.Checked = True then
      edAnswer.Text := FloatToStr(StrToFloat(edFirst.Text) - StrToFloat(edSecond.Text))
    else if rBtnMult.Checked = True then
      edAnswer.Text := FloatToStr(StrToFloat(edFirst.Text) * StrToFloat(edSecond.Text))
    else if rBtnDiv.Checked = True then
      edAnswer.Text := FloatToStr(StrToFloat(edFirst.Text) / StrToFloat(edSecond.Text))
    else
      ShowMessage('Please Select an Operator');
  except
    on E: Exception do
      ShowMessage(E.Message + '. Please Check Your Numbers');
  end;
end;

procedure TFrmMain.btnClearClick(Sender: TObject);
begin
  edFirst.Clear;
  edSecond.Clear;
  edAnswer.Clear;
end;

end.

