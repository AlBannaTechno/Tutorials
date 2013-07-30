import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;


public class Submenu extends JFrame
{
    public Submenu()
    {
        initUi();
    }

    public final void initUi()
    {
        JMenuBar menubar = new JMenuBar();
        ImageIcon new_icon = new ImageIcon(getClass().getResource("new.png"));
        ImageIcon open_icon = new ImageIcon(getClass().getResource("open.png"));
        ImageIcon save_icon = new ImageIcon(getClass().getResource("save.png"));
        ImageIcon exit_icon = new ImageIcon(getClass().getResource("exit.png"));

        JMenu file_menu = new JMenu("File");
        file_menu.setMnemonic(KeyEvent.VK_F);

        JMenu import_menu = new JMenu("Import");
        import_menu.setMnemonic(KeyEvent.VK_M);

        JMenuItem news_item = new JMenuItem("Import News Feed list...");
        JMenuItem book_item = new JMenuItem("Import Bookmarks...");
        JMenuItem mail_item = new JMenuItem("Import Mail...");

        import_menu.add(news_item);
        import_menu.add(book_item);
        import_menu.add(mail_item);

        JMenuItem new_item = new JMenuItem("New", new_icon);
        new_item.setMnemonic(KeyEvent.VK_N);
        JMenuItem open_item = new JMenuItem("Open", open_icon);
        open_item.setMnemonic(KeyEvent.VK_O);
        JMenuItem save_item = new JMenuItem("Save", save_icon);
        save_item.setMnemonic(KeyEvent.VK_S);
        JMenuItem exit_item = new JMenuItem("Exit", exit_icon);
        exit_item.setMnemonic(KeyEvent.VK_C);
        exit_item.setToolTipText("Exit Application");
        exit_item.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W, ActionEvent.CTRL_MASK));
        exit_item.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        file_menu.add(new_item);
        file_menu.add(open_item);
        file_menu.add(save_item);
        file_menu.addSeparator();
        file_menu.add(import_menu);
        file_menu.addSeparator();
        file_menu.add(exit_item);
        menubar.add(file_menu);

        this.setJMenuBar(menubar);
        this.setTitle("Submenu");
        this.setSize(360, 250);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Submenu ex = new Submenu();
                ex.setVisible(true);
            }
        });
    }
}
