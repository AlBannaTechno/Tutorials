struct T;  // a null struct
struct GenericTup<T>(T,);

// impl of GenericTup we specifically specialize:
impl GenericTup<f32> {}  // specialize to 'f32'
impl GenericTup<T> {}  // specialize to 'T' defined above

// '<T>' must precede the type to remain generic
impl <T> GenericTup<T> {}

struct Tup (f64,);
struct GenTup<T>(T,);

// impl of Tup
impl Tup {
    fn value(&self) -> &f64 {
        let &Tup ( ref val ) = self;

        val
    }
}

// impl of GenTup for a generic type 'T'
impl <T> GenTup<T> {
    fn value(&self) -> &T {
        let &GenTup (ref val) = self;

        val
    }
}

fn main() {
    let x = Tup(3.0);
    let y = GenTup(3i32);

    println!("{}, {}", x.value(), y.value());
}
