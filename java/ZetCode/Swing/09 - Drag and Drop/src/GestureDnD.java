import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.awt.dnd.DnDConstants;
import java.awt.dnd.DragGestureEvent;
import java.awt.dnd.DragGestureListener;
import java.awt.dnd.DragSource;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class GestureDnD extends JFrame implements DragGestureListener, Transferable
{
    public GestureDnD()
    {
        JPanel ui_main_panel = new JPanel(new FlowLayout(FlowLayout.LEFT, 50, 15));

        JPanel ui_left_panel = new JPanel();
        ui_left_panel.setBackground(Color.red);
        ui_left_panel.setPreferredSize(new Dimension(120, 120));

        DragSource ds = new DragSource();
        ds.createDefaultDragGestureRecognizer(ui_left_panel, DnDConstants.ACTION_COPY, this);

        ui_main_panel.add(ui_left_panel);
        this.add(ui_main_panel);
        this.pack();

        this.setTitle("Gesture Drag & Drop");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void dragGestureRecognized(DragGestureEvent event)
    {
        System.out.println("Drag Gesture");
        Cursor cursor = null;

        if (event.getDragAction() == DnDConstants.ACTION_COPY)
            cursor = DragSource.DefaultCopyDrop;

        event.startDrag(cursor, this);
    }

    @Override
    public Object getTransferData(DataFlavor flavor)
    {
        return null;
    }

    @Override
    public DataFlavor[] getTransferDataFlavors()
    {
        return new DataFlavor[0];
    }

    @Override
    public boolean isDataFlavorSupported(DataFlavor flavor)
    {
        return false;
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                GestureDnD ex = new GestureDnD();
                ex.setVisible(true);
            }
        });
    }
}
