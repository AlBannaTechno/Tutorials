import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;


public class ColorDialogExample extends JFrame
{
    private JPanel ui_main_panel;
    private JPanel ui_display_panel;

    public ColorDialogExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout());
        ImageIcon open_icon = new ImageIcon(getClass().getResource("color.png"));

        JToolBar ui_main_tbar = new JToolBar();
        JButton ui_open_btn = new JButton(open_icon);
        ui_open_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JColorChooser clr = new JColorChooser();
                Color color = clr.showDialog(ui_main_panel, "Color Chooser", Color.white);
                ui_display_panel.setBackground(color);
            }
        });

        ui_main_tbar.add(ui_open_btn);

        ui_display_panel = new JPanel();
        ui_display_panel.setBackground(Color.WHITE);

        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(30, 50, 30, 50));
        ui_main_panel.add(ui_display_panel);
        this.add(ui_main_panel);
        this.add(ui_main_tbar, BorderLayout.NORTH);

        this.setTitle("Color Dialog Example");
        this.setSize(400, 300);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                ColorDialogExample ex = new ColorDialogExample();
                ex.setVisible(true);
            }
        });
    }
}
