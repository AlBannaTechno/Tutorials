import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class QuitButton extends JFrame
{
    public QuitButton()
    {
        initUi();
    }

    public final void initUi()
    {
        JPanel panel = new JPanel();
        this.getContentPane().add(panel);
        panel.setLayout(null);

        JButton quit_button = new JButton("Quit");
        quit_button.setBounds(50, 60, 80, 30);
        quit_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        panel.add(quit_button);

        this.setTitle("Quit Button");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                QuitButton ex = new QuitButton();
                ex.setVisible(true);
            }
        });
    }
}
