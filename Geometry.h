#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Point;
class Line;
class Circle;

//---------------------------------------------------------------------------------------------------------------//

struct Point
{
    double x;
    double y;
};

class Line
{
private:

public:

};

class Circle
{
private:
    Point center;
    double radius;
public:
    Circle(Point center, double radius);
    explicit Circle(double radius);
};

//---------------------------------------------------------------------------------------------------------------//

Circle::Circle(Point center, double radius)
{
    this->center = center;
    this->radius = radius;
}

Circle::Circle(double radius)
{
    this->center = {0,0};
    this->radius = radius;
}

#endif
