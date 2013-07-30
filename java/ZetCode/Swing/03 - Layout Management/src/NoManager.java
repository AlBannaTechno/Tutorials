import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;


public class NoManager extends JFrame
{
    public NoManager()
    {
        initUi();
    }

    public final void initUi()
    {
        this.setLayout(null);

        JButton ok_btn = new JButton("Ok");
        ok_btn.setBounds(50, 50, 80, 25);
        JButton close_btn = new JButton("Close");
        close_btn.setBounds(150, 50, 80, 25);

        this.add(ok_btn);
        this.add(close_btn);

        this.setTitle("Absolute Positioning");
        this.setSize(300, 250);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                NoManager ex = new NoManager();
                ex.setVisible(true);
            }
        });
    }
}
