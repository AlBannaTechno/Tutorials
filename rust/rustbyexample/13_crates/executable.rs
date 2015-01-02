// executable.rs
// Link to 'liberty', import items under the 'erty' module
extern crate erty;

fn main() {
    erty::public_function();

    // ERROR! private
    // erty::private_function();

    erty::indirect_access();
}
