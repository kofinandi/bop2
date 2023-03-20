#include "rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(double side1, double side2) {
	side1 = std::abs(side1);
	side2 = std::abs(side2);

    if (side1 == 0 && side2 == 0) {
		length = width = 0;
	}
    else if (side1 == 0 || side2 == 0) {
		length = width = side1 + side2; // square
	}
    else {
		length = std::max(side1, side2);
		width = std::min(side1, side2);
	}
}

double Rectangle::getLength() const {
	return length;
}

double Rectangle::getWidth() const {
	return width;
}

double Rectangle::getPerimeter() const {
	return 2 * (length + width);
}

double Rectangle::getArea() const {
	return length * width;
}

void Rectangle::print() const {
	std::cout << "Rectangle Sides: " << length << ", " << width << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
}