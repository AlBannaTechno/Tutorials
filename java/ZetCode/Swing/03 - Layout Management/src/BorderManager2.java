import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;


public class BorderManager2 extends JFrame
{
    public BorderManager2()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JMenuBar menubar = new JMenuBar();
        JMenu file_menu = new JMenu("File");
        menubar.add(file_menu);
        this.setJMenuBar(menubar);

        JToolBar toolbar = new JToolBar();
        toolbar.setFloatable(false);

        ImageIcon exit_icon = new ImageIcon(getClass().getResource("exit.png"));
        JButton exit_btn = new JButton(exit_icon);
        exit_btn.setBorder(new EmptyBorder(0, 0, 0, 0));
        toolbar.add(exit_btn);

        this.add(toolbar, BorderLayout.NORTH);

        JToolBar vertical = new JToolBar(JToolBar.VERTICAL);
        vertical.setFloatable(false);
        vertical.setMargin(new Insets(10, 5, 5, 5));

        ImageIcon select_icon = new ImageIcon(getClass().getResource("drive.png"));
        ImageIcon freehand_icon = new ImageIcon(getClass().getResource("computer.png"));
        ImageIcon shapeed_icon = new ImageIcon(getClass().getResource("printer.png"));

        JButton select_btn = new JButton(select_icon);
        select_btn.setBorder(new EmptyBorder(3, 0, 3, 0));
        JButton freehand_btn = new JButton(freehand_icon);
        freehand_btn.setBorder(new EmptyBorder(3, 0, 3, 0));
        JButton shapeed_btn = new JButton(shapeed_icon);
        shapeed_btn.setBorder(new EmptyBorder(3, 0, 3, 0));

        vertical.add(select_btn);
        vertical.add(freehand_btn);
        vertical.add(shapeed_btn);

        this.add(vertical, BorderLayout.WEST);
        this.add(new JTextArea(), BorderLayout.CENTER);

        JLabel statusbar = new JLabel(" Statusbar");
        statusbar.setPreferredSize(new Dimension(-1, 22));
        statusbar.setBorder(LineBorder.createGrayLineBorder());
        this.add(statusbar, BorderLayout.SOUTH);

        this.setTitle("Border Manager");
        this.setSize(350, 300);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                BorderManager2 ex = new BorderManager2();
                ex.setVisible(true);
            }
        });
    }
}
