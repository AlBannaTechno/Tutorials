import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


class DrawPanel4 extends JPanel
{
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);

        Graphics2D g2d = (Graphics2D) g;

        GradientPaint gp1 = new GradientPaint(5, 5, Color.red, 20, 20, Color.black, true);
        g2d.setPaint(gp1);
        g2d.fillRect(20, 20, 300, 40);

        GradientPaint gp2 = new GradientPaint(5, 25, Color.yellow, 20, 2, Color.black, true);
        g2d.setPaint(gp2);
        g2d.fillRect(20, 80, 300, 40);

        GradientPaint gp3 = new GradientPaint(5, 25, Color.green, 2, 2, Color.black, true);
        g2d.setPaint(gp3);
        g2d.fillRect(20, 140, 300, 40);

        GradientPaint gp4 = new GradientPaint(5, 25, Color.blue, 15, 25, Color.black, true);
        g2d.setPaint(gp4);
        g2d.fillRect(20, 200, 300, 40);

        GradientPaint gp5 = new GradientPaint(0, 0, Color.orange, 0, 20, Color.black, true);
        g2d.setPaint(gp5);
        g2d.fillRect(20, 260, 300, 40);
    }
}


public class GradientExample extends JFrame
{
    public GradientExample()
    {
        DrawPanel4 ui_draw_panel = new DrawPanel4();
        this.add(ui_draw_panel);

        this.setTitle("Gradients");
        this.setSize(350, 350);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                GradientExample ex = new GradientExample();
                ex.setVisible(true);
            }
        });
    }
}
