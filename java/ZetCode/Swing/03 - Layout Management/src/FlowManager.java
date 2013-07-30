import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTree;
import javax.swing.SwingUtilities;


public class FlowManager extends JFrame
{
    public FlowManager()
    {
        initUi();
    }

    public final void initUi()
    {
        JPanel panel = new JPanel();

        JTextArea area = new JTextArea("Text Area");
        area.setPreferredSize(new Dimension(100, 100));

        JButton new_btn = new JButton("Button");
        panel.add(new_btn);

        JTree tree = new JTree();
        panel.add(tree);
        panel.add(area);

        this.add(panel);
        this.pack();

        this.setTitle("FlowLayout");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                FlowManager ex = new FlowManager();
                ex.setVisible(true);
            }
        });
    }
}
