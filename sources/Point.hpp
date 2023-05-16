/**
 * Header file of class "Point"
 */
#ifndef Point_HPP
#define Point_HPP
#include <iostream>

#include <iostream>
// using namespace std;
namespace ariel
{

    class Point
    {
        double _x, _y;

    public:
        Point() { _x = _y = 0; }   // inline constructor
        Point(double x, double y); // "outline" constructor

        // inline method

        // string to_string() {
        //     return std::to_string(re)+"+"+std::to_string(im)+"i";
        // }

        // "outline" method

        double distance(const Point b);
        std::string print();
        Point moveTowards(const Point &source, const Point &target, double distance);

        /*getter*/
        double getX() const
        {
            return _x;
        }
        double getY() const
        {
            return _y;
        }
    };
}
#endif