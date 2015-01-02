struct Foo;
struct Bar;

#[deriving(Show)]
struct FooBar;

#[deriving(Show)]
struct BarFoo;

// The 'Add<T, U>' trait needs two generic parameters:
// * T is the type of the RHS summand, and
// * U is the type of the sum
// This block implements teh operation: Foo + Bar = FooBar
impl Add<Bar, FooBar> for Foo {
    fn add(self, _rhs: Bar) -> FooBar {
        println!("> Foo.add(bar) was called");

        FooBar
    }
}

// Addition can be implemented in a non-communative way
// This block implements the operation: Bar + Foo = BarFoo
impl Add<Foo, BarFoo> for Bar {
    fn add(self, _rhs: Foo) -> BarFoo {
        println!("> Bar.add(Foo) was called");

        BarFoo
    }
}

fn main() {
    println!("Foo + Bar = {}", Foo + Bar);
    println!("Bar + Foo = {}", Bar + Foo);
}
