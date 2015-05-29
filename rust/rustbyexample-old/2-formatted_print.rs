fn main() {
    // `{:?}` are placeholders for arguments that will be stringified.
    println!("{:?} days", 31);

    // Without a suffix, 31 becomes an i32. You can change what type 31 is, with a suffix, and that
    // is covered in the next chapter

    // The positional arguments can be reused along the template.
    println!("{0:?}, this is {1:?}. {1:?}, this is {0:?}", "Alice", "Bob");

    // Named arguments can also be used.
    println!("{subject:?} {verb:?} {predicate:?}",
             predicate="over the lazy dog",
             subject="The quick brown fox",
             verb="jumps");

    // Special formatting can be specified in the place of the `?`
    println!("{:?} of {:b} people know binary, the other half don't", 1, 2);

    // ERROR! Missing argument
    // println!("My name is {0:?}, {1:?} {0:?}", "Bond");
    println!("My name is {0:?}, {1:?} {0:?}", "Bond", "James");
}
