#include <iostream>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) {
        //altough input checking was not required, it would be a good practice to do so
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    int isSpecial() {
        if (side1 == side2 && side2 == side3) {
            return 2; // equilateral triangle
        }
        if (side1 == side2 || side2 == side3 || side3 == side1) {
            return 1; // isosceles triangle
        }
        return 0; // none of the above
    }
};

int main() {
    // create a Triangle instance with sides 5, 5, 7
    Triangle t(2, 2, 4);

    // use the isSpecial method to check the type of triangle
    int special = t.isSpecial();

    // print the result
    if (special == 2) {
        cout << "Equilateral Triangle" << endl;
    } else if (special == 1) {
        cout << "Isosceles Triangle" << endl;
    } else {
        cout << "None of the above" << endl;
    }

    return 0;
}
