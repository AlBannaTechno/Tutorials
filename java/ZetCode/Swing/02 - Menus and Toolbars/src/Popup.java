import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.SwingUtilities;


public class Popup extends JFrame
{
    private JPopupMenu menu;
    private Toolkit toolkit;

    public Popup(String title)
    {
        super(title);
        this.initUi();
    }

    public final void initUi()
    {
        toolkit = this.getToolkit();

        menu = new JPopupMenu();
        JMenuItem beep_item = new JMenuItem("Beep");
        beep_item.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                toolkit.beep();
            }
        });
        menu.add(beep_item);

        JMenuItem close_item = new JMenuItem("Close");
        close_item.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        menu.add(close_item);

        this.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) {
                menu.show(e.getComponent(), e.getX(), e.getY());
            }
        });

        this.setSize(250, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                Popup ex = new Popup("JPopupMenu");
                ex.setVisible(true);
            }
        });
    }
}
