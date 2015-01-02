fn main() {
    struct Foo { x: (uint, uint), y: uint }

    // Destructure members of the struct
    let foo = Foo { x: (1, 2), y: 3 };
    let Foo { x: (a, b), y } = foo;

    println!("a = {}, b = {}, y = {}", a, b, y);

    // You can destructure structs and rename the variables, the order is not important

    let Foo { y: i, x: j } = foo;
    println!("i = {}, j = {}", i, j);

    // and you can also ignore some variables:
    let Foo { y, .. } = foo;
    println!("y = {}", y);

    // This will give an error: pattern does not mention field 'x'
    // let Foo { y } = foo
}
