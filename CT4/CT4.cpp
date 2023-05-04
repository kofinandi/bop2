#include <iostream>
using namespace std;

class Shape {
private:
	double xo, yo;
public:
	Shape(double x, double y) {
		xo = x;
		yo = y;
	}
	virtual double area() const = 0;
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double x, double y, double r) : Shape(x, y) {
		radius = r;
	}
	double area() const {
		return 3.14 * radius * radius;
	}
	double perimeter() const {
		return 2 * 3.14 * radius;
	}
};

class Cylinder : public Circle {
private:
	double height;
public:
	Cylinder(double x, double y, double r, double h) : Circle(x, y, r) {
		height = h;
	}
	double area() const{
		return 2 * Circle::area() + Circle::perimeter() * height;
	}
};

int main() {
	// Shape s1(0,0);      // this must result in compiler error
	Shape* shapes[3];
	shapes[0] = new Circle(0, 0, 1);
	shapes[1] = new Cylinder(0, 0, 3, 5);
	shapes[2] = new Circle(3, 3, 4);
	for (int i = 0; i < 3; i++)
		cout << shapes[i]->area() << endl;
	for (int i = 0; i < 3; i++)
		delete shapes[i];
	return 0;
}
