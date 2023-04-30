#pragma once
#include "Equipment.h"

class Printer : public Equipment {
private:
	int speed;
	
public:
	Printer(int id, double price, int speed) : Equipment(id, price), speed(speed) {}
	void print() const;
};