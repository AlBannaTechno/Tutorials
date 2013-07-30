import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;
import javax.swing.border.LineBorder;


public class JComboBoxExample extends JDialog implements ActionListener, ItemListener
{
    final String[] authors = { "Leo Tolstoy", "John Galsworthy", "Honore de Balzac", "Stefan Zweig",
        "Boris Basternak", "Tom Wolfe" };

    final String[] images = { "tolstoy.jpg", "galsworthy.jpg", "balzac.jpg", "zweig.jpg",
        "pasternack.jpg", "wolfe.jpg" };

    private JLabel ui_display_lbl = null;
    private JComboBox ui_authors_combo = null;
    private JButton ui_close_btn = null;

    public JComboBoxExample()
    {
        this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));
        this.add(Box.createRigidArea(new Dimension(0, 25)));

        ui_display_lbl = new JLabel();
        ui_display_lbl.setPreferredSize(new Dimension(100, 127));
        ui_display_lbl.setMaximumSize(new Dimension(100, 127));
        ui_display_lbl.setAlignmentX(Component.CENTER_ALIGNMENT);
        ui_display_lbl.setBorder(LineBorder.createGrayLineBorder());
        this.add(ui_display_lbl);
        this.add(Box.createRigidArea(new Dimension(0, 15)));

        ui_authors_combo = new JComboBox(authors);
        ui_authors_combo.setSelectedIndex(-1);
        ui_authors_combo.setPreferredSize(new Dimension(140, 22));
        ui_authors_combo.setMaximumSize(new Dimension(140, 22));
        ui_authors_combo.addItemListener(this);
        this.add(ui_authors_combo);

        ui_close_btn = new JButton("Close");
        ui_close_btn.setAlignmentX(Component.CENTER_ALIGNMENT);
        ui_close_btn.addActionListener(this);
        this.add(ui_close_btn);

        this.setTitle("JComboBox Example");
        this.setSize(300, 300);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }

    public void itemStateChanged(ItemEvent e)
    {
        if (e.getStateChange() == ItemEvent.SELECTED) {
            JComboBox source = (JComboBox) e.getSource();
            int index = source.getSelectedIndex();
            ui_display_lbl.setIcon(new ImageIcon(this.getClass().getResource(images[index])));
        }
    }

    public void actionPerformed(ActionEvent e) {
        System.exit(0);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JComboBoxExample ex = new JComboBoxExample();
                ex.setVisible(true);
            }
        });
    }
}
