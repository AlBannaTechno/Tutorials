proc getAlphabet(): string =
  result = ""
  for letter in 'a'..'z':
    result.add(letter)

proc unexpected(): int =
  var result = 5
  result += 5

echo getAlphabet()
echo unexpected()
