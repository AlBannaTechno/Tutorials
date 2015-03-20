use std::cmp::Ordering;
use std::io;
use StringResult::StringOk;
use StringResult::ErrorReason;

enum StringResult {
    StringOk(String),
    ErrorReason(String),
}

struct Point {
    x: i32,
    y: i32,
}

#[allow(dead_code)]
struct Color {
    red: i32,
    blue: i32,
    green: i32,
}

struct Inches(i32);


#[allow(unstable)]
#[allow(unused_variables)]
fn main() {
    hello("Nick");

    let x = (1, 2, 3);
    let y = (2, 2, 4);

    if x == y {
        println!("Yes");
    } else {
        println!("No");
    }

    let (x, y) = next_two(5);
    println!("x, y = {}, {}", x, y);

    let origin = Point { x: 0, y: 0 };
    println!("The origin is at {}, {}", origin.x, origin.y);

    let mut point = Point { x: 0, y: 0 };
    point.x = 5;
    println!("The point is at ({}, {})", point.x, point.y);

    let black = Color { red: 0, blue: 0, green: 0 };
    println!("Black: {}", black.red);

    let length = Inches(10);
    let Inches(integer_length) = length;
    println!("length is {} inches", integer_length);

    let a = 5;
    let b = 10;

    let ordering = cmp(a, b);

    if ordering == Ordering::Less {
        println!("Less");
    } else if ordering == Ordering::Greater {
        println!("Greater");
    } else if ordering == Ordering::Equal {
        println!("Equal");
    }

    match cmp(a, b) {
        Ordering::Less => println!("Less"),
        Ordering::Greater => println!("Greater"),
        Ordering::Equal => println!("Equal"),
    }

    println!("{}", match respond("Hello") {
        StringOk(msg) => msg,
        _ => "Not today.".to_string(),
    });

    let d = 5;
    println!("{}", match d {
        1 => "One",
        2 => "Two",
        3 => "Three",
        4 => "Four",
        5 => "Five",
        _ => "Something else",
    });

    for x in 0..10 {
        print!("{}", x);
    }
    println!("");

    let mut j = 5;
    let mut done = false;

    while !done {
        j += j - 3;
        println!("{}", j);
        if j % 5 == 0 { done = true; }
    }

    j = 5;
    loop {
        j += j - 3;
        println!("{}", j);
        if j % 5 == 0 { break; }
    }

    for x in 0u32..10 {
        if x % 2 == 0 { continue; }
        println!("{}", x);
    }

    let mut s = "Hello".to_string();
    println!("{}", s);
    s.push_str(", world.");
    println!("{}", s);

    takes_slice(s.as_slice());
    compare("Hello".to_string());

    let m = [1, 2, 3];
    let mut n = [1, 2, 3];
    let o: [i32; 20] = [0; 20];

    println!("m has {} elements", m.len());
    for val in m.iter() {
        println!("{}", val);
    }

    let names = ["Graydon", "Brian", "Niko"];
    println!("The second name is: {}", names[1]);

    let v = vec![1, 2, 3];  // x: Vec<i32>
    let mut nums = vec![1, 2, 3];

    nums.push(4);
    println!("The length of nums is now {}", nums.len());

    let v2 = [0, 1, 2, 3, 4];
    let middle = &v2[1..4]; // inclusive to exclusive

    for val in middle.iter() {
        println!("{}", val);
    }

    println!("Type something!");
    let input = io::stdin()
                  .read_line()
                  .ok()
                  .expect("failed to read line");
    println!("{}", input);
}

fn cmp(a: i32, b: i32) -> Ordering {
    if a < b { Ordering::Less }
    else if a > b { Ordering::Greater }
    else { Ordering::Equal }
}

fn next_two(x: i32) -> (i32, i32) { (x + 1, x + 2) }

/// `hello` is a function that prints a greeting that is personalized based on the name given.
///
/// # Arguments
///
/// * `name` - The name of the person you'd like to greet.
///
/// # Example
///
/// ```rust
/// let name = "Steve";
/// hello(name); // prints "Hello, Steve!"
/// ```
fn hello(name: &str) {
    println!("Hello, {}", name);
}

#[allow(unstable)]
fn respond(greeting: &str) -> StringResult {
    if greeting == "Hello" {
        StringOk("Good morning!".to_string())
    } else {
        ErrorReason("I don't understand you!".to_string())
    }
}

fn takes_slice(slice: &str) {
    println!("Got: {}", slice);
}

// always compare as a &str over String, as String requires allocating memory!
#[allow(unstable)]
fn compare(string: String) {
    if string.as_slice() == "Hello" {
        println!("Yes");
    }
}
