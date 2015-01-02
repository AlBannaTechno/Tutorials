// A unit struct without resources
#[deriving(Show, Copy)]
struct Nil;

// A tuple struct with resources that implements the 'Clone' trait
#[deriving(Clone, Show)]
struct Pair(Box<int>, Box<int>);

fn main() {
    // Instantiate 'Nil'
    let nil = Nil;
    // Copy 'Nil', there are no resources to move
    let copied_nil = nil;

    // Boxs 'Nil's can be used independently
    println!("Original: {}", nil);
    println!("Copy: {}", copied_nil);

    // Instantiate a 'Pair'
    let pair = Pair(box 1, box 2);
    println!("Original: {}", pair);

    // Copy 'pair' into 'moved_pair', moves resources
    let moved_pair = pair;
    println!("Copy: {}", moved_pair);

    // ERROR! 'pair' has lost its resources
    // println!("Original: {}", pair);

    // "Clone" 'moved_pair' into 'cloned_pair' (resources included)
    let cloned_pair = moved_pair.clone();

    // 'Drop' the original pair
    drop(moved_pair);

    // ERROR! 'moved_pair' has beed 'drop'ed
    // println!("Copy: {}", moved_pair);

    // Clone can still be used
    println!("Clone: {}", cloned_pair);
}
