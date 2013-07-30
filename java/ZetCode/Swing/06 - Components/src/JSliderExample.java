import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.SwingUtilities;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;


public class JSliderExample extends JFrame
{
    private JSlider ui_volume_slider;
    private JLabel ui_volume_lbl;

    ImageIcon mute_icon = new ImageIcon(this.getClass().getResource(
        "speaker-volume-control-mute.png"));
    ImageIcon min_icon = new ImageIcon(this.getClass().getResource("speaker-volume-none.png"));
    ImageIcon med_icon = new ImageIcon(this.getClass().getResource("speaker-volume-low.png"));
    ImageIcon max_icon = new ImageIcon(this.getClass().getResource("speaker-volume.png"));

    public JSliderExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BoxLayout(ui_main_panel, BoxLayout.X_AXIS));
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(40, 40, 40, 40));
        this.setLayout(new BorderLayout());
        
        ui_main_panel.add(Box.createHorizontalGlue());
        ui_volume_slider = new JSlider(0, 150, 0);
        ui_volume_slider.setPreferredSize(new Dimension(150, 30));
        ui_volume_slider.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                int value = ui_volume_slider.getValue();
                
                if (value == 0)
                    ui_volume_lbl.setIcon(mute_icon);
                else if (value > 0 && value <= 30)
                    ui_volume_lbl.setIcon(min_icon);
                else if (value > 30 && value < 80)
                    ui_volume_lbl.setIcon(med_icon);
                else
                    ui_volume_lbl.setIcon(max_icon);
            }
        });

        ui_main_panel.add(ui_volume_slider);
        ui_main_panel.add(Box.createRigidArea(new Dimension(5, 0)));

        ui_volume_lbl = new JLabel(mute_icon, JLabel.CENTER);
        ui_main_panel.add(ui_volume_lbl);
        ui_main_panel.add(Box.createHorizontalGlue());
        this.add(ui_main_panel, BorderLayout.CENTER);
        this.pack();

        this.setTitle("JSlider");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JSliderExample ex = new JSliderExample();
                ex.setVisible(true);
            }
        });
    }
}
