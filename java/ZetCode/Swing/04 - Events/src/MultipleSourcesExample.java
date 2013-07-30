import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.border.EtchedBorder;


public class MultipleSourcesExample extends JFrame
{
    JLabel ui_statusbar;
    
    public MultipleSourcesExample()
    {
        this.initUi();
    }
    
    public final void initUi()
    {
        JPanel ui_main_panel = new JPanel();
        ui_main_panel.setLayout(null);
        
        ui_statusbar = new JLabel(" ZetCode");
        ui_statusbar.setBorder(BorderFactory.createEtchedBorder(EtchedBorder.RAISED));
        
        JButton ui_close_btn = new JButton("Close");
        ui_close_btn.setBounds(40, 30, 80, 25);
        ui_close_btn.addActionListener(new ButtonListener());
        
        JButton ui_open_btn = new JButton("Open");
        ui_open_btn.setBounds(40, 80, 80, 25);
        ui_open_btn.addActionListener(new ButtonListener());
        
        JButton ui_find_btn = new JButton("Find");
        ui_find_btn.setBounds(40, 130, 80, 25);
        ui_find_btn.addActionListener(new ButtonListener());
        
        JButton ui_save_btn = new JButton("Save");
        ui_save_btn.setBounds(40, 180, 80, 25);
        ui_save_btn.addActionListener(new ButtonListener());
        
        ui_main_panel.add(ui_close_btn);
        ui_main_panel.add(ui_open_btn);
        ui_main_panel.add(ui_find_btn);
        ui_main_panel.add(ui_save_btn);
        
        this.add(ui_main_panel);
        this.add(ui_statusbar, BorderLayout.SOUTH);

        this.setTitle("Multiple Sources Example");
        this.setSize(400, 300);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class ButtonListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            JButton obj = (JButton) e.getSource();
            String label = obj.getText();
            ui_statusbar.setText(" " + label + " button clicked");
        }
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                MultipleSourcesExample ex = new MultipleSourcesExample();
                ex.setVisible(true);
            }
        });
    }
}
