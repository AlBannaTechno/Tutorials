package simplechat;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;


public class ClientGUI extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    /* Will first hold "Username: ", ;ater on "Enter Message" */
    private JLabel label;
    /* Will hold the username, later on the messages */
    private JTextField tf;
    /* Will hold the server address and the port number */
    private JTextField tfServer, tfPort;
    /* Login, logout, and list of users buttons */
    private JButton login, logout, whoIsIn;
    /* Used for the chat room */
    private JTextArea ta;
    /* Connection boolean */
    private boolean connected;
    /* The client object */
    private Client client;
    /* The default port number and host */
    private int defaultPort;
    private String defaultHost;

    // Constructor connection receiving a socket number
    public ClientGUI(String host, int port) {
        super("Chat Client");
        defaultPort = port;
        defaultHost = host;

        // The northpanel
        JPanel northPanel = new JPanel(new GridLayout(3, 1));
        // The server name and port number
        JPanel serverAndPort = new JPanel(new GridLayout(1, 5, 1, 3));
        // The two JTextFields with default values for address and port
        tfServer = new JTextField(host);
        tfPort = new JTextField("" + port);
        tfPort.setHorizontalAlignment(SwingConstants.RIGHT);

        serverAndPort.add(new JLabel("Server Address: "));
        serverAndPort.add(tfServer);
        serverAndPort.add(new JLabel("Port Number: "));
        serverAndPort.add(tfPort);
        serverAndPort.add(new JLabel(""));
        // Adds the server and port field to the GUI
        northPanel.add(serverAndPort);

        // The label and text field
        label = new JLabel("Enter your username below", SwingConstants.CENTER);
        northPanel.add(label);
        tf = new JTextField("Anonymous");
        tf.setBackground(Color.WHITE);
        northPanel.add(tf);
        add(northPanel, BorderLayout.NORTH);

        // The centerpanel which is the chat room
        ta = new JTextArea("Welcome to the chat room\n", 80, 80);
        JPanel centerPanel = new JPanel(new GridLayout(1, 1));
        centerPanel.add(new JScrollPane(ta));
        ta.setEditable(false);
        add(centerPanel, BorderLayout.CENTER);

        // The 3 buttons
        login = new JButton("Login");
        login.addActionListener(this);
        logout = new JButton("Logout");
        logout.addActionListener(this);
        logout.setEnabled(false);
        whoIsIn = new JButton("Who is in");
        whoIsIn.addActionListener(this);
        whoIsIn.setEnabled(false);

        JPanel southPanel = new JPanel();
        southPanel.add(login);
        southPanel.add(logout);
        southPanel.add(whoIsIn);
        add(southPanel, BorderLayout.SOUTH);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(600, 600);
        setVisible(true);
        tf.requestFocus();
    }

    // Called by the client to append text in the text area
    public void append(String str) {
        ta.append(str);
        ta.setCaretPosition(ta.getText().length() - 1);
    }

    // Called by the gui when a connection has failed
    public void connectionFailed() {
        login.setEnabled(true);
        logout.setEnabled(false);
        whoIsIn.setEnabled(false);
        label.setText("Enter your username below");
        tf.setText("Anonymous");
        // reset port number and host name to defaults
        tfPort.setText("" + defaultPort);
        tfServer.setText(defaultHost);
        // Let the user change them
        tfServer.setEditable(true);
        tfPort.setEditable(true);
        // don't react to a cr after the username
        tf.removeActionListener(this);
        connected = false;
    }

    /*
    * Button or JTextField clicked
    */
    @Override
    public void actionPerformed(ActionEvent event) {
        Object o = event.getSource();

        // if it's the login button
        if (o == login) {
            String username = tf.getText().trim();
            if (username.length() == 0)
                return;

            String server = tfServer.getText().trim();
            if (server.length() == 0)
                return;

            String portNumber = tfPort.getText().trim();
            if (portNumber.length() == 0)
                return;

            int port = 0;
            try {
                port = Integer.parseInt(portNumber);
            }
            catch (Exception err) {
                return;  // Nothing much can be done
            }

            // TRy created a new Client with the GUI
            client = new Client(server, port, username, this);
            if (!client.start())
                return;

            tf.setText("");
            label.setText("Enter your message below");
            connected = true;

            login.setEnabled(false);
            logout.setEnabled(true);
            whoIsIn.setEnabled(true);
            tfServer.setEditable(false);
            tfPort.setEditable(false);
            tf.addActionListener(this);
        }

        // if it's the logout button
        if (o == logout) {
            client.sendMessage(new ChatMessage(ChatMessage.LOGOUT, ""));
            return;
        }

        // If it's the WhoIsIn button
        if (o == whoIsIn) {
            client.sendMessage(new ChatMessage(ChatMessage.WHOISIN, ""));
            return;
        }

        // it's coming from the JTextField
        if (connected) {
            client.sendMessage(new ChatMessage(ChatMessage.MESSAGE, tf.getText()));
            tf.setText("");
            return;
        }
    }

    public static void main(String[] args) {
        new ClientGUI("localhost", 1500);
    }
}
