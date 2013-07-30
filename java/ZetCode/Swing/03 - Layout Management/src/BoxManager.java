import java.awt.Dimension;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class BoxManager extends JFrame
{
    public BoxManager()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_basic_panel = new JPanel();
        ui_basic_panel.setLayout(new BoxLayout(ui_basic_panel, BoxLayout.Y_AXIS));
        this.add(ui_basic_panel);
        ui_basic_panel.add(Box.createVerticalGlue());

        JPanel ui_bottom_panel = new JPanel();
        ui_bottom_panel.setAlignmentX(1f);
        ui_bottom_panel.setLayout(new BoxLayout(ui_bottom_panel, BoxLayout.X_AXIS));

        JButton ui_ok_btn = new JButton("Ok");
        JButton ui_close_btn = new JButton("Close");

        ui_bottom_panel.add(ui_ok_btn);
        ui_bottom_panel.add(Box.createRigidArea(new Dimension(5, 0)));
        ui_bottom_panel.add(ui_close_btn);
        ui_bottom_panel.add(Box.createRigidArea(new Dimension(15, 0)));

        ui_basic_panel.add(ui_bottom_panel);
        ui_basic_panel.add(Box.createRigidArea(new Dimension(0, 15)));

        this.setTitle("Two Buttons");
        this.setSize(300, 150);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                BoxManager ex = new BoxManager();
                ex.setVisible(true);
            }
        });
    }
}
