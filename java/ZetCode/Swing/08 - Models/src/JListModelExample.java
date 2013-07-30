import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.*;


public class JListModelExample extends JFrame
{
    private DefaultListModel model;
    private JList ui_movies_list;

    public JListModelExample()
    {
        model = new DefaultListModel();
        model.addElement("Amelie");
        model.addElement("Aguirre, der Zon Gottes");
        model.addElement("Fargo");
        model.addElement("Exorcist");
        model.addElement("Schindlers List");

        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(new BoxLayout(ui_main_panel, BoxLayout.X_AXIS));

        JPanel ui_left_panel = new JPanel();
        ui_left_panel.setLayout(new BorderLayout());

        JPanel ui_right_panel = new JPanel();
        ui_right_panel.setLayout(new BoxLayout(ui_right_panel, BoxLayout.Y_AXIS));

        ui_movies_list = new JList(model);
        ui_movies_list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        ui_movies_list.setBorder(BorderFactory.createEmptyBorder(2, 2, 2, 2));
        ui_movies_list.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    int index = ui_movies_list.locationToIndex(e.getPoint());
                    Object item = model.getElementAt(index);
                    String new_text = JOptionPane.showInputDialog("Rename Item", item);
                    String new_item = null;

                    if (new_text != null)
                        new_item = new_text.trim();
                    else
                        return;

                    if (!new_item.isEmpty()) {
                        model.remove(index);
                        model.add(index, new_item);
                        ListSelectionModel selmodel = ui_movies_list.getSelectionModel();
                        selmodel.setLeadSelectionIndex(index);
                    }
                }
            }
        });

        JScrollPane pane = new JScrollPane();
        pane.getViewport().add(ui_movies_list);

        ui_left_panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        ui_left_panel.add(pane);

        JButton ui_remove_all_btn = new JButton("Remove All");
        JButton ui_add_btn = new JButton("Add");
        ui_add_btn.setMaximumSize(ui_remove_all_btn.getMaximumSize());
        JButton ui_rename_btn = new JButton("Rename");
        ui_rename_btn.setMaximumSize(ui_remove_all_btn.getMaximumSize());
        JButton ui_delete_btn = new JButton("Delete");
        ui_delete_btn.setMaximumSize(ui_remove_all_btn.getMaximumSize());

        ui_remove_all_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                model.clear();
            }
        });

        ui_add_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String new_text = JOptionPane.showInputDialog("Add a new item");
                String new_item = null;

                if (new_text != null)
                    new_item = new_text.trim();
                else
                    return;

                if (!new_item.isEmpty())
                    model.addElement(new_item);
            }
        });

        ui_rename_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ListSelectionModel selmodel = ui_movies_list.getSelectionModel();
                int index = selmodel.getMinSelectionIndex();

                if (index == -1)
                    return;

                Object item = model.getElementAt(index);
                String new_text = JOptionPane.showInputDialog("Rename item", item);
                String new_item = null;

                if (new_text != null)
                    new_item = new_text.trim();
                else
                    return;

                if (!new_item.isEmpty()) {
                    model.remove(index);
                    model.add(index, new_item);
                }
            }
        });

        ui_delete_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ListSelectionModel selmodel = ui_movies_list.getSelectionModel();
                int index = selmodel.getMinSelectionIndex();

                if (index >= 0)
                    model.remove(index);
            }
        });

        ui_right_panel.add(ui_add_btn);
        ui_right_panel.add(Box.createRigidArea(new Dimension(0, 4)));
        ui_right_panel.add(ui_rename_btn);
        ui_right_panel.add(Box.createRigidArea(new Dimension(0, 4)));
        ui_right_panel.add(ui_delete_btn);
        ui_right_panel.add(Box.createRigidArea(new Dimension(0, 4)));
        ui_right_panel.add(ui_remove_all_btn);
        ui_right_panel.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 20));

        ui_main_panel.add(ui_left_panel);
        ui_main_panel.add(ui_right_panel);
        this.add(ui_main_panel);
        this.pack();

        this.setTitle("JList Model Example");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JListModelExample ex = new JListModelExample();
                ex.setVisible(true);
            }
        });
    }
}
