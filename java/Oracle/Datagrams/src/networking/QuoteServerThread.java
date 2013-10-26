package networking;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;


public class QuoteServerThread extends Thread {
    protected DatagramSocket socket = null;
    protected BufferedReader in = null;
    protected boolean moreQuotes = true;

    public QuoteServerThread() throws IOException {
        this("Quote Server Thread");
    }

    public QuoteServerThread(String name) throws IOException {
        super(name);
        socket = new DatagramSocket(4445);

        try {
            in = new BufferedReader(new FileReader("one-liners.txt"));
        }
        catch (FileNotFoundException err) {
            System.err.println("Could not open quote file. Serving time instead.");
        }
    }

    @Override
    public void run() {
        while (moreQuotes) {
            try {
                byte[] buf = new byte[256];

                // Receive request
                DatagramPacket packet = new DatagramPacket(buf, buf.length);
                socket.receive(packet);

                // Figure out response
                String dString = null;
                if (in == null)
                    dString = new Date().toString();
                else
                    dString = getNextQuote();
                buf = dString.getBytes();

                // Send response to the client at "address" and "port"
                InetAddress address = packet.getAddress();
                int port = packet.getPort();
                packet = new DatagramPacket(buf, buf.length, address, port);
                socket.send(packet);
            }
            catch (IOException err) {
                err.printStackTrace();
                moreQuotes = false;
            }
        }

        socket.close();
    }

    protected String getNextQuote() {
        String returnValue = null;

        try {
            if ((returnValue = in.readLine()) == null) {
                in.close();
                moreQuotes = false;
                returnValue = "No more quotes. Goodbye.";
            }
        }
        catch (IOException err) {
            returnValue = "IOException occurred in server";
        }

        return returnValue;
    }
}
