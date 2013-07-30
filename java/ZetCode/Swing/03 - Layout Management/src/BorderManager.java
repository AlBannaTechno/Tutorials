import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;


public class BorderManager extends JFrame
{
    public BorderManager()
    {
        initUi();
    }

    public final void initUi()
    {
        JPanel panel = new JPanel(new BorderLayout());
        JPanel top = new JPanel();

        top.setBackground(Color.gray);
        top.setPreferredSize(new Dimension(250, 150));
        panel.add(top);
        panel.setBorder(new EmptyBorder(new Insets(20, 20, 20, 20)));

        this.add(panel);
        this.pack();
        this.setTitle("Border Manager");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                BorderManager ex = new BorderManager();
                ex.setVisible(true);
            }
        });
    }
}
