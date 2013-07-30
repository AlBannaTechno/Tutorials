import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class RemoveListenerExample extends JFrame
{
    private JLabel ui_text_lbl;
    private JButton ui_add_btn;
    private JCheckBox ui_active_chk;
    private ButtonListener button_listener;
    private static int count = 0;

    public RemoveListenerExample()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        ui_add_btn = new JButton("+");
        ui_add_btn.setBounds(40, 30, 80, 25);
        button_listener = new ButtonListener();

        ui_active_chk = new JCheckBox("Active Listener");
        ui_active_chk.setBounds(160, 30, 140, 25);
        ui_active_chk.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (ui_active_chk.isSelected())
                    ui_add_btn.addActionListener(button_listener);
                else
                    ui_add_btn.removeActionListener(button_listener);
            }
        });

        ui_text_lbl = new JLabel("0");
        ui_text_lbl.setBounds(40, 80, 80, 25);

        ui_main_panel.add(ui_add_btn);
        ui_main_panel.add(ui_active_chk);
        ui_main_panel.add(ui_text_lbl);
        this.add(ui_main_panel);

        this.setTitle("Remove Listener Example");
        this.setSize(310, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class ButtonListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            ui_text_lbl.setText(Integer.toString(++count));
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                RemoveListenerExample ex = new RemoveListenerExample();
                ex.setVisible(true);
            }
        });
    }
}
