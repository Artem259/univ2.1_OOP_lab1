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

class Line //format: ax+by+c=0
{
private:
    double a,b,c;
public:
    Line(double _a, double _b, double _c);
    void set(double _a, double _b, double _c);
    void setA(double _a);
    void setB(double _b);
    void setC(double _c);
    double getA() const;
    double getB() const;
    double getC() const;
};

class Circle
{
private:
    Point center{};
    double radius;
public:
    Circle(Point _center, double _radius);
    explicit Circle(double _radius);
    void setCenter(Point _center);
    void serRadius(double _radius);
    Point getCenter() const;
    double getRadius() const;
};

//---------------------------------------------------------------------------------------------------------------//

Line::Line(double _a, double _b, double _c)
{
    assert(!(_a==0 && _b==0));
    a = _a;
    b = _b;
    c = _c;
}

void Line::set(double _a, double _b, double _c)
{
    assert(!(_a==0 && _b==0));
    a = _a;
    b = _b;
    c = _c;
}
void Line::setA(double _a)
{
    a = _a;
}
void Line::setB(double _b)
{
    b = _b;
}
void Line::setC(double _c)
{
    c = _c;
}

double Line::getA() const
{
    return a;
}
double Line::getB() const
{
    return b;
}
double Line::getC() const
{
    return c;
}

//---------------------------------------------------------------------------------------------------------------//

Circle::Circle(Point _center, double _radius)
{
    assert(_radius!=0);
    center = _center;
    radius = _radius;
}
Circle::Circle(double _radius)
{
    assert(_radius!=0);
    center = {0,0};
    radius = _radius;
}

void Circle::setCenter(Point _center)
{
    center = _center;
}
void Circle::serRadius(double _radius)
{
    radius = _radius;
}

Point Circle::getCenter() const
{
    return center;
}
double Circle::getRadius() const
{
    return radius;
}

#endif
