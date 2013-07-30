// arrobj.cpp -- functions with array objects (C++11)
#include <iostream>
#include <array>
#include <string>

// constants
const int SEASONS = 4;
const std::array<std::string, SEASONS> SEASON_NAMES = {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(std::array<double, SEASONS> *pa);
// function that uses array object without modifying it
void show(std::array<double, SEASONS> da);

int main() {
    std::array<double, SEASONS> expenses;
    fill(&expenses);
    show(expenses);

    return 0;
}

void fill(std::array<double, SEASONS> *pa) {
    using namespace std;
    for (int i = 0; i < SEASONS; ++i) {
        cout << "Enter " << SEASON_NAMES[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, SEASONS> da) {
    using namespace std;
    double total = 0.0;

    cout << "\nEXPENSES:\n";
    for (int i = 0; i < SEASONS; ++i) {
        cout << SEASON_NAMES[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
