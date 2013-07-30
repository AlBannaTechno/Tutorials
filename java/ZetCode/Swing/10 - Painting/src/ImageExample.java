import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


class DrawPanel6 extends JPanel
{
    Image img;

    public DrawPanel6(Image img)
    {
        this.img = img;
        Dimension dm = new Dimension(img.getWidth(null), img.getHeight(null));
        this.setPreferredSize(dm);
    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.drawImage(this.img, 0, 0, null);
    }
}


public class ImageExample extends JFrame
{
    public ImageExample()
    {
        Image img = new ImageIcon(ClassLoader.getSystemResource("IpIZs.jpg")).getImage();
        DrawPanel6 dpnl = new DrawPanel6(img);
        this.add(dpnl);
        this.pack();

        this.setTitle("Image");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                ImageExample ex = new ImageExample();
                ex.setVisible(true);
            }
        });
    }
}
