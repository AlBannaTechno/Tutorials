import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.KeyEvent;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.JTextPane;
import javax.swing.SwingUtilities;


public class TipOfTheDay extends JDialog
{
    public TipOfTheDay()
    {
        this.initUi();
    }
    
    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BoxLayout(ui_main_panel, BoxLayout.Y_AXIS));
        this.add(ui_main_panel);
        
        JPanel ui_top_panel = new JPanel(new BorderLayout(0, 0));
        ui_top_panel.setMaximumSize(new Dimension(450, 0));
        JLabel ui_hint_lbl = new JLabel("JDeveloper Productivity Hints");
        ui_hint_lbl.setBorder(BorderFactory.createEmptyBorder(0, 25, 0, 0));
        ui_top_panel.add(ui_hint_lbl);
        
        ImageIcon ui_hint_img = new ImageIcon(getClass().getResource("tips.png"));
        JLabel ui_hint_img_lbl = new JLabel(ui_hint_img);
        ui_hint_img_lbl.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        ui_top_panel.add(ui_hint_img_lbl, BorderLayout.EAST);
        
        JSeparator ui_top_sep = new JSeparator();
        ui_top_sep.setForeground(Color.gray);
        ui_top_panel.add(ui_top_sep, BorderLayout.SOUTH);
        ui_main_panel.add(ui_top_panel);

        JPanel ui_text_panel = new JPanel(new BorderLayout());
        ui_text_panel.setBorder(BorderFactory.createEmptyBorder(15, 25, 15, 25));
        JTextPane ui_text_txt = new JTextPane();

        ui_text_txt.setContentType("text/html");
        String text = "<p><b>Closing windows using the mouse wheel</b></p>" +
            "<p>Clicking with the mouse wheel on an editor tab closes the window. This method " +
            "works also with docable windows or Log window tabs.</p>";
        ui_text_txt.setText(text);
        ui_text_txt.setEditable(false);
        ui_text_panel.add(ui_text_txt);
        ui_main_panel.add(ui_text_panel);

        JPanel ui_box_panel = new JPanel(new FlowLayout(FlowLayout.LEFT, 20, 0));
        JCheckBox ui_box_chk = new JCheckBox("Show Tips at startup");
        ui_box_chk.setMnemonic(KeyEvent.VK_S);
        ui_box_panel.add(ui_box_chk);
        ui_main_panel.add(ui_box_panel);

        JPanel ui_bottom_panel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton ui_next_btn = new JButton("Next Tip");
        ui_next_btn.setMnemonic(KeyEvent.VK_N);
        JButton ui_close_btn = new JButton("Close");
        ui_close_btn.setMnemonic(KeyEvent.VK_C);
        ui_bottom_panel.add(ui_next_btn);
        ui_bottom_panel.add(ui_close_btn);
        ui_main_panel.add(ui_bottom_panel);
        ui_bottom_panel.setMaximumSize(new Dimension(450, 0));

        this.setTitle("Tip of the Day");
        this.setSize(new Dimension(450, 350));
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                TipOfTheDay ex = new TipOfTheDay();
                ex.setVisible(true);
            }
        });
    }
}
