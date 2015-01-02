// Generic tuplestruct with same types in both generic <A> and definition (A,)
struct Tuple<A>(A,);

// This tuple is a phantom type. B is a hidden parameter. Storage is allocated for generic type A
// yet not for B. Therefore, B cannot be used in computations.
#[deriving(PartialEq)]  // Allow equality test for this type
struct PhantomTuple<A, B>(A,);

// Similarly, a phantom type struct which is generic over A with hidden parameter B
#[deriving(PartialEq)]
struct PhantomStruct<A, B> { first: A }

fn main() {
    // instantiate tuple
    let _tuple: Tuple<char> = Tuple('R');

    // We can create similar types without carrying around extra info
    // PhantomTuple specialize to <char, f32>
    let _tuple1: PhantomTuple<char, f32> = PhantomTuple('Q');
    // PhantomTuple specialized to <char, f64>
    let _tuple2: PhantomTuple<char, f64> = PhantomTuple('Q');

    // ERROR: type mismatch so these cannot be compared
    // println!("_tuple1 == _tuple2 yields: {}",
    //          _tuple1 == tuple2);

    // Specialized to <char, f32>
    let _struct1: PhantomStruct<char, f32> = PhantomStruct { first: 'Q' };
    let _struct2: PhantomStruct<char, f64> = PhantomStruct { first: 'Q' };

    // ERROR: type mismatch so these cannot be compared
    // println!("_struct1 == struct2 yields: {}",
    //          _struct1 == _struct2);
}
