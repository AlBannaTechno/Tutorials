import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.SwingUtilities;
import javax.swing.Timer;


public class JProgressBarExample extends JFrame
{
    ActionListener updateProgressBar;
    Timer timer;
    JProgressBar ui_time_prog;
    JButton ui_start_btn;

    public JProgressBarExample()
    {
        this.setTitle("JProgressBar Example");

        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(40, 40, 40, 40));
        ui_main_panel.setLayout(new BoxLayout(ui_main_panel, BoxLayout.Y_AXIS));

        ui_time_prog = new JProgressBar();
        ui_time_prog.setMaximumSize(new Dimension(150, 20));
        ui_time_prog.setMinimumSize(new Dimension(150, 20));
        ui_time_prog.setPreferredSize(new Dimension(150, 20));
        ui_time_prog.setAlignmentX(0f);

        ui_main_panel.add(ui_time_prog);
        ui_main_panel.add(Box.createRigidArea(new Dimension(0, 20)));

        ui_start_btn = new JButton("Start");
        ui_start_btn.setFocusable(false);
        ui_start_btn.setMaximumSize(ui_start_btn.getPreferredSize());

        updateProgressBar = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int val = ui_time_prog.getValue();
                if (val >= 100) {
                    timer.stop();
                    ui_start_btn.setText("End");
                    return;
                }
                ui_time_prog.setValue(++val);
            }
        };

        timer = new Timer(50, updateProgressBar);

        ui_start_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (timer.isRunning()) {
                    timer.stop();
                    ui_start_btn.setText("Start");
                }
                else if (ui_start_btn.getText() != "End") {
                    timer.start();
                    ui_start_btn.setText("Stop");
                }
                else if (ui_start_btn.getText() == "End") {
                    System.exit(0);
                }
            }
        });

        ui_main_panel.add(ui_start_btn);
        this.add(ui_main_panel);
        this.pack();

        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JProgressBarExample ex = new JProgressBarExample();
                ex.setVisible(true);
            }
        });
    }
}
