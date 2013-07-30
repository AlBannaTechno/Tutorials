// file2.cpp -- contains functions called in file1.cpp
#include <iostream>
#include <cmath>
#include "coordin.h"  // structure templates, function prototypes


// convert rectangular to polar coordinates
polar rect_to_polar(rect xypos) {
    using namespace std;
    polar answer;

    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);

    return answer;  // returns a polar structure
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos) {
    using namespace std;
    const double RAD_TO_DEG = 57.29577951;

    cout << "distance = " << dapos.distance << ", angle = " << dapos.angle * RAD_TO_DEG
         << " degrees\n";
}
