import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class DerivedClassExample extends JFrame
{
    public DerivedClassExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        CustomButton ui_close_btn = new CustomButton("Close");
        ui_close_btn.setBounds(40, 50, 80, 25);

        ui_main_panel.add(ui_close_btn);
        this.add(ui_main_panel);

        this.setTitle("Derived Class");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class CustomButton extends JButton implements ActionListener
    {
        public CustomButton(String text)
        {
            super.setText(text);
            this.addActionListener(this);
        }

        public void actionPerformed(ActionEvent e)
        {
            System.exit(0);
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                DerivedClassExample ex = new DerivedClassExample();
                ex.setVisible(true);
            }
        });
    }
}
