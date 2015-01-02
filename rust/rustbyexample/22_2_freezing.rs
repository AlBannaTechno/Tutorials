fn main() {
    let mut _integer = 5i;

    {
        // Borrow 'integer'
        let _ref_to_integer = &_integer;

        // ERROR! 'integer' is frozen in this scope
        // _integer = 4;

        // '_ref_to_integer' goes out of scope
    }

    // OK! 'integer' is not frozen in this scope
    _integer = 4;
}
