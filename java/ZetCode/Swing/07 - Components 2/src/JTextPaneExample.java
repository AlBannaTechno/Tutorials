import java.awt.BorderLayout;
import java.awt.Dimension;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.SwingUtilities;


public class JTextPaneExample extends JFrame
{
    public JTextPaneExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout());
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JScrollPane pane = new JScrollPane();
        JTextPane text_pane = new JTextPane();

        text_pane.setContentType("text/html");
        text_pane.setEditable(false);

        String cd = System.getProperty("user.dir") + "/";

        try {
            text_pane.setPage("File:///" + cd + "text.html");
        } catch (IOException e) {
            System.out.println("Exception: " + e);
        }

        text_pane.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
        pane.getViewport().add(text_pane);
        ui_main_panel.add(pane);
        this.add(ui_main_panel);

        this.setTitle("JTextPane Example");
        this.setSize(new Dimension(380, 320));
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JTextPaneExample ex = new JTextPaneExample();
                ex.setVisible(true);
            }
        });
    }
}
