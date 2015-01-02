static LANGUAGE: &'static str = "Rust";
static THREASHOLD: int = 10;

fn is_big(n: int) -> bool {
    // Access constant in some function
    n > THREASHOLD
}

fn main() {
    let n = 16;

    // Access constant in the main task
    println!("This is {}", LANGUAGE);
    println!("The threashold is {}", THREASHOLD);
    println!("{} is {}", n, if is_big(n) { "big" } else { "small" });

    // ERROR! Cannot modify a static item
    // THREASHOLD = 5;

    {
        // String literals are references to read-only memory
        let _static_string: &'static str = "In read-only memory";

        // When '_static_string' goes out of scope, we can no longer refer to the underlying data,
        // but the string remains in read-only memory
    }
}
