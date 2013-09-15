#ifndef _SUBOBJECT_H_
#define _SUBOBJECT_H_

#include <QtCore/QTextStream>

QTextStream cout(stdout);

class Point
{
public:
    Point(int xx, int yy)
        : _x(xx), _y(yy) { }
    ~Point()
    { cout << "Point destroyed: (" << _x << ", " << _y << ")\n"; }

private:
    int _x;
    int _y;
};

class Square
{
public:
    Square(int ulx, int uly, int lrx, int lry)
        : _upper_left(ulx, uly), _lower_right(lrx, lry) { }
    Square(const Point &ul, const Point &lr)
        : _upper_left(ul), _lower_right(lr) { }

private:
    Point _upper_left;
    Point _lower_right;
};

#endif
