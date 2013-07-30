import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JToggleButton;
import javax.swing.SwingUtilities;
import javax.swing.border.LineBorder;


public class JToggleButtonExample extends JDialog implements ActionListener
{
    private JToggleButton ui_red_toggle;
    private JToggleButton ui_green_toggle;
    private JToggleButton ui_blue_toggle;
    private JPanel ui_display_panel;
    
    public JToggleButtonExample()
    {
        this.initUi();
    }
    
    public final void initUi()
    {
        JPanel ui_bottom_panel = new JPanel();
        ui_bottom_panel.setLayout(new BoxLayout(ui_bottom_panel, BoxLayout.X_AXIS));
        ui_bottom_panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        
        JPanel ui_left_panel = new JPanel();
        ui_left_panel.setLayout(new BoxLayout(ui_left_panel, BoxLayout.Y_AXIS));
        
        ui_red_toggle = new JToggleButton("Red");
        ui_red_toggle.addActionListener(this);
        
        ui_green_toggle = new JToggleButton("Green");
        ui_green_toggle.addActionListener(this);
        
        ui_blue_toggle = new JToggleButton("Blue");
        ui_blue_toggle.addActionListener(this);
        
        ui_red_toggle.setMaximumSize(ui_green_toggle.getMaximumSize());
        ui_blue_toggle.setMaximumSize(ui_green_toggle.getMaximumSize());

        ui_left_panel.add(ui_red_toggle);
        ui_left_panel.add(Box.createRigidArea(new Dimension(25, 7)));
        ui_left_panel.add(ui_green_toggle);
        ui_left_panel.add(Box.createRigidArea(new Dimension(25, 7)));
        ui_left_panel.add(ui_blue_toggle);

        ui_bottom_panel.add(ui_left_panel);
        ui_bottom_panel.add(Box.createRigidArea(new Dimension(20, 0)));

        ui_display_panel = new JPanel();
        ui_display_panel.setPreferredSize(new Dimension(110, 110));
        ui_display_panel.setBorder(LineBorder.createGrayLineBorder());
        ui_display_panel.setBackground(Color.black);

        ui_bottom_panel.add(ui_display_panel);
        this.add(ui_bottom_panel);
        this.pack();

        this.setTitle("JToggleButton Example");
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e)
    {
        Color color = ui_display_panel.getBackground();
        int red = color.getRed();
        int green = color.getGreen();
        int blue = color.getBlue();

        if (e.getActionCommand().equals("Red"))
            if (red == 0)
                red = 255;
            else
                red = 0;

        if (e.getActionCommand().equals("Green"))
            if (green == 0)
                green = 255;
            else
                green = 0;

        if (e.getActionCommand().equals("Blue"))
            if (blue == 0)
                blue = 255;
            else
                blue = 0;

        Color new_color = new Color(red, green, blue);
        ui_display_panel.setBackground(new_color);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JToggleButtonExample ex = new JToggleButtonExample();
                ex.setVisible(true);
            }
        });
    }
}
