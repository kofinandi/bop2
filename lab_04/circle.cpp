#include "circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(double r) {
	radius = std::abs(r);
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getPerimeter() const {
	return 2 * 3.14 * radius;
}

double Circle::getArea() const {
	return 3.14 * radius * radius;
}

void Circle::print() const {
	std::cout << "Circle radius: " << radius << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
}