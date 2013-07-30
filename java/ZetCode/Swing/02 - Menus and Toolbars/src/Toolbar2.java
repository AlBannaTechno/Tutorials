import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;


public class Toolbar2 extends JFrame
{
    public Toolbar2()
    {
        initUi();
    }

    public final void initUi()
    {
        JToolBar toolbar1 = new JToolBar();
        JToolBar toolbar2 = new JToolBar();

        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        ImageIcon new_icon = new ImageIcon(getClass().getResource("new.png"));
        ImageIcon open_icon = new ImageIcon(getClass().getResource("open.png"));
        ImageIcon save_icon = new ImageIcon(getClass().getResource("save.png"));
        ImageIcon exit_icon = new ImageIcon(getClass().getResource("exit.png"));

        JButton new_btn = new JButton(new_icon);
        JButton open_btn = new JButton(open_icon);
        JButton save_btn = new JButton(save_icon);

        toolbar1.add(new_btn);
        toolbar1.add(open_btn);
        toolbar1.add(save_btn);
        toolbar1.setAlignmentX(0);

        JButton exit_btn = new JButton(exit_icon);
        toolbar2.add(exit_btn);
        toolbar2.setAlignmentX(0);

        exit_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        panel.add(toolbar1);
        panel.add(toolbar2);
        this.add(panel, BorderLayout.NORTH);

        this.setTitle("Toolbars");
        this.setSize(360, 250);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Toolbar2 ex = new Toolbar2();
                ex.setVisible(true);
            }
        });
    }
}
