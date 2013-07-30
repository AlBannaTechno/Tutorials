import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Calendar;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingUtilities;
import javax.swing.border.EtchedBorder;


public class MultipleListenersExample extends JFrame
{
    private JLabel ui_statusbar;
    private JSpinner ui_spinner;
    private static int count = 0;

    public MultipleListenersExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        ui_statusbar = new JLabel("0");
        ui_statusbar.setBorder(BorderFactory.createEtchedBorder(EtchedBorder.RAISED));

        JButton ui_add_btn = new JButton("+");
        ui_add_btn.setBounds(40, 30, 80, 25);
        ui_add_btn.addActionListener(new ButtonListener1());
        ui_add_btn.addActionListener(new ButtonListener2());

        Calendar calendar = Calendar.getInstance();
        int current_year = calendar.get(Calendar.YEAR);

        SpinnerModel ui_year_smod = new SpinnerNumberModel(current_year, current_year - 100,
            current_year + 100, 1);

        ui_spinner = new JSpinner(ui_year_smod);
        ui_spinner.setEditor(new JSpinner.NumberEditor(ui_spinner, "#"));
        ui_spinner.setBounds(190, 30, 80, 25);

        ui_main_panel.add(ui_add_btn);
        ui_main_panel.add(ui_spinner);

        this.add(ui_main_panel);
        this.add(ui_statusbar, BorderLayout.SOUTH);

        this.setTitle("Multiple Listeners");
        this.setSize(300, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class ButtonListener1 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            Integer val = (Integer) ui_spinner.getValue();
            ui_spinner.setValue(++val);
        }
    }

    class ButtonListener2 implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            ui_statusbar.setText(Integer.toString(++count));
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                MultipleListenersExample ex = new MultipleListenersExample();
                ex.setVisible(true);
            }
        });
    }
}
