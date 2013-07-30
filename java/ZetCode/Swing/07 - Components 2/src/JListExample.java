import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GraphicsEnvironment;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.SwingUtilities;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;


public class JListExample extends JFrame
{
    private JLabel ui_example_lbl;
    private JList ui_fonts_list;

    public JListExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout());
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        GraphicsEnvironment enviro = GraphicsEnvironment.getLocalGraphicsEnvironment();

        String[] fonts = enviro.getAvailableFontFamilyNames();
        ui_fonts_list = new JList(fonts);
        ui_fonts_list.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    String name = (String) ui_fonts_list.getSelectedValue();
                    Font font = new Font(name, Font.PLAIN, 12);
                    ui_example_lbl.setFont(font);
                }
            }
        });

        JScrollPane ui_scroll_pane = new JScrollPane();
        ui_scroll_pane.getViewport().add(ui_fonts_list);
        ui_scroll_pane.setPreferredSize(new Dimension(250, 200));
        ui_main_panel.add(ui_scroll_pane);

        ui_example_lbl = new JLabel("Aguirre, der Zorn Gottes");
        ui_example_lbl.setFont(new Font("Serif", Font.PLAIN, 12));

        this.add(ui_example_lbl, BorderLayout.SOUTH);
        this.add(ui_main_panel);
        this.pack();

        this.setTitle("JList Example");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JListExample ex = new JListExample();
                ex.setVisible(true);
            }
        });
    }
}
