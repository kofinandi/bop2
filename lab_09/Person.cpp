#include "Person.h"
#include <iostream>
#include <fstream>
using namespace std;

// Implementation of ISerializable::Save
void Person::Save(std::ostream& os) {
	os << (int)age << ';' << height << ';' << weight << endl;
}

// Implementation of ISerializable::Load 
void Person::Load(std::istream& is) {
	double height; double weight; int age; char c;
	is >> age;
	is >> c;
	if (c != ';') is.clear(ios::failbit);
	is >> height;
	is >> c;
	if (c != ';') is.clear(ios::failbit);
	is >> weight;
	if (is) {
		this->age = age;
		this->height = height;
		this->weight = weight;
	}
	else {
		cerr << "Error in input format." << endl;
	}
}

// Implementation of IComparable::operator==
bool Person::operator==(const IComparable& theOther) {
	const Person& other = dynamic_cast<const Person&>(theOther);
	return (this->age == other.age) && (this->height == other.height) && (this->weight == other.weight);
}

// Implementation of IComparable::operator>
bool Person::operator>(const IComparable& theOther) {
	const Person& other = dynamic_cast<const Person&>(theOther);
	return (this->age > other.age);
}

void Person::SetHeight(double height) {
	this->height = height;
}

double Person::GetHeight() {
	return height;
}

void Person::SetWeight(double weight) {
	this->weight = weight;
}

double Person::GetWeight() {
	return weight;
}
