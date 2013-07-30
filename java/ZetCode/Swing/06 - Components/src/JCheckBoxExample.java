import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;


public class JCheckBoxExample extends JFrame implements ActionListener
{
    public JCheckBoxExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
        this.add(Box.createRigidArea(new Dimension(15, 20)));

        JCheckBox ui_title_chk = new JCheckBox("Show Title", true);
        ui_title_chk.setFocusable(false);
        ui_title_chk.addActionListener(this);
        this.add(ui_title_chk);

        this.setSize(280, 200);
        this.setTitle("JCheckBox Example");
        this.setLocationRelativeTo(null);
        this.setResizable(false);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e)
    {
        JCheckBox source = (JCheckBox) e.getSource();
        if (source.isSelected())
            this.setTitle("JCheckBox Example");
        else
            this.setTitle("");
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JCheckBoxExample ex = new JCheckBoxExample();
                ex.setVisible(true);
            }
        });
    }
}
