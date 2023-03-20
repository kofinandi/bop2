#include "rectangle.h"
#include "circle.h"

int main() {
	Rectangle r1;
	r1.print();

	Rectangle r2(5);
	r2.print();

	Rectangle r3(-5, 10);
	r3.print();

	Rectangle r4(10, 5);
	r4.print();

	Circle c1;
	c1.print();

	Circle c2(5);
	c2.print();

	Circle c3(-5);
	c3.print();

	return 0;
}