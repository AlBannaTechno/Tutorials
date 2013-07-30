import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class Tooltip extends JFrame
{
    public Tooltip()
    {
        initUi();
    }

    public final void initUi()
    {
        JPanel panel = new JPanel();
        this.getContentPane().add(panel);
        panel.setLayout(null);
        panel.setToolTipText("A JPanel widget");

        JButton button = new JButton("Button");
        button.setBounds(100, 60, 100, 30);
        button.setToolTipText("A JButton widget");
        panel.add(button);

        this.setTitle("Tooltip");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Tooltip ex = new Tooltip();
                ex.setVisible(true);
            }
        });
    }
}
