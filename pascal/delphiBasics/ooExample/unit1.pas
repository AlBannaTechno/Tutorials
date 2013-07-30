unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs; 

type

  TStringy = class
    { These variables and methods are not visible outside this class. They are purely used in the
      implementation below. Note that variables are all prefixed by 'st'. This allows us, for
      example to use 'WordCount' as a property name - properties cannot use the same name as a
      variable.  }
  private
    stText: String;  { the string passed to the constructor }
    stWordCount: Integer;  { internal count of words in the string }
    stFindString: String;  { the substring used by FindFirst, FindNext }
    stFindPosition: Integer;  { FindFirst/FindNext current position }

    procedure GetWordCount;  { calculates the word count }
    procedure SetText(const VALUE: String);  { changes the text string }
  { these methods and properties are all usable by instances of the class }
  public
    { Called when creating an instance (object) from this class. The passed string is the one that
      is operated on by the methods below.  }
    constructor Create(Text: String);

    { Utility to replace all occurences of a substring in the string. The number if replacements is
      returned. This utility is !CASE SENSITIVE!  }
    function Replace(fromStr, toStr: String): Integer;

    { Utility to find the first occurences of a substring in the string. The number of replacements
      is required. This utility is !CASE SENSITIVE!  }
    function FindFirst(search: String): Integer;

    { Utility to find the next occurence of the FindFirst substring. If not found, -1 is returned.
      If no FindFirst performed before this call, -2 is returned. This utility is !CASE SENSITIVE! }
    function FindNext: Integer;

    { The string itself - allow it to be read and overwritten }
    property Text: String read stText write SetText;

    { The number of words in the documet. Words are groups of character separated by blanks, tabs,
      carriage returns and line feeds  }
    property WorldCount: Integer read stWordCount
  end;

  TForm1 = class(TForm)
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  Form1: TForm1; 

implementation

{$R *.lfm}

constructor TStringy.Create(nText: String);
begin
  slText := nText;  { Save the passed string }
  slFindPosition := 1;  { Start a search at the string start }
  slFindString := '';  { No find string provided yet }
  GetWordCount;  { Cal; a subroutine to get the word count }
end;

procedure TStringy.SetText(const VALUE: String);
begin
  slText := VALUE;  { Save the passed string }
  stFindPosition := 1;  { Reposition the find mechanism to the start }
  GetWordCount;  { Recalculate the word count }
end;

procedure TStringy.GetWordCount;
const
  { define word separator types that we will recognize }
  LF = #10;
  TAB = #9;
  CR = #13;
  BLANK = #32;
var
  WordSeparatorSet: Set of Char;  { We will set only the above characters }
  index: Integer;  { Used to scan along the string }
  inWord: Boolean;  { Indicates whether we are in the middle of a word }
begin
  { Turn on the TAB, CR, LF and BLANK characters in our word separator set }
  WordSeparatorSet := [LF, TAB, CR, BLANK];

  { Start with 0 words }
  stWordCount := 0;

  { Scan the string character by character looking for word separators }
  inWord := False;

  for index := 1 to Length(stText) do
  begin
    { Have we found a separator character? }
    if stText[index] in WordSeparatorSet then
    begin
      { Separator found - have we moved from a word? }
      if inWord then Inc(stWordCount);  { Yes - we have ended another word }
      { Indicate that we are not in a word anymore }
      inWord := False;
    end;
    else
      { Separator not found - we are in a world }
      inWord := False;
  end;

  { Finally, were we still in a word at the end of the string? If so, we must add one to the word
    count since we did not meet a separator character;  }
  if inWord then Inc(stWordCount);
end;

end.

