import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class JLabelExample extends JFrame
{
    private Toolkit toolkit;

    public JLabelExample()
    {
        this.setTitle("No Sleep");

        String lyrics = "<html>It's way too late to think of<br>" +
            "Someone I would call now<br>" +
            "And neon signs got tired<br>" +
            "Red eye flights help the stars out<br>" +
            "I'm safe in a corner<br>" +
            "Just hours before me<br>" +
            "<br>" +
            "I'm waking with the roaches<br>" +
            "The world has surrendered<br>" +
            "I'm dating ancient ghosts<br>" +
            "The ones I made friends with<br>" +
            "The comfort of fireflies<br>" +
            "Long gone before daylight<br>" +
            "<br>" +
            "And if I had one wishful field tonight<br>" +
            "I'd ask for the sun to never rise<br>" +
            "If God leant his voice for me to speak<br>" +
            "I'd say go to bed, world<br>" +
            "<br>" +
            "I've always been too late<br>" +
            "To see what's before me<br>" +
            "And I know nothing sweeter than<br>" +
            "Champaign from last New Years<br>" +
            "Sweet music in my ears<br>" +
            "And a night full of no fears<br>" +
            "<br>" +
            "But if I had one wishful field tonight<br>" +
            "I'd ask for the sun to never rise<br>" +
            "If God passed a mic to me to speak<br>" +
            "I'd say stay in bed, world<br>" +
            "Sleep in peace</html>";

        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout(10, 10));

        JLabel ui_lyrics_lbl = new JLabel(lyrics);
        ui_lyrics_lbl.setFont(new Font("Georgia", Font.PLAIN, 14));
        ui_lyrics_lbl.setForeground(new Color(50, 50, 25));

        ui_main_panel.add(ui_lyrics_lbl, BorderLayout.CENTER);
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        this.add(ui_main_panel);
        this.pack();

        toolkit = this.getToolkit();
        Dimension screensize = toolkit.getScreenSize();
        this.setLocation((screensize.width - this.getWidth()) / 2,
            (screensize.height - this.getHeight()) / 2);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JLabelExample ex = new JLabelExample();
                ex.setVisible(true);
            }
        });
    }
}
