fn main() {
  print!("January has ");

  // {} work similar to how they do in C#
  println!("{} days", 31i);
  // i is a "signed pointer size integer"

  println!("{0}, this is {1}. {1}, this is {0}", "Alice", "Bob");

  // named arguments can be used
  println!("{subject} {verb} {predicate}",
           predicate="over the lazy dog",
           subject="the quick brown fox",
           verb="jumps");

  // and ofc special formatting
  println!("{} of {:b} people know binary, the other half don't", 1i, 2i);

  // println!("My name is {0}, {1} {0}", "Bond");
  println!("My name is {0}, {1} {0}", "Bond", "James");
}
