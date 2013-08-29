#include <cassert>

int param_size;

void bar(int *integers);
int *foo(int arrayparameter[]);

int main() {
    int intarray2[40] = {9, 9, 9, 9, 9, 9, 9, 2, 1};
    char chararray[20] = "Hello World";
    int intarray1[20];
    int *retval;

//  intarray1 = foo(intarray2);
    retval = foo(intarray2);
    assert(retval[2] == 3);
    assert(retval[2] == intarray2[2]);
    assert(retval == intarray2);

    int ref_size = sizeof(intarray2);
    assert(ref_size == param_size);

    return 0;
}

void bar(int *integers) {
    integers[2] = 3;
}

int *foo(int arrayparameter[]) {
    param_size = sizeof(arrayparameter);
    bar(arrayparameter);

    return arrayparameter;
}
