#include "hondurato.h"

Hondurato::Hondurato(double fuel, double odom, double capacity, double mpg)
    : _fuel(fuel), _odometer(odom), _tank_capacity(capacity), _mpg(mpg), _speed(0)
{ }

double Hondurato::addFuel(double gal)
{
    _fuel += gal;
    if (gal == 0 || _fuel > _tank_capacity)
        _fuel = _tank_capacity;

    return _fuel;
}

double Hondurato::drive(double speed, int minutes)
{
    if (_fuel == 0)
        return _fuel;

    double distance = speed * (minutes / 60.0);
    _odometer += distance;
    _fuel -= distance / _mpg;

    if (_fuel < 0)
        _fuel = 0;

    return _fuel;
}

double Hondurato::highwayDrive(double distance, double speed_limit)
{

}

double Hondurato::get_fuel() const
{
    return _fuel;
}

double Hondurato::get_odometer() const
{
    return _odometer;
}

double Hondurato::get_tank_capacity() const
{
    return _tank_capacity;
}

double Hondurato::get_mpg() const
{
    return _mpg;
}

double Hondurato::get_speed() const
{
    return _speed;
}
