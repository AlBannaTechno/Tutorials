package simplechat;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class ServerGUI extends JFrame implements ActionListener, WindowListener {
    private static final long serialVersionUID = 1l;
    /* Stop and start buttons */
    private JButton stopStart;
    /* JTextArea for the chat room and the events */
    private JTextArea chat, event;
    /* The port number */
    private JTextField tPortNumber;
    /* The server object */
    private Server server;

    // Server constructor that recieves the port to listen to for a connection as a parameter
    public ServerGUI(int port) {
        super("Chat Server");
        server = null;
        // In the NorthPanel the PortNumber the Start and Stop buttons
        JPanel north = new JPanel();
        north.add(new JLabel("Port number: "));
        tPortNumber = new JTextField(" " + port);
        north.add(tPortNumber);
        // To stop or start the server, we start with "Start"
        stopStart = new JButton("Start");
        stopStart.addActionListener(this);
        north.add(stopStart);
        add(north, BorderLayout.NORTH);

        // The event and chat room
        JPanel center = new JPanel(new GridLayout(2, 1));
        chat = new JTextArea(80, 80);
        chat.setEditable(false);
        appendRoom("Chat room.\n");
        center.add(new JScrollPane(chat));
        event = new JTextArea(80, 80);
        event.setEditable(false);
        appendEvent("Events log.\n");
        center.add(new JScrollPane(event));
        add(center);

        // Need to be informed when the user click the close button of the frame
        addWindowListener(this);
        setSize(400, 600);
        setVisible(true);
    }

    // append message to the two JTextArea
    // position at the end
    public void appendRoom(String str) {
        chat.append(str);
        chat.setCaretPosition(chat.getText().length() - 1);
    }

    public void appendEvent(String str) {
        event.append(str);
        event.setCaretPosition(chat.getText().length() - 1);
    }

    // Start or stop where clicked
    @Override
    public void actionPerformed(ActionEvent event) {
        // If running we have to stop
        if (server != null) {
            server.stop();
            server = null;
            tPortNumber.setEditable(true);
            stopStart.setText("Start");
            return;
        }

        // Start server otherwise
        int port;
        try {
            port = Integer.parseInt(tPortNumber.getText().trim());
        }
        catch (Exception err) {
            appendEvent("Invalid port number");
            return;
        }

        // Create a new server
        server = new Server(port, this);
        // Start the server thread
        new ServerRunning().start();
        stopStart.setText("Stop");
        tPortNumber.setEditable(false);
    }

    /*
     * If the user click the X button to close the application
     * I need to close the connection with the server to free the port
     */
    @Override
    public void windowClosing(WindowEvent event) {
        // If the server exists
        if (server != null) {
            try {
                server.stop();
            }
            catch (Exception err) {
                // Not much can be done
            }

            server = null;
        }

        // Dispose of the gui
        dispose();
        System.exit(0);
    }

    // Ignore the other required WindowListener methods
    public void windowClosed(WindowEvent event) {}
    public void windowOpened(WindowEvent event) {}
    public void windowIconified(WindowEvent event) {}
    public void windowDeiconified(WindowEvent event) {}
    public void windowActivated(WindowEvent event) {}
    public void windowDeactivated(WindowEvent event) {}

    /*
     * A thread to run the Server
     */
    class ServerRunning extends Thread {
        public void run() {
            server.start();
            // The above won't return unless something goes wrong or is stopped
            stopStart.setText("Start");
            tPortNumber.setEditable(true);
            appendEvent("Server crashed\n");
            server = null;
        }
    }

    // Entry point to start the server
    public static void main(String[] args) {
        // Start a server on the default port
        new ServerGUI(1500);
    }
}
