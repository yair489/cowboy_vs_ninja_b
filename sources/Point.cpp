/**
 * Implementation file of class "Point"
 */
#include <cmath>
#include <iostream>
#include "Point.hpp"
using namespace ariel;

// "outline" constructor implementation:
Point::Point(double x, double y)
{
    (*this)._x = x;
    this->_y = y;
}

// "outline" method implementation:

double Point::distance(const Point b)
{

    double dx = this->_x - b._x;
    double dy = this->_y - b._y;
    return std::sqrt(dx * dx + dy * dy);
}
std::string Point::print()
{
    return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
}

Point Point::moveTowards(const Point &source, const Point &target, double distance)
{

    double dx = target._x - source._x;
    double dy = target._y - source._y;
    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist <= distance)
    {
        return target; // target is already reachable
    }
    double ratio = distance / dist;
    double x = source._x + dx * ratio;
    double y = source._y + dy * ratio;
    return Point(x, y);
}
