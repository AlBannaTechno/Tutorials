import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonModel;
import javax.swing.DefaultButtonModel;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class JButtonModelExample2 extends JFrame
{
    private JButton ui_ok_btn;
    private JLabel ui_enabled_lbl;
    private JLabel ui_pressed_lbl;
    private JLabel ui_armed_lbl;

    public JButtonModelExample2()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        ui_ok_btn = new JButton("Ok");
        ui_ok_btn.setBounds(40, 30, 80, 25);

        JCheckBox ui_enabled_chk = new JCheckBox("Enabled", true);
        ui_enabled_chk.setBounds(180, 30, 100, 25);
        ui_enabled_chk.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ui_ok_btn.setEnabled(!ui_ok_btn.isEnabled());
            }
        });

        ui_enabled_lbl = new JLabel("Enabled: true");
        ui_enabled_lbl.setBounds(40, 90, 90, 25);
        ui_pressed_lbl = new JLabel("Pressed: false");
        ui_pressed_lbl.setBounds(40, 120, 90, 25);
        ui_armed_lbl = new JLabel("Armed: false");
        ui_armed_lbl.setBounds(40, 150, 90, 25);

        ButtonModel model = new DefaultButtonModel() {
            @Override
            public void setEnabled(boolean b)
            {
                if (b)
                    ui_enabled_lbl.setText("Enabled: true");
                else
                    ui_enabled_lbl.setText("Enabled: false");

                super.setEnabled(b);
            }

            @Override
            public void setPressed(boolean b)
            {
                if (b)
                    ui_pressed_lbl.setText("Pressed: true");
                else
                    ui_pressed_lbl.setText("Pressed: false");

                super.setPressed(b);
            }

            @Override
            public void setArmed(boolean b)
            {
                if (b)
                    ui_armed_lbl.setText("Armed: true");
                else
                    ui_armed_lbl.setText("Armed: false");

                super.setArmed(b);
            }
        };
        ui_ok_btn.setModel(model);

        ui_main_panel.add(ui_ok_btn);
        ui_main_panel.add(ui_enabled_chk);
        ui_main_panel.add(ui_enabled_lbl);
        ui_main_panel.add(ui_pressed_lbl);
        ui_main_panel.add(ui_armed_lbl);
        this.add(ui_main_panel);

        this.setTitle("JButton Model Example 2");
        this.setSize(350, 250);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JButtonModelExample2 ex = new JButtonModelExample2();
                ex.setVisible(true);
            }
        });
    }
}
