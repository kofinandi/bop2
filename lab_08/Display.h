#pragma once
#include "Equipment.h"

class Display : public Equipment {
private:
	int year;

public:
	Display(int id, double price, int year) : Equipment(id, price), year(year) {}
	void print() const;
};