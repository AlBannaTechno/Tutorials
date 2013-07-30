import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;


public class OpenDialogExample extends JFrame
{
    private JPanel ui_main_panel;
    private JTextArea ui_area_txt;

    public OpenDialogExample()
    {
        this.initUi();
    }

    public final void initUi()
    {
        ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BorderLayout());
        ImageIcon ui_open_ico = new ImageIcon(getClass().getResource("folder-open.png"));

        JToolBar ui_bar1_tools = new JToolBar();
        JButton ui_open_btn = new JButton(ui_open_ico);
        ui_open_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser file_open = new JFileChooser();
                FileFilter filter = new FileNameExtensionFilter("c files", "c");
                file_open.addChoosableFileFilter(filter);

                int ret = file_open.showDialog(ui_main_panel, "Open File");
                if (ret == JFileChooser.APPROVE_OPTION) {
                    File file = file_open.getSelectedFile();
                    String text = readFile(file);
                    ui_area_txt.setText(text);
                }
            }
        });

        ui_bar1_tools.add(ui_open_btn);

        ui_area_txt = new JTextArea();
        ui_area_txt.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JScrollPane ui_pane_scroll = new JScrollPane();
        ui_pane_scroll.getViewport().add(ui_area_txt);

        ui_main_panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        ui_main_panel.add(ui_pane_scroll);
        this.add(ui_main_panel);
        this.add(ui_bar1_tools, BorderLayout.NORTH);

        this.setTitle("Open File Example");
        this.setSize(400, 300);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public String readFile(File file)
    {
        StringBuffer file_buffer = null;
        String file_string = null;
        String line = null;

        try {
            FileReader in = new FileReader(file);
            BufferedReader brd = new BufferedReader(in);
            file_buffer = new StringBuffer();

            while ((line = brd.readLine()) != null)
                file_buffer.append(line).append(System.getProperty("line.separator"));

            in.close();
            file_string = file_buffer.toString();
        }
        catch (IOException e) {
            return null;
        }

        return file_string;
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                OpenDialogExample ex = new OpenDialogExample();
                ex.setVisible(true);
            }
        });
    }
}
