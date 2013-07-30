import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class MessageBoxExample extends JFrame
{
    private JPanel ui_main_panel;

    public MessageBoxExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new GridLayout(2, 2));

        JButton ui_error_btn = new JButton("Error");
        JButton ui_warning_btn = new JButton("Warning");
        JButton ui_question_btn = new JButton("Question");
        JButton ui_info_btn = new JButton("Information");

        ui_error_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(ui_main_panel, "Could not open file", "Error",
                    JOptionPane.ERROR_MESSAGE);
            }
        });

        ui_warning_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(ui_main_panel, "A deprecated call", "Warning",
                    JOptionPane.WARNING_MESSAGE);
            }
        });

        ui_question_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(ui_main_panel, "Are you sure to quit?", "Question",
                    JOptionPane.QUESTION_MESSAGE);
            }
        });

        ui_info_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(ui_main_panel, "Download completed", "Information",
                    JOptionPane.INFORMATION_MESSAGE);
            }
        });

        ui_main_panel.add(ui_error_btn);
        ui_main_panel.add(ui_warning_btn);
        ui_main_panel.add(ui_question_btn);
        ui_main_panel.add(ui_info_btn);
        this.add(ui_main_panel);

        this.setTitle("Message Boxes");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                MessageBoxExample ex = new MessageBoxExample();
                ex.setVisible(true);
            }
        });
    }
}
