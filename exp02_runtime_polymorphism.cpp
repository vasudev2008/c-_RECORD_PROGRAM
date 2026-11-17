#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};
class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
};
class Rectangle : public Shape {
    double length, breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double area() const override { return length * breadth; }
};
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
};
int main() {
    Circle c(5); Rectangle r(4, 6); Triangle t(10, 8);
    Shape* ptr = &c; cout << "Area of Circle: " << ptr->area() << '\n';
    ptr = &r; cout << "Area of Rectangle: " << ptr->area() << '\n';
    ptr = &t; cout << "Area of Triangle: " << ptr->area() << '\n';
}
