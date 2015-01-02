use common::{IPADDRESS, PORT};
use std::io::TcpStream;
use std::os;

mod common;

fn main() {
    // 'args' returns the arguments passed to the program
    let args = os::args();

    // First argument is the message to be sent
    let message = match args.as_slice() {
        [_, ref message] => message.as_slice(),
        _ => panic!("wrong number of arguments"),
    };

    // Connect to the server
    let mut socket = match TcpStream::connect((IPADDRESS, PORT)) {
        Ok(socket) => socket,
        Err(_) => panic!("server is not running"),
    };

    match socket.write_str(message) {
        Ok(_) => {},
        Err(_) => panic!("couldn't send message"),
    }
}
