import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class InnerClassExample extends JFrame
{
    public InnerClassExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        JButton ui_close_btn = new JButton("Close");
        ui_close_btn.setBounds(40, 50, 80, 25);

        ButtonCloseListener listener = new ButtonCloseListener();
        ui_close_btn.addActionListener(listener);

        ui_main_panel.add(ui_close_btn);
        this.add(ui_main_panel);

        this.setTitle("Inner Class Example");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class ButtonCloseListener implements ActionListener
    {
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
                InnerClassExample ex = new InnerClassExample();
                ex.setVisible(true);
            }
        });
    }
}
