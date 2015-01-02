// custom.rs
// Custom conditions can be defined, but must be supplied to the compiler ex:
// $ rustc --cfg some_condition custom.rs
#[cfg(some_condition)]
fn conditional_function() {
    println!("condition met!");
}

fn main() {
    conditional_function();
}
