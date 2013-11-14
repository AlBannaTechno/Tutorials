package simplechat;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;


/*
 * The Client that can be run both as a console or a GUI
 */
public class Client {
    /* For I/O */
    private ObjectInputStream sInput;
    private ObjectOutputStream sOutput;
    private Socket socket;

    /* Gui object */
    private ClientGUI cg;

    /* The server, port and username */
    private String server, username;
    private int port;

    /*
     *  Constructor called by console mode
     *  server: the server address
     *  port: the port number
     *  username: the username
     */
    public Client(String server, int port, String username) {
        this(server, port, username, null);
    }

    /*
     * Constructor call when used from a GUI
     * in console mode the ClienGUI parameter is null
     */
    public Client(String server, int port, String username, ClientGUI cg) {
        this.server = server;
        this.port = port;
        this.username = username;
        this.cg = cg;
    }

    /*
     * To start the dialog
     */
    public boolean start() {
        // Try to connect to the server
        try {
            socket = new Socket(server, port);
        }
        catch (Exception err) {
            display("Error connecting to server: " + err);
        }

        String msg = "Connection accepted " + socket.getInetAddress() + ":" + socket.getPort();
        display(msg);

        // Creating both data streams
        try {
            sInput = new ObjectInputStream(socket.getInputStream());
            sOutput = new ObjectOutputStream(socket.getOutputStream());
        }
        catch (IOException err) {
            display("Exception creating new Input/Output streams: " + err);
            return false;
        }

        // Creates the thread that listens for new messages from the server
        new ListenFromServer().start();
        // Send username to the server. This is the only message that is sent as a string, all other
        // messages are sent as ChatMessage objects
        try {
            sOutput.writeObject(username);
        }
        catch (IOException err) {
            display("Exception doing login: " + err);
            disconnect();
            return false;
        }

        // If everything worked correctly return true
        return true;
    }

    /*
     * To send a message to the console or the GUI
     */
    private void display(String msg) {
        if (cg == null)
            System.out.println(msg);
        else
            cg.append(msg + "\n");
    }

    /*
     * To send a message to the server
     */
    public void sendMessage(ChatMessage msg) {
        try {
            sOutput.writeObject(msg);
        }
        catch (IOException err) {
            display("Exception writing to server: " + err);
        }
    }

    /*
     * When something goes wrong
     * Close the Input/Output streams and disconnect not much to do in the catch clause
     */
    private void disconnect() {
        try {
            if (sInput != null)
                sInput.close();
        }
        catch (Exception err) {
            // Not much can be done
        }
        try {
            if (sOutput != null)
                sOutput.close();
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

        // Inform the gui
        if (cg != null)
            cg.connectionFailed();
    }

    /*
     * a class that waits for the message from the server and append them to the JTextArea
     * if we have a GUI or simply System.out.println() it in console mode
     */
    class ListenFromServer extends Thread {
        public void run() {
            while (true) {
                try {
                    String msg = (String) sInput.readObject();

                    if (cg == null) {
                        System.out.println(msg);
                        System.out.println("> ");
                    }
                    else
                        cg.append(msg);
                }
                catch (IOException err) {
                    display("Server has closed the connection: " + err);
                    if (cg != null)
                        cg.connectionFailed();
                    break;
                }
                catch (ClassNotFoundException err) {
                    // Not much can be done
                }
            }
        }
    }

    /*
     * To start the Client in console mode use one of the following command
     * > java Client
     * > java Client username
     * > java Client username portNumber
     * > java Client username portNumber serverAddress
     * at the console prompt
     * If the portNumber is not specified 1500 is used
     * If the serverAddress is not specified "localHost" is used
     * If the username is not specified "Anonymous" is used
     * > java Client
     * is equivalent to
     * > java Client Anonymous 1500 localhost
     * are eqquivalent
     *
     * In console mode, if an error occurs the program simply stops
     * when a GUI id used, the GUI is informed of the disconnection
     */
    public static void main(String[] args) {
        // Default values
        int portNumber = 1500;
        String serverAddress = "localhost";
        String userName = "Anonymous";

        // Depending on the number of arguments provided we fall through
        switch (args.length) {
            case 3:
                serverAddress = args[2];
            case 2:
                try {
                    portNumber = Integer.parseInt(args[1]);
                }
                catch (Exception err) {
                    System.out.println("Invalid port number.");
                    System.out.println(
                            "Usage is: > java client [username] [portNumber] [serverAddress]");
                    return;
                }
            case 1:
                userName = args[0];
            case 0:
                break;
            default:
                System.out.println(
                        "Usage is: > java client [username] [portNumber] [serverAddress]");
                return;
        }

        // Create the client object
        Client client = new Client(serverAddress, portNumber, userName);
        // Test if the connection to the server failed
        if (!client.start())
            return;

        // wait for messages from user
        Scanner scan = new Scanner(System.in);
        // loop forever for new message from the user
        while (true) {
            System.out.print("> ");
            // Read message from the user
            String msg = scan.nextLine();
            // Logout if message is LOGOUT
            if (msg.equalsIgnoreCase("LOGOUT")) {
                client.sendMessage(new ChatMessage(ChatMessage.LOGOUT, ""));
                break;
            }
            else if (msg.equalsIgnoreCase("WHOISIN"))
                client.sendMessage(new ChatMessage(ChatMessage.WHOISIN, ""));
            else
                client.sendMessage(new ChatMessage(ChatMessage.MESSAGE, msg));
        }

        // cleanly disconnect
        client.disconnect();
    }
}
