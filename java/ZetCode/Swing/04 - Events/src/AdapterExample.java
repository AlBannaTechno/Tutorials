import java.awt.Font;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class AdapterExample extends JFrame
{
    private JLabel ui_x_lbl;
    private JLabel ui_y_lbl;

    public AdapterExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);

        ui_x_lbl = new JLabel("x: ");
        ui_x_lbl.setFont(new Font("Serif", Font.BOLD, 14));
        ui_x_lbl.setBounds(20, 20, 60, 25);

        ui_y_lbl = new JLabel("y: ");
        ui_y_lbl.setFont(new Font("Serif", Font.BOLD, 14));
        ui_y_lbl.setBounds(20, 45, 60, 25);

        ui_main_panel.add(ui_x_lbl);
        ui_main_panel.add(ui_y_lbl);
        this.add(ui_main_panel);
        this.addComponentListener(new MoveAdapter());

        this.setTitle("Adapter Example");
        this.setSize(310, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class MoveAdapter extends ComponentAdapter
    {
        @Override
        public void componentMoved(ComponentEvent e)
        {
            int x = e.getComponent().getX();
            int y = e.getComponent().getY();
            ui_x_lbl.setText("x: " + x);
            ui_y_lbl.setText("y: " + y);
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                AdapterExample ex = new AdapterExample();
                ex.setVisible(true);
            }
        });
    }
}
