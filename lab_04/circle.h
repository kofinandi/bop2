#pragma once

class Circle {
private:
	double radius;

public:
Circle(double radius = 0);
	double getRadius() const;
	double getPerimeter() const;
	double getArea() const;
	void print() const;
};;