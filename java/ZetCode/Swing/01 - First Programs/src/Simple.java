import javax.swing.JFrame;
import javax.swing.SwingUtilities;


public class Simple extends JFrame
{
    public Simple()
    {
        this.setTitle("Simple Example");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Simple ex = new Simple();
                ex.setVisible(true);
            }
        });
    }
}
