import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.TexturePaint;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class TexturesExample extends JPanel
{
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);

        Graphics2D g2d = (Graphics2D) g;

        g2d.setColor(new Color(212, 212, 212));
        g2d.drawRect(10, 15, 90, 60);
        g2d.drawRect(130, 15, 90, 60);
        g2d.drawRect(250, 15, 90, 60);
        g2d.drawRect(10, 105, 90, 60);
        g2d.drawRect(130, 105, 90, 60);
        g2d.drawRect(250, 105, 90, 60);

        BufferedImage bimg1 = null;
        BufferedImage bimg2 = null;
        BufferedImage bimg3 = null;
        BufferedImage bimg4 = null;
        BufferedImage bimg5 = null;
        BufferedImage bimg6 = null;

        URL url1 = ClassLoader.getSystemResource("texture1.png");
        URL url2 = ClassLoader.getSystemResource("texture2.png");
        URL url3 = ClassLoader.getSystemResource("texture3.png");
        URL url4 = ClassLoader.getSystemResource("texture4.png");
        URL url5 = ClassLoader.getSystemResource("texture5.png");
        URL url6 = ClassLoader.getSystemResource("texture6.png");

        try {
            bimg1 = ImageIO.read(url1);
            bimg2 = ImageIO.read(url2);
            bimg3 = ImageIO.read(url3);
            bimg4 = ImageIO.read(url4);
            bimg5 = ImageIO.read(url5);
            bimg6 = ImageIO.read(url6);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        Rectangle rect1 = new Rectangle(0, 0, bimg1.getWidth(), bimg1.getHeight());
        Rectangle rect2 = new Rectangle(0, 0, bimg2.getWidth(), bimg2.getHeight());
        Rectangle rect3 = new Rectangle(0, 0, bimg3.getWidth(), bimg3.getHeight());
        Rectangle rect4 = new Rectangle(0, 0, bimg4.getWidth(), bimg4.getHeight());
        Rectangle rect5 = new Rectangle(0, 0, bimg5.getWidth(), bimg5.getHeight());
        Rectangle rect6 = new Rectangle(0, 0, bimg6.getWidth(), bimg6.getHeight());

        TexturePaint texture1 = new TexturePaint(bimg1, rect1);
        TexturePaint texture2 = new TexturePaint(bimg2, rect2);
        TexturePaint texture3 = new TexturePaint(bimg3, rect3);
        TexturePaint texture4 = new TexturePaint(bimg4, rect4);
        TexturePaint texture5 = new TexturePaint(bimg5, rect5);
        TexturePaint texture6 = new TexturePaint(bimg6, rect6);

        g2d.setPaint(texture1);
        g2d.fillRect(10, 15, 90, 60);

        g2d.setPaint(texture2);
        g2d.fillRect(130, 15, 90, 60);

        g2d.setPaint(texture3);
        g2d.fillRect(250, 15, 90, 60);

        g2d.setPaint(texture4);
        g2d.fillRect(10, 105, 90, 60);

        g2d.setPaint(texture5);
        g2d.fillRect(130, 105, 90, 60);

        g2d.setPaint(texture6);
        g2d.fillRect(250, 105, 90, 60);
    }

    public static void main(String[] args)
    {
        TexturesExample rects = new TexturesExample();
        JFrame frame = new JFrame("Textures");

        frame.add(rects);
        frame.setSize(360, 210);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setVisible(true);
    }
}
