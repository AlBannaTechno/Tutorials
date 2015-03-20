use std::str;


fn main() {
    let string = "Hello there.";
    takes_slice(string);

    let mut s = "Hello".to_string();
    println!("{}", s);
    s.push_str(", world!");
    println!("{}", s);
    takes_slice(&*s);

    let x: &[u8] = &[b'a', b'b'];
    let stack_str: &str = str::from_utf8(x).unwrap();
}

fn takes_slice(slice: &str) {
    println!("Got: {}", slice);
}
