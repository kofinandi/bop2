#pragma once

class Equipment {
protected:
	int id;
	double price;

public:
	Equipment(int id, double price) : id(id), price(price) {}
	virtual void print() const = 0;
};