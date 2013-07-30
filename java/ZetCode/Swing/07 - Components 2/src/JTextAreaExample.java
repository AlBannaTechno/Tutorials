import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SwingUtilities;


public class JTextAreaExample extends JFrame
{
    public JTextAreaExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout());
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JScrollPane ui_scroll_pane = new JScrollPane();
        JTextArea ui_edit_txt = new JTextArea();

        ui_edit_txt.setLineWrap(true);
        ui_edit_txt.setWrapStyleWord(true);
        ui_edit_txt.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));

        ui_scroll_pane.getViewport().add(ui_edit_txt);
        ui_main_panel.add(ui_scroll_pane);
        this.add(ui_main_panel);

        this.setTitle("JTextArea Example");
        this.setSize(new Dimension(350, 300));
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JTextAreaExample ex = new JTextAreaExample();
                ex.setVisible(true);
            }
        });
    }
}
