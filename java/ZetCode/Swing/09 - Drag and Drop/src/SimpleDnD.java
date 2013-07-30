import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.TransferHandler;


public class SimpleDnD extends JFrame
{
    JTextField ui_info_txt;
    JButton ui_test_btn;

    public SimpleDnD()
    {
        this.setTitle("Simple Drag & Drop");
        this.setLayout(null);

        ui_test_btn = new JButton("Button");
        ui_test_btn.setBounds(200, 50, 90, 25);

        ui_info_txt = new JTextField();
        ui_info_txt.setBounds(30, 50, 150, 25);

        this.add(ui_test_btn);
        this.add(ui_info_txt);

        ui_info_txt.setDragEnabled(true);
        ui_test_btn.setTransferHandler(new TransferHandler("text"));

        ui_test_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JButton source = (JButton) e.getSource();
                if (source.getText().equals("Close"))
                    System.exit(0);
            }
        });

        this.setSize(330, 150);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                SimpleDnD ex = new SimpleDnD();
                ex.setVisible(true);
            }
        });
    }
}
