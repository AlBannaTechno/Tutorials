#include <QTextStream>

int main() {
    QTextStream cout(stdout);

    int x = 4;
    int *p_x = 0;
    p_x = &x;

    cout << "x = " << x << " *p_x = " << *p_x << " p_x = " << p_x << " &p_x = " << &p_x << endl;
    x += 1;
    cout << "x = " << x << " *p_x = " << *p_x << " p_x = " << p_x << endl;
    *p_x += 1;
    cout << "x = " << x << " *p_x = " << *p_x << " p_x = " << p_x <<  endl;

    return EXIT_SUCCESS;
}
