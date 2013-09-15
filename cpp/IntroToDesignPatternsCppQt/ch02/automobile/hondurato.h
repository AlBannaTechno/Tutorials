#ifndef _HONDURATO_H_
#define _HONDURATO_H_

class Hondurato
{
public:
    Hondurato(double fuel, double odom, double capacity, double mpg);

    double addFuel(double gal);
    double drive(double speed, int minutes);
    double highwayDrive(double distance, double speed_limit);

    double get_fuel() const;
    double get_odometer() const;
    double get_tank_capacity() const;
    double get_mpg() const;
    double get_speed() const;

private:
    double _fuel;
    double _odometer;
    double _tank_capacity;
    double _mpg;
    double _speed;
};

#endif
