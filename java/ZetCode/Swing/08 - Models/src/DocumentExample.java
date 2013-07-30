import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;


public class DocumentExample extends JFrame
{
    private StyledDocument doc;
    private JTextPane ui_input_txtpane;

    public DocumentExample()
    {
        JToolBar ui_main_tool = new JToolBar();

        ImageIcon bold_icon = new ImageIcon(this.getClass().getResource("edit-bold.png"));
        ImageIcon italic_icon = new ImageIcon(this.getClass().getResource("edit-italic.png"));
        ImageIcon strike_icon = new ImageIcon(this.getClass().getResource("edit-strike.png"));
        ImageIcon underline_icon = new ImageIcon(this.getClass().getResource("edit-underline.png"));

        JButton ui_bold_btn = new JButton(bold_icon);
        JButton ui_italic_btn = new JButton(italic_icon);
        JButton ui_strike_btn = new JButton(strike_icon);
        JButton ui_underline_btn = new JButton(underline_icon);

        ui_main_tool.add(ui_bold_btn);
        ui_main_tool.add(ui_italic_btn);
        ui_main_tool.add(ui_strike_btn);
        ui_main_tool.add(ui_underline_btn);
        this.add(ui_main_tool, BorderLayout.NORTH);

        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout());
        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JScrollPane ui_text_spane = new JScrollPane();
        ui_input_txtpane = new JTextPane();
        ui_input_txtpane.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
        doc = ui_input_txtpane.getStyledDocument();

        Style style = ui_input_txtpane.addStyle("Bold", null);
        StyleConstants.setBold(style, true);

        style = ui_input_txtpane.addStyle("Italic", null);
        StyleConstants.setItalic(style, true);

        style = ui_input_txtpane.addStyle("Underline", null);
        StyleConstants.setUnderline(style, true);

        style = ui_input_txtpane.addStyle("Strike", null);
        StyleConstants.setStrikeThrough(style, true);

        ui_bold_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                doc.setCharacterAttributes(ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getSelectionEnd() - ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getStyle("Bold"), false);
            }
        });

        ui_italic_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                doc.setCharacterAttributes(ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getSelectionEnd() - ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getStyle("Italic"), false);
            }
        });

        ui_strike_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                doc.setCharacterAttributes(ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getSelectionEnd() - ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getStyle("Strike"), false);
            }
        });

        ui_underline_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                doc.setCharacterAttributes(ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getSelectionEnd() - ui_input_txtpane.getSelectionStart(),
                    ui_input_txtpane.getStyle("Underline"), false);
            }
        });

        ui_text_spane.getViewport().add(ui_input_txtpane);
        ui_main_panel.add(ui_text_spane);
        this.add(ui_main_panel);

        this.setTitle("Document Example");
        this.setSize(new Dimension(380, 320));
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                DocumentExample ex = new DocumentExample();
                ex.setVisible(true);
            }
        });
    }
}
