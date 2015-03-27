// Re-implementation of integer division (/)
fn division(divident: i32, divisor: i32) -> i32 {
    if divisor == 0 {
        // Division by zero triggers panic
        panic!("division by zero");
    } else {
        divident / divisor
    }
}

// The `main` task
fn main() {
    // Heap allocated integer
    let _x = Box::new(0i32);

    // This operation will trigger a task failure
    division(3, 0);

    println!("This point won't be reached!");

    // `_x` should get destroyed at this point
}
