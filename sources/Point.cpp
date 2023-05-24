#include "Point.hpp"

namespace ariel
{

    // Default constructor
    Point::Point() : value_x(0), value_y(0) {}

    // Constructor with x and y values
    Point::Point(double value_x, double value_y) : value_x(value_x), value_y(value_y) {}

    // Destructor
    Point::~Point(void) {}

    // Getter and Setter
    double Point::getx() const
    {
        return value_x;
    }

    double Point::gety() const
    {
        return value_y;
    }

    void Point::setx(double value_x)
    {
        this->value_x = value_x;
    }

    void Point::sety(double value_y)
    {
        this->value_y = value_y;
    }

    // Functions
    double Point::distance(Point other)
    {
        return sqrt(pow(value_x - other.value_x, 2) + pow(value_y - other.value_y, 2));
    }

    string Point::print()
    {
        stringstream ss;
        ss << "(" << value_x << ", " << value_y << ")";
        return ss.str();
    }

    Point Point::moveTowards(Point point_s, Point point_t, double dis)
    {
        if (dis < 0)
        {
            throw std::invalid_argument("the distance cannot be negative!");
        }

        double total_distance = point_s.distance(point_t);
        if (dis >= total_distance)
        {
            return point_t;
        }
        double ratio = dis / total_distance;
        double new_x = point_s.value_x + (point_t.value_x - point_s.value_x) * ratio;
        double new_y = point_s.value_y + (point_t.value_y - point_s.value_y) * ratio;
        return Point(new_x, new_y);
    }

    Point &Point::operator=(const Point &other)
    {
        if (this != &other)
        {
            value_x = other.value_x;
            value_y = other.value_y;
        }
        return *this;
    }

    bool Point::operator==(const Point &other) const
    {
        return value_x == other.value_x && value_y == other.value_y;
    }

}
