// Tuples can be used as function arguments and as return values
fn reverse(pair: (int, bool)) -> (bool, int) {
    // 'let' can be used to bind the members of a tuple to variables (destructuring fts!)
    let (integer, boolean) = pair;

    (boolean, integer)
}

fn reverse2<T1, T2>(pair: (T1, T2)) -> (T2, T1) {
    let (a, b) = pair;
    (b, a)
}

fn main() {
    // A tuple with a bunch of different types
    let long_tuple = (1u8, 2u16, 3u32, 4u64,
                      -1i8, -2i16, -3i32, -4i64,
                      0.1f32, 0.2f64,
                      'a', true);

    // Values can be extracted from the tuple using the '.N' syntax
    println!("long tuple first value: {}", long_tuple.1);
    println!("long tuple second value: {}", long_tuple.2);

    // Tuples can be tuple members
    let tuple_of_tuples = ((1u8, 2u16, 3u32), (4u64, -1i8), -2i16);

    // Tuples are printable
    println!("tuple of tuples: {}", tuple_of_tuples);

    let pair = (1, true);
    println!("pair is {}", pair);
    println!("the reversed pair is: {}", reverse(pair));

    // Generics! Victory!
    let pair2: (int, bool) = (1, true);
    println!("pair2 is {}", pair2);
    println!("the reversed pair2 is {}", reverse2(pair2));

    // To create one element tuples, the comma is required to tell them apart from a literal
    // surrounded by parentheses
    println!("one element tuple: {}", (5u,));
    println!("just an integer: {}", (5u));
}
