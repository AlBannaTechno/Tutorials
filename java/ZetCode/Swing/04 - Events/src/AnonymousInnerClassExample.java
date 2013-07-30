import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class AnonymousInnerClassExample extends JFrame
{
    public AnonymousInnerClassExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        JButton ui_close_btn = new JButton("Close");
        ui_close_btn.setBounds(40, 50, 80, 25);
        ui_close_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        ui_main_panel.add(ui_close_btn);
        this.add(ui_main_panel);

        this.setTitle("Anonymous Inner Class Example");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                AnonymousInnerClassExample ex = new AnonymousInnerClassExample();
                ex.setVisible(true);
            }
        });
    }
}
