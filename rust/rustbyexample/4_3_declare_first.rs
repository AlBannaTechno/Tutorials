fn main() {
  let a_variable;

  {
    let x = 2i;
    a_variable = x * x;
  }

  println!("a variable: {}", a_variable);

  let another_variable;

  // ERROR!
  // println!("another variable: {}", another_variable);

  another_variable = 1i;
  println!("another variable: {}", another_variable);
}
