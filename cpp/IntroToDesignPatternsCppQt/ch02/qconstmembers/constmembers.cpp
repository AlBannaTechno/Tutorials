#include <QtCore/QTextStream>
#include <QtCore/QString>

class Point
{
public:
    Point(int px, int py)
        : _x(px), _y(py) { }
    void set(int nx, int ny)
    { _x = nx; _y = ny; }
    QString toString() const
    { ++_count; return QString("[%1, %2]").arg(_x).arg(_y); }

private:
    int _x;
    int _y;
    mutable int _count;
};

int main()
{
    QTextStream cout(stdout);
    Point p(1, 1);
    const Point q(2, 2);
    p.set(4, 4);
    cout << p.toString() << endl;
//  q.set(4, 4);  // error, q is a const
    cout << q.toString() << endl;

    return 0;
}
