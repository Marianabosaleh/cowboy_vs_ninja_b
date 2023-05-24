#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
namespace ariel
{
    class Point
    {
        double value_x;
        double value_y;

    public:
        // constructors
        Point();
        Point(double value_x, double value_y);
        // destructor
        virtual ~Point(void);
        // Getter and Setter
        double getx() const;
        double gety() const;
        void setx(double value_x);
        void sety(double value_y);
        // functions
        double distance(Point other);
        string print();
        static Point moveTowards(Point point_s, Point point_t, double dis);
        Point& operator=(const Point& other);
        bool operator==(const Point& other) const;
    };
}