#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <string>
#include <cassert>
#include <cmath>

struct Point;
class Line;
class Circle;

//---------------------------------------------------------------------------------------------------------------//

struct Point
{
    double x = 0;
    double y = 0;

    friend bool operator ==(const Point &first, const Point &second);
    friend bool operator !=(const Point &first, const Point &second);
};

class Line
{
private:
    double a,b,c; //format: ax+by+c=0

    Line getNormal(const Point &point) const;
public:
    Line(); //y-x=0
    Line(const Line &line);
    Line(double _a, double _b, double _c);
    Line(double _k, double _b); //y=kx+b => -kx+y-b=0
    Line(const Point &first, const Point &second);
    void set(double _a, double _b, double _c);
    void set(double _k, double _b); //y=kx+b => -kx+y-b=0
    void set(const Point &first, const Point &second);
    void setA(double _a);
    void setB(double _b);
    void setC(double _c);
    double getA() const;
    double getB() const;
    double getC() const;

    friend double getAngle(const Line &first, const Line &second);
    friend double getAngle(const Line &line, const Circle &circle);
    friend double getAngle(const Circle &circle, const Line &line);
    friend Point operator &&(const Line &first, const Line &second);
    friend std::vector<Point> operator &&(const Line &line, const Circle &circle);
    friend std::vector<Point> operator &&(const Circle &circle, const Line &line);
    friend std::vector<Point> operator &&(const Circle &first, const Circle &second);
};

class Circle
{
private:
    Point center{};
    double radius;

    Line getTangent(const Point &point) const;
public:
    Circle(); //(x2)+(y2)=1
    Circle(const Circle &circle);
    Circle(Point _center, double _radius);
    explicit Circle(double _radius);
    void setCenter(Point _center);
    void setRadius(double _radius);
    Point getCenter() const;
    double getRadius() const;

    friend double getAngle(const Circle &first, const Circle &second);
    friend double getAngle(const Line &line, const Circle &circle);
    friend double getAngle(const Circle &circle, const Line &line);
    friend std::vector<Point> operator &&(const Circle &first, const Circle &second);
    friend std::vector<Point> operator &&(const Line &line, const Circle &circle);
    friend std::vector<Point> operator &&(const Circle &circle, const Line &line);
};

//---------------------------------------------------------------------------------------------------------------//
// functions related to struct Point

bool operator ==(const Point &first, const Point &second)
{
    return (first.x==second.x && first.y==second.y);
}
bool operator !=(const Point &first, const Point &second)
{
    return !(first==second);
}

//---------------------------------------------------------------------------------------------------------------//
// functions related to class Line

Line::Line()
{
    a = -1;
    b = 1;
    c = 0;
}
Line::Line(const Line &line)
{
    a = line.a;
    b = line.b;
    c = line.c;
}
Line::Line(double _a, double _b, double _c)
{
    assert(_b!=0);
    a = _a;
    b = _b;
    c = _c;
}
Line::Line(double _k, double _b)
{
    assert(_k!=0);
    a = -_k;
    b = 1;
    c = -_b;
}
Line::Line(const Point &first, const Point &second)
{
    assert(first.x!=second.x);
    a = second.y-first.y;
    b = first.x-second.x;
    c = first.y*second.x-first.x*second.y;
}

void Line::set(double _a, double _b, double _c)
{
    assert(_b!=0);
    a = _a;
    b = _b;
    c = _c;
}
void Line::set(double _k, double _b)
{
    assert(_k != 0);
    a = -_k;
    b = 1;
    c = -_b;
}
void Line::set(const Point &first, const Point &second)
{
    assert(first.x!=second.x);
    a = second.y-first.y;
    b = first.x-second.x;
    c = first.y*second.x-first.x*second.y;
}
void Line::setA(double _a)
{
    a = _a;
}
void Line::setB(double _b)
{
    assert(_b!=0);
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

Line Line::getNormal(const Point &point) const
{
    Line res;
    res.setA(-b);
    res.setB(a);
    res.setC(b*point.x-a*point.y);
    return res;
}
double getAngle(const Line &first, const Line &second)
{
    if(first.a==second.a && first.b==second.b) return -1;
    return abs(atan(-(first.a/first.b))-atan((-(second.a/second.b))));
}
Point operator &&(const Line &first, const Line &second)
{
    assert(!(first.a==second.a && first.b==second.b));
    Point res;
    res.x = (second.b*first.c-first.b*second.c)/(second.a*first.b-first.a*second.b);
    res.y = -(first.a/first.b)*res.x-(first.c/first.b);
    return res;
}

//---------------------------------------------------------------------------------------------------------------//
// functions related to class Circle

Circle::Circle()
{
    center = {0,0};
    radius = 1;
}
Circle::Circle(const Circle &circle)
{
    center = circle.center;
    radius = circle.radius;
}
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
void Circle::setRadius(double _radius)
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

Line Circle::getTangent(const Point &point) const
{
    Line res;
    res.setA(point.x-center.x);
    res.setB(point.y-center.y);
    res.setC(center.x*center.x+center.y*center.y-radius*radius-center.y*point.y-center.x*point.x);
    return res;
}
std::vector<Point> operator &&(const Circle &first, const Circle &second)
{
    assert(!(first.center==second.center && first.radius==second.radius));
    Line line(first.center, second.center);
    return (line.getNormal({(first.center.x+second.center.x)/2, (first.center.y+second.center.y)/2}) && first);
}

//---------------------------------------------------------------------------------------------------------------//
// additional functions

double getAngle(const Line &line, const Circle &circle)
{
    std::vector<Point> points = line && circle;
    if(points.empty()) return -1;
    return getAngle(line, circle.getTangent(points[0]));
}
double getAngle(const Circle &circle, const Line &line)
{
    return getAngle(line, circle);
}
double getAngle(const Circle &first, const Circle &second)
{
    std::vector<Point> points = first && second;
    if(points.empty()) return -1;
    return getAngle(first.getTangent(points[0]), second.getTangent(points[0]));
}
std::vector<Point> operator &&(const Line &line, const Circle &circle)
{
    std::vector<Point> res;
    double a = line.a, b = line.b, c = line.c;
    double x = circle.center.x, y = circle.center.y, r = circle.radius;
    double a2 = a*a, b2 = b*b, c2 = c*c;
    double x2 = x*x, y2 = y*y, r2 = r*r;
    //A(x2)+B(x)+C=0
    double A = a2+b2;
    double B = 2*(a*b*y+a*c-b2*x);
    double C = b2*x2+b2*y2+2*b*c*y+c2-r2*b2;
    double D = B*B-4*A*C; //D=b2-4ac
    if(D<0) return {};
    double sqrtD = sqrt(D);
    double X1 = (-B+sqrtD)/(2*A);
    double X2 = (-B-sqrtD)/(2*A);
    double Y1 = -(a/b)*X1-(c/b);
    double Y2 = -(a/b)*X2-(c/b);
    res.push_back({X1,Y1});
    if(D==0) return res;
    res.push_back({X2,Y2});
    return res;
}
std::vector<Point> operator &&(const Circle &circle, const Line &line)
{
    return (line && circle);
}

#endif
