package networking;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.util.Date;


public class MulticastServer {
    public static void main(String[] args) throws IOException {
        new MulticastServerThread().start();
    }
}


class MulticastServerThread extends QuoteServerThread {
    private final long FIVESECONDS = 5000;

    public MulticastServerThread() throws IOException {
        super("MulticastServerThread");
    }

    @Override
    public void run() {
        while (moreQuotes) {
            try {
                byte[] buf = new byte[256];

                // Construct quote
                String dString = null;
                if (in == null)
                    dString = new Date().toString();
                else
                    dString = getNextQuote();
                buf = dString.getBytes();

                // Send it
                InetAddress group = InetAddress.getByName("230.0.0.1");
                DatagramPacket packet = new DatagramPacket(buf, buf.length, group, 4446);
                socket.send(packet);

                // Sleep for a while
                try {
                    sleep((long)(Math.random() * FIVESECONDS));
                }
                catch (InterruptedException err) {
                    err.printStackTrace();
                }
            }
            catch (IOException err) {
                err.printStackTrace();
                moreQuotes = false;
            }
        }

        socket.close();
    }
}