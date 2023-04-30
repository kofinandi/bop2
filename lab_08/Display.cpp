#include <iostream>
#include "Display.h"

void Display::print() const
{
	std::cout << "Display: ";
	std::cout << "ID: " << id << ", ";
	std::cout << "Price: " << price << ", ";
	std::cout << "Year: " << year << std::endl;
}