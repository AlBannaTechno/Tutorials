package simplechat;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;


/*
 * The server that can be run both as a console application or a GUI
 */
public class Server {
    /* A unique ID for each connection */
    private static int uniqueId;
    /* An ArrayList to keep the list of the clients */
    private ArrayList<ClientThread> al;
    /* If the program is a gui or cli */
    private ServerGUI sg;
    /* Used to display the time */
    private SimpleDateFormat sdf;
    /* The port number to listen for connections */
    private int port;
    /* The boolean that will be turned off to stop the server */
    private boolean keepGoing;

    /*
     *  server constructor that receive the port to listen to for connection as parameter
     *  in console
     */
    public Server(int port) {
        this(port, null);
    }

    public Server(int port, ServerGUI sg) {
        // Set the GUI for the server
        this.sg = sg;
        // Set the port
        this.port = port;
        // Setup date format
        sdf = new SimpleDateFormat("HH:mm:ss");
        // Initialize the client arraylist
        al = new ArrayList<ClientThread>();
    }

    public void start() {
        keepGoing = true;
        // Create the socket server and wait for connection requests
        try {
            ServerSocket serverSocket = new ServerSocket(port);

            // Infinite while loop waiting for connections
            while (keepGoing) {
                // Formatted message saying the server is waiting
                display("Server is waiting for Clients on port " + port + ".");

                Socket socket = serverSocket.accept();  // accept a new connection
                // If asked to stop
                if (!keepGoing)
                    break;

                ClientThread t = new ClientThread(socket);  // Make a thread with the connection
                al.add(t);  // Add the thread to the arraylist
                t.start();
            }

            // Cleanly close all connections and threads
            try {
                serverSocket.close();

                for (ClientThread ct : al) {
                    try {
                        ct.sInput.close();
                        ct.sOutput.close();
                        ct.socket.close();
                    }
                    catch (IOException err) {
                        // Not much can be done
                    }
                }
            }
            catch (Exception err) {
                display("Exception closing the server and clients: " + err);
            }
        }
        catch (Exception err) {
            String msg = sdf.format(new Date()) + " Exception on new ServerSocket: " + err + "\n";
            display(msg);
        }
    }

    /*
     * For the GUI to stop the server
     */
    protected void stop() {
        keepGoing = false;
        // Connect to self as a client and send the exit statement
        try {
            new Socket("localhost", port);
        }
        catch (Exception err) {
            // Not much can be done
        }
    }

    /*
     * Display an event (not a message) to the console or the GUI
     */
    private void display(String msg) {
        String time = sdf.format(new Date()) + " " + msg;

        if (sg == null)
            System.out.println(time);
        else
            sg.appendEvent(time + "\n");
    }

    /*
     *  to broadcast a message to all Clients
     */
    private synchronized void broadcast(String message) {
        // Add timestamp and newline to the message
        String time = sdf.format(new Date());
        String messageLf = time + " " + message + "\n";
        // Display message on console or gui
        if (sg == null)
            System.out.print(messageLf);
        else
            sg.appendRoom(messageLf);  // append in the room window

        // We loop in reverse order in case we would have to remove a client because it disconnected
        Collections.reverse(al);
        for (ClientThread ct : al) {
            if (!ct.writeMsg(messageLf)) {
                al.remove(ct);
                display("Disconnected client + " + ct.username + " removed from list.");
            }
        }
        Collections.reverse(al);
    }

    // for a client who logoff using the LOGOUT message
    synchronized void remove(int id) {
        // Scan the arraylist until we find the id
        for (ClientThread ct : al) {
            if (ct.id == id) {
                al.remove(ct);
                return;
            }
        }
    }

    /* One instance of this thread will run for each client */
    class ClientThread extends Thread {
        /* The socket to listen and talk to */
        Socket socket;
        ObjectInputStream sInput;
        ObjectOutputStream sOutput;
        /* The unique id, used for disconnecting */
        int id;
        /* The username of the client */
        String username;
        /* The message object */
        ChatMessage cm;
        /* The date the user connected */
        String date;

        // Constructor
        ClientThread(Socket socket) {
            // Unique id
            id = ++uniqueId;
            this.socket = socket;
            // Create both data streams
            System.out.println("Thread trying to create Object input and output streams");
            try {
                // Create output first
                sOutput = new ObjectOutputStream(socket.getOutputStream());
                sInput = new ObjectInputStream(socket.getInputStream());
                // Read the username
                username = (String) sInput.readObject();
                display(username + " just connected.");
            }
            catch (IOException err) {
                display("Exception created new input and output streams: " + err);
                return;
            }
            catch (ClassNotFoundException err) {
                // Have to catch this exception when a string is read, but not much can be done
            }

            date = new Date().toString() + "\n";
        }

        // Thread run statement
        @Override
        public void run() {
            // Loops until LOGOUT is recieved
            boolean keepGoing = true;

            while (keepGoing) {
                // Read a string (which is an object)
                try {
                    cm = (ChatMessage) sInput.readObject();
                }
                catch (IOException err) {
                    display(username + " exception reading streams: " + err);
                    break;
                }
                catch (ClassNotFoundException err) {
                    break;
                }

                // The message part of the ChatMessage
                String message = cm.getMessage();

                // Switch to detect the message type
                switch (cm.getType()) {
                    case ChatMessage.MESSAGE:
                        broadcast(username + ": " + message);
                        break;
                    case ChatMessage.LOGOUT:
                        display(username + " disconnected with a LOGOUT message.");
                        keepGoing = false;
                        break;
                    case ChatMessage.WHOISIN:
                        writeMsg("List of the users connected at " + sdf.format(new Date()) + "\n");
                        // scan all the users connected
                        int amount = 0;
                        for (ClientThread ct : al) {
                            ++amount;
                            writeMsg(amount + ") " + ct.username + " since " + ct.date);
                        }
                        break;
                }
            }

            // Remove client from arraylist when thread ends
            remove(id);
            close();
        }

        // Try to close everything
        private void close() {
            try {
                if (sOutput != null)
                    sOutput.close();
            }
            catch (Exception err) {
                // Not much can be done
            }
            try {
                if (sInput != null)
                    sInput.close();
            }
            catch (Exception err) {
                // Not much can be done
            }
            try {
                if (socket != null)
                    socket.close();
            }
            catch (Exception err) {
                // Not much can be done
            }
        }

        /*
         * Write a String to the Client output stream
         */
        private boolean writeMsg(String msg) {
            // if Client is still connected, send the message
            if (!socket.isConnected()) {
                close();
                return false;
            }

            // Write the message to the stream
            try {
                sOutput.writeObject(msg);
            }
            catch (IOException err) {
                display("Error sending message to " + username);
                display(err.toString());
            }

            return true;
        }
    }

    /*
     *  To run as a console application just open a console window and:
     * > java Server
     * > java Server portNumber
     * If the port number is not specified 1500 is used
     */
    public static void main(String[] args) {
        // Start the server on port 1500 unless PortNumber is specified
        int portNumber = 1500;

        switch (args.length) {
            case 1:
                try {
                    portNumber = Integer.parseInt(args[0]);
                }
                catch (Exception err) {
                    System.out.println("Invalid port number.");
                    System.out.println("Usage is: > java server [portNumber]");
                    return;
                }
            case 0:
                break;
            default:
                System.out.println("Usage is: > java server [portNumber]");
                return;
        }

        // Create a server object and start it
        Server server = new Server(portNumber);
        server.start();
    }
}
