use common::{IPADDRESS, PORT};
use std::io::TcpListener;
use std::io::{Acceptor, Listener};

mod common;

fn main() {
    let listener = match TcpListener::bind((IPADDRESS, PORT)) {
        Ok(listener) => listener,
        Err(_) => panic!("couldn't start server"),
    };

    let mut acceptor = listener.listen();

    println!("Server started, waiting for clients");

    for mut client in acceptor.incoming() {
        match client.read_to_string().unwrap().as_slice() {
            "quit" => break,
            s => println!("Client said: {}", s),
        }
    }

    println!("Server shutting down");
}
