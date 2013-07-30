import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.BorderFactory;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.SwingUtilities;
import javax.swing.border.EtchedBorder;


public class CbMenuItem extends JFrame
{
    private JLabel statusbar;

    public CbMenuItem()
    {
        initUi();
    }

    public final void initUi()
    {
        JMenuBar menubar = new JMenuBar();
        JMenu file_menu = new JMenu("File");
        file_menu.setMnemonic(KeyEvent.VK_F);
        JMenu view_menu = new JMenu("View");
        view_menu.setMnemonic(KeyEvent.VK_V);

        JCheckBoxMenuItem show_sbar_item = new JCheckBoxMenuItem("Show Statusbar");
        show_sbar_item.setState(true);
        show_sbar_item.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                statusbar.setVisible(!statusbar.isVisible());
            }
        });

        view_menu.add(show_sbar_item);
        menubar.add(file_menu);
        menubar.add(view_menu);
        this.setJMenuBar(menubar);

        statusbar = new JLabel(" Statusbar");
        statusbar.setBorder(BorderFactory.createEtchedBorder(EtchedBorder.RAISED));
        this.add(statusbar, BorderLayout.SOUTH);

        this.setTitle("JCheckBoxMenuItem");
        this.setSize(360, 250);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                CbMenuItem ex = new CbMenuItem();
                ex.setVisible(true);
            }
        });
    }
}
