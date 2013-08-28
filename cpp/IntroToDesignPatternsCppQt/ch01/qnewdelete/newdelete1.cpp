#include <QTextStream>

int main() {
    QTextStream cout(stdout);

    const char tab = '\t';
    int n = 13;
    int *p_i = new int(n + 3);
    double d = 3.14;
    double *p_d = new double(d + 2.3);
    char c = 'K';
    char *p_c = new char(c + 5);

    cout << *p_i << tab << *p_d << tab << *p_c << endl;  // output: 16 5.44 P

    int *p_i2 = p_i;
    cout << p_i << tab << p_i2 << endl;  // output: same memory addresses

    *p_i2 += 6;
    cout << *p_i << endl;  // output: 22

    delete p_i;
    cout << *p_i2 << endl;  // ERROR! p_i no longer exists! This will create a memory leak
    cout << p_i << tab << p_i2 << endl;  // output: the same memory addresses

    delete p_i;
    delete p_i2;
    delete p_d;
    delete p_c;

    return 0;
}
