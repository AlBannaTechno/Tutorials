import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.SwingUtilities;


class AboutDialog extends JDialog
{
    public AboutDialog()
    {
        this.initUi();
    }

    public final void initUi()
    {
        this.setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        this.add(Box.createRigidArea(new Dimension(0, 10)));

        ImageIcon ui_notes_img = new ImageIcon(getClass().getResource("smiley.png"));
        JLabel ui_notes_lbl = new JLabel(ui_notes_img);
        ui_notes_lbl.setAlignmentX(0.5f);
        this.add(ui_notes_lbl);
        this.add(Box.createRigidArea(new Dimension(0, 10)));

        JLabel ui_name_lbl = new JLabel("Notes, 1.23");
        ui_name_lbl.setFont(new Font("Serif", Font.BOLD, 13));
        ui_name_lbl.setAlignmentX(0.5f);
        this.add(ui_name_lbl);
        this.add(Box.createRigidArea(new Dimension(0, 50)));

        JButton ui_close_btn = new JButton("Close");
        ui_close_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        ui_close_btn.setAlignmentX(0.5f);
        this.add(ui_close_btn);

        this.setModalityType(ModalityType.APPLICATION_MODAL);
        this.setTitle("About Notes");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }
}

public class AboutDialogExample extends JFrame
{
    public AboutDialogExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JMenuBar ui_menubar = new JMenuBar();

        JMenu ui_file_menu = new JMenu("File");
        ui_file_menu.setMnemonic(KeyEvent.VK_F);

        JMenu ui_help_menu = new JMenu("Help");
        ui_help_menu.setMnemonic(KeyEvent.VK_H);

        JMenuItem ui_about_act = new JMenuItem("About");
        ui_help_menu.add(ui_about_act);

        ui_about_act.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                AboutDialog ex = new AboutDialog();
                ex.setVisible(true);
            }
        });

        ui_menubar.add(ui_file_menu);
        ui_menubar.add(ui_help_menu);
        this.setJMenuBar(ui_menubar);

        this.setTitle("About Dialog Example");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                AboutDialogExample ex = new AboutDialogExample();
                ex.setVisible(true);
            }
        });
    }
}
