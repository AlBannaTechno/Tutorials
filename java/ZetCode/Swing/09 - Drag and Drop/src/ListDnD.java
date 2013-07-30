import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;

import javax.swing.DefaultListModel;
import javax.swing.DropMode;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SwingUtilities;
import javax.swing.TransferHandler;


public class ListDnD extends JFrame
{
    JTextField ui_display_txt;
    DefaultListModel model;

    public ListDnD()
    {
        JPanel ui_main_panel = new JPanel(new FlowLayout(FlowLayout.LEFT, 15, 15));

        JScrollPane ui_text_spane = new JScrollPane();
        ui_text_spane.setPreferredSize(new Dimension(180, 150));

        model = new DefaultListModel();
        JList ui_info_list = new JList(model);

        ui_info_list.setDropMode(DropMode.INSERT);
        ui_info_list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        ui_info_list.setTransferHandler(new ListHandler());

        ui_display_txt = new JTextField("");
        ui_display_txt.setPreferredSize(new Dimension(150, 25));
        ui_display_txt.setDragEnabled(true);

        ui_main_panel.add(ui_display_txt);
        ui_text_spane.getViewport().add(ui_info_list);
        ui_main_panel.add(ui_text_spane);
        this.add(ui_main_panel);
        this.pack();

        this.setTitle("List Drag & Drop");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private class ListHandler extends TransferHandler
    {
        @Override
        public boolean canImport(TransferSupport support)
        {
            return support.isDrop() && support.isDataFlavorSupported(DataFlavor.stringFlavor);
        }

        @Override
        public boolean importData(TransferSupport support)
        {
            if (!this.canImport(support))
                return false;

            Transferable trans = support.getTransferable();
            String line;

            try {
                line = (String) trans.getTransferData(DataFlavor.stringFlavor);
            }
            catch (Exception e) {
                return false;
            }

            JList.DropLocation dl = (JList.DropLocation) support.getDropLocation();
            int index = dl.getIndex();

            String[] data = line.split(",");

            for (String item: data) {
                if (!item.isEmpty())
                    model.add(index++, item.trim());

                if (item.trim().equals("Close"))
                    System.exit(0);
            }

            return true;
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                ListDnD ex = new ListDnD();
                ex.setVisible(true);
            }
        });
    }
}
