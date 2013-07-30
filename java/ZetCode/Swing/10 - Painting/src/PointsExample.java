import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


class DrawPanel extends JPanel
{
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(Color.blue);

        for (int i = 0; i <= 1000; i++) {
            Dimension size = this.getSize();
            Insets insets = this.getInsets();

            int w = size.width - insets.left - insets.right;
            int h = size.height - insets.top - insets.bottom;

            Random rand = new Random();
            int x = Math.abs(rand.nextInt()) % w;
            int y = Math.abs(rand.nextInt()) % h;

            g2d.drawLine(x, y, x, y);
        }
    }
}


public class PointsExample extends JFrame
{
    public PointsExample()
    {
        DrawPanel ui_draw_panel = new DrawPanel();
        this.add(ui_draw_panel);

        this.setTitle("Draw Random Points");
        this.setSize(250, 200);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                PointsExample ex = new PointsExample();
                ex.setVisible(true);
            }
        });
    }
}
