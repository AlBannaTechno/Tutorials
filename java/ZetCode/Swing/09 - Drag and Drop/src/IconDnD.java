import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.TransferHandler;


public class IconDnD extends JFrame
{
    public IconDnD()
    {
        JPanel ui_main_panel = new JPanel(new FlowLayout(FlowLayout.LEFT, 50, 15));

        ImageIcon sad_icon = new ImageIcon(this.getClass().getResource("smiley-sad.png"));
        ImageIcon face_icon = new ImageIcon(this.getClass().getResource("smiley-neutral.png"));
        ImageIcon cry_icon = new ImageIcon(this.getClass().getResource("smiley-cry.png"));

        JButton ui_face_btn = new JButton(face_icon);
        ui_face_btn.setFocusable(false);
        ui_face_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JButton source = (JButton) e.getSource();
                ImageIcon close_icon = new ImageIcon(this.getClass().getResource("smiley-cry.png"));
                if (source.getIcon().toString().equals(close_icon.toString()))
                    System.exit(0);
            }
        });

        JLabel ui_sad_lbl = new JLabel(sad_icon, JLabel.CENTER);
        JLabel ui_cry_lbl = new JLabel(cry_icon, JLabel.CENTER);

        MouseListener listener = new DragMouseAdapter();
        ui_sad_lbl.addMouseListener(listener);
        ui_cry_lbl.addMouseListener(listener);

        ui_sad_lbl.setTransferHandler(new TransferHandler("icon"));
        ui_face_btn.setTransferHandler(new TransferHandler("icon"));
        ui_cry_lbl.setTransferHandler(new TransferHandler("icon"));

        ui_main_panel.add(ui_sad_lbl);
        ui_main_panel.add(ui_face_btn);
        ui_main_panel.add(ui_cry_lbl);
        this.add(ui_main_panel);
        this.pack();

        this.setTitle("Icon Drag & Drop");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class DragMouseAdapter extends MouseAdapter
    {
        @Override
        public void mousePressed(MouseEvent e)
        {
            JComponent source = (JComponent) e.getSource();
            TransferHandler handler = source.getTransferHandler();
            handler.exportAsDrag(source, e, TransferHandler.COPY);
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                IconDnD ex = new IconDnD();
                ex.setVisible(true);
            }
        });
    }
}
