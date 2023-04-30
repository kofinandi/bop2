#include <iostream>
#include "Printer.h"

void Printer::print() const
{
	std::cout << "Printer: ";
	std::cout << "ID: " << id << ", ";
	std::cout << "Price: " << price << ", ";
	std::cout << "Speed: " << speed << std::endl;
}