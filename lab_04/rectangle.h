#pragma once

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double side1 = 0, double side2 = 0);
    double getLength() const;
    double getWidth() const;
    double getPerimeter() const;
    double getArea() const;
    void print() const;
};