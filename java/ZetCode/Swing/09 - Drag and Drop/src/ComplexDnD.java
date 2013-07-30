import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.dnd.DnDConstants;
import java.awt.dnd.DragGestureEvent;
import java.awt.dnd.DragGestureListener;
import java.awt.dnd.DragSource;
import java.awt.dnd.DropTarget;
import java.awt.dnd.DropTargetAdapter;
import java.awt.dnd.DropTargetDropEvent;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class ComplexDnD extends JFrame implements DragGestureListener
{
    JPanel ui_main_panel;
    JPanel ui_left_panel;

    public ComplexDnD()
    {
        ui_main_panel = new JPanel(new FlowLayout(FlowLayout.LEFT, 50, 15));

        JButton ui_open_btn = new JButton("Choose Color");
        ui_open_btn.setFocusable(false);

        ui_left_panel = new JPanel();
        ui_left_panel.setBackground(Color.red);
        ui_left_panel.setPreferredSize(new Dimension(100, 100));

        ui_open_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Color color = JColorChooser.showDialog(ui_main_panel, "Choose Color", Color.white);
                ui_left_panel.setBackground(color);
            }
        });

        JPanel ui_right_panel = new JPanel();
        ui_right_panel.setBackground(Color.white);
        ui_right_panel.setPreferredSize(new Dimension(100, 100));

        new CustDropTargetListener(ui_right_panel);
        DragSource ds = new DragSource();
        ds.createDefaultDragGestureRecognizer(ui_left_panel, DnDConstants.ACTION_COPY, this);

        ui_main_panel.add(ui_open_btn);
        ui_main_panel.add(ui_left_panel);
        ui_main_panel.add(ui_right_panel);
        this.add(ui_main_panel);
        this.pack();

        this.setTitle("Complex Drag & Drop");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void dragGestureRecognized(DragGestureEvent event)
    {
        Cursor cursor = null;
        JPanel source = (JPanel) event.getComponent();
        Color color = source.getBackground();

        if (event.getDragAction() == DnDConstants.ACTION_COPY)
            cursor = DragSource.DefaultCopyDrop;

        event.startDrag(cursor, new TransferableColor(color));
    }

    class CustDropTargetListener extends DropTargetAdapter
    {
        private DropTarget drop_target;
        private JPanel source;

        public CustDropTargetListener(JPanel source)
        {
            this.source = source;

            drop_target = new DropTarget(source, DnDConstants.ACTION_COPY, this, true, null);
        }

        @Override
        public void drop(DropTargetDropEvent event)
        {
            try {
                Transferable trans = event.getTransferable();
                Color color = (Color) trans.getTransferData(TransferableColor.color_flavor);

                if (event.isDataFlavorSupported(TransferableColor.color_flavor)) {
                    event.acceptDrop(DnDConstants.ACTION_COPY);
                    this.source.setBackground(color);
                    event.dropComplete(true);

                    if (color.equals(Color.green))
                        System.exit(0);

                    return;
                }

                event.rejectDrop();
            }
            catch (Exception e) {
                e.printStackTrace();
                event.rejectDrop();
            }
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                ComplexDnD ex = new ComplexDnD();
                ex.setVisible(true);
            }
        });
    }
}


class TransferableColor implements Transferable
{
    protected static DataFlavor color_flavor = new DataFlavor(Color.class, "A Color Object");
    protected static DataFlavor[] supported_flavors = { color_flavor, DataFlavor.stringFlavor, };
    Color color;

    public TransferableColor(Color color)
    {
        this.color = color;
    }

    @Override
    public DataFlavor[] getTransferDataFlavors()
    {
        return supported_flavors;
    }

    @Override
    public boolean isDataFlavorSupported(DataFlavor flavor)
    {
        return flavor.equals(color_flavor) || flavor.equals(DataFlavor.stringFlavor);
    }

    @Override
    public Object getTransferData(DataFlavor flavor) throws UnsupportedFlavorException
    {
        if (flavor.equals(color_flavor))
            return color;
        else if (flavor.equals(DataFlavor.stringFlavor))
            return color.toString();
        else
            throw new UnsupportedFlavorException(flavor);
    }
}
