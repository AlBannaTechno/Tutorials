fn function() {
    println!("called `function()`");
}

mod my {
    #[allow(dead_code)]
    fn function() {
        println!("called `my::function()`");
    }

    mod nested {
        #[allow(dead_code)]
        fn function() {
            println!("called `my::nested::function()");
        }
    }
}

fn main() {
    function();

    // Items inside a module can be called using their full path
    // The 'println' function lives in the 'stdio' module
    // The 'stdio' module lives in the 'io' module
    // And the 'io' module lives in the 'std' create
    std::io::stdio::println("Hello, world!");

    // ERROR! 'my::function()' is private
    // my::function();
}
