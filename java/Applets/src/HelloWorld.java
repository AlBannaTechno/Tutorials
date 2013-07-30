import javax.swing.JApplet;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;

public class HelloWorld extends JApplet {
    //Called when this applet is loaded into the browser.
    @Override
    public void init() {
        //Execute a job on the event-dispatching thread; creating this applet's GUI.
        try {
            SwingUtilities.invokeAndWait(new Runnable() {
                @Override
                public void run() {
                    JLabel lbl = new JLabel("Hello World");
                    add(lbl);
                }
            });
        } catch (Exception e) {
            System.err.println("CreateGUI didn't complete successfully");
        }
    }
}