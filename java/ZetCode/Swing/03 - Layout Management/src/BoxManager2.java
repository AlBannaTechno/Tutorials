import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;


public class BoxManager2 extends JFrame
{
    public BoxManager2()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BoxLayout(ui_main_panel, BoxLayout.Y_AXIS));
        ui_main_panel.setBorder(new EmptyBorder(new Insets(40, 60, 40, 60)));

        ui_main_panel.add(new JButton("Button"));
        ui_main_panel.add(Box.createRigidArea(new Dimension(0, 5)));
        ui_main_panel.add(new JButton("Button"));
        ui_main_panel.add(Box.createRigidArea(new Dimension(0, 5)));
        ui_main_panel.add(new JButton("Button"));
        ui_main_panel.add(Box.createRigidArea(new Dimension(0, 5)));
        ui_main_panel.add(new JButton("Button"));

        this.add(ui_main_panel);
        this.pack();
        this.setTitle("RigidArea");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                BoxManager2 ex = new BoxManager2();
                ex.setVisible(true);
            }
        });
    }
}
