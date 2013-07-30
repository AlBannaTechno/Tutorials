import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;


public class Toolbar extends JFrame
{
    public Toolbar()
    {
        initUi();
    }

    public final void initUi()
    {
        JMenuBar menubar = new JMenuBar();
        JMenu file_menu = new JMenu("File");
        menubar.add(file_menu);
        this.setJMenuBar(menubar);

        JToolBar toolbar = new JToolBar();
        ImageIcon exit_icon = new ImageIcon(getClass().getResource("exit.png"));
        JButton exit_btn = new JButton(exit_icon);
        exit_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        toolbar.add(exit_btn);

        this.add(toolbar, BorderLayout.NORTH);
        this.setTitle("Simple Toolbar");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Toolbar ex = new Toolbar();
                ex.setVisible(true);
            }
        });
    }
}
