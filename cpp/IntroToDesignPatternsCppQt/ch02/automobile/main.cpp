#include "hondurato.h"
#include <iostream>

int main()
{
    Hondurato car1(20, 0, 20, 25);
    Hondurato car2(7, 20000, 18, 20);
    Hondurato car3(10, 120000, 15, 20);

    std::cout << "-- Car 1 --\nFuel: " << car1.get_fuel() << "/" << car1.get_tank_capacity() << "\n"
              << "Odometer: " << car1.get_odometer() << ", MPG: " << car1.get_mpg() << "\n";
    std::cout << "-- Car 2 --\nFuel: " << car2.get_fuel() << "/" << car2.get_tank_capacity() << "\n"
              << "Odometer: " << car2.get_odometer() << ", MPG: " << car2.get_mpg() << "\n";
    std::cout << "-- Car 3 --\nFuel: " << car3.get_fuel() << "/" << car3.get_tank_capacity() << "\n"
              << "Odometer: " << car3.get_odometer() << ", MPG: " << car3.get_mpg() << "\n";

    std::cout << "\nCar 1 drives at 60mph for 45 minutes to it's destination.\nIt has "
              << car1.drive(60, 45) << " gallons of fuel left.\n";
    std::cout << "Car 2 drives at 80mph for 1 hour and 20 minutes to it's destination.\nIt has "
              << car2.drive(80, 80) << " gallons of fuel left.\n";
    std::cout << "Car 3 drives at 30mph for 30 minutes to it's destination.\nIt has "
              << car3.drive(30, 30) << " gallons of fuel left.\n";

    std::cout << "Car 2 fuels up, it now has " << car2.addFuel(5) << " gallons in it's tank.\n";
    std::cout << "Car 3 fuels up, it now has " << car3.addFuel(0) << " gallons in it's tank.\n";

    return 0;
}
