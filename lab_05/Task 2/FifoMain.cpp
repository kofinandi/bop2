#include "Fifo.h"

int main(void) {
	Fifo f1;

	f1.push(1);
	f1.push(2);
	f1.push(3);
	f1.push(4);
	f1.push(5);

	f1.print();

	printf("pop: %d", f1.pop());

	f1.print();

	Fifo f2(f1);

	f2.print();

	printf("pop: %d", f1.pop());

	f1.print();

	f2.print();

	return 0;
}