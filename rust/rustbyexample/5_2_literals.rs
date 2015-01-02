fn main() {
  let x = 1u8;
  let y = 2u;
  let z = 3f32;

  let i = 1;
  let f = 1.0;

  println!("size of `x` in bytes: {}", std::mem::size_of_val(&x));
  println!("size of `y` in bytes: {}", std::mem::size_of_val(&y));
  println!("size of `z` in bytes: {}", std::mem::size_of_val(&z));
  println!("size of `i` in bytes: {}", std::mem::size_of_val(&i));
  println!("size of `f` in bytes: {}", std::mem::size_of_val(&f));

  // Commenting out these lines will cause a compiler error as it doesn't know what their types are
  let _constraint_i = x + i;
  let _constraint_f = z + f;
}
