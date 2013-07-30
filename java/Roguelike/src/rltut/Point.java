package rltut;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Point {
    public int x;
    public int y;
    public int z;

    public Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;

        Point point = (Point) obj;

        if (x != point.x) return false;
        if (y != point.y) return false;
        if (z != point.z) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        result = 31 * result + z;
        return result;
    }

    public List<Point> neighbors8() {
        List<Point> points = new ArrayList<>();

        for (int ox = -1; ox < 2; ox++)
        for (int oy = -1; oy < 2; oy++) {
            if (ox == 0 && oy == 0)
                continue;
            points.add(new Point(x + ox, y + oy, z));
        }

        Collections.shuffle(points);
        return points;
    }
}
