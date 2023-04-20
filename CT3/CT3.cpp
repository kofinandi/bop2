#include <iostream>

class Vector {
private:
    double x;
    double y;

public:
    // Constructor which can only be called with 2 parameters
    Vector(double x, double y) : x(x), y(y) {}

    // Destructor (only needed if there are any dynamically allocated resources)
    // Not needed in this case as there are no dynamically allocated resources

    // Subtraction operator overload
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y);
    }

    // This method was not necessary, it is only here to see the result
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Create two vectors
    Vector v1(1.0, 2.0);
    Vector v2(3.0, 4.0);

    // Print initial vector coordinates
    std::cout << "v1: ";
    v1.print();
    std::cout << std::endl;

    std::cout << "v2: ";
    v2.print();
    std::cout << std::endl;

    // Subtract v2 from v1
    Vector result = v1 - v2;

    // Print result
    std::cout << "v1 - v2: ";
    result.print();
    std::cout << std::endl;

    return 0;
}
