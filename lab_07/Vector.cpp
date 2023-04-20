#include "Vector.h"
#include <iostream>

Vector::Vector(const Vector& theOther) {
	elementNum = theOther.elementNum;

	if (elementNum == 0) {
		pData = NULL;
		return;
	}

	pData = new int[elementNum];
	for (int i = 0; i < elementNum; i++) {
		pData[i] = theOther.pData[i];
	}
}

void Vector::clear() {
	delete[] pData;
	pData = NULL;
	elementNum = 0;
}

void Vector::erase(unsigned int position) {
	if (position < elementNum && position >= 0) {
		if (elementNum == 1) {
			clear();
			return;
		}

		int *temp = new int[elementNum - 1];
		for (int i = 0; i < position; i++) {
			temp[i] = pData[i];
		}
		for (int i = position; i < elementNum - 1; i++) {
			temp[i] = pData[i + 1];
		}

		// A different approach
		//int x = 0;
		//for (int i = 0; i < elementNum; i++)
		//{
		//	if (i != position)
		//	{
		//		temp[x++] = pData[i];
		//	}
		//}

		delete[] pData;
		pData = temp;
		elementNum--;
	}
}

int& Vector::at(unsigned int position) {
	return pData[position];
	// It would better to check if the position is valid, but there would be no return value in the invalid case. The best solution would be to throw an exception, but that should fit in the topic of exceptions.
}

const int& Vector::at(unsigned int position)const {
	return pData[position];
}

bool Vector::insert(unsigned int position, int element) {
	int *temp;
	if (position < elementNum && position >= 0) {
		temp = new int[elementNum + 1];
		for (int i = 0; i < position; i++) {
			temp[i] = pData[i];
		}
		temp[position] = element;
		for (int i = position + 1; i < elementNum + 1; i++) {
			temp[i] = pData[i - 1];
		}
		elementNum++;
	}
	else if (position >= elementNum) {
		temp = new int[position + 1];
		for (int i = 0; i < elementNum; i++) {
			temp[i] = pData[i];
		}
		for (int i = elementNum; i < position; i++) {
			temp[i] = 0;
		}
		temp[position] = element;
		elementNum = position + 1;
	}
	else {
		// It might be more useful to return false (or throw an exception) when the memory allocation fails, but that should fit in the topic of exceptions.
		return false;
	}
	delete[] pData;
	pData = temp;
	return true;
}

const Vector& Vector::operator= (const Vector& theOther) {
	if (this != &theOther) {
		delete[] pData;
		elementNum = theOther.elementNum;
		if (elementNum == 0) {
			pData = NULL;
			return *this;
		}
		pData = new int[elementNum];
		for (int i = 0; i < elementNum; i++) {
			pData[i] = theOther.pData[i];
		}
	}
	return *this;
}

int& Vector::operator[] (unsigned int position) {
	return pData[position];
}

const int& Vector::operator[] (unsigned int position)const {
	return pData[position];
}

std::ostream& operator<< (std::ostream& os, const Vector& v) {
	for (int i = 0; i < v.elementNum; i++) {
		os << v.pData[i] << " ";
	}
	return os;
}

// Homework extra
void Vector::sort() {
	for (int i = 0; i < elementNum; i++) {
		for (int j = 0; j < elementNum - 1; j++) {
			if (pData[j] > pData[j + 1]) {
				int temp = pData[j];
				pData[j] = pData[j + 1];
				pData[j + 1] = temp;
			}
		}
	}
}