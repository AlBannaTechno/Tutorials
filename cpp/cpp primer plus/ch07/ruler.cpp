// ruler.cpp -- using recursion to subdivide a ruler
#include <iostream>

const int LEN = 66;
const int DIVS = 6;

void subdivide(char arr[], int low, int high, int level);

int main() {
    char ruler[LEN];
    int i;

    for (i = 1; i < LEN-2; ++i)
        ruler[i] = ' ';
    ruler[LEN-1] = '\0';

    int max = LEN - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';

    std::cout << ruler << std::endl;
    for (i = 1; i <= DIVS; ++i) {
        subdivide(ruler, min, max, i);
        std::cout << ruler << std::endl;
        for (int j = 1; j < LEN-2; ++j)
            ruler[j] = ' ';  // reset to blank ruler
    }

    return 0;
}

void subdivide(char arr[], int low, int high, int level) {
    if (level == 0)
        return;

    int mid = (high + low) / 2;
    arr[mid] = '|';
    subdivide(arr, low, mid, level-1);
    subdivide(arr, mid, high, level-1);
}
