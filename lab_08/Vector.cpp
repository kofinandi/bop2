#include <limits.h>
#include <assert.h>
#include "Vector.h"
#include "Equipment.h"

using namespace std;

ostream& operator<< (ostream& os, const Vector& v) {
	for (unsigned int i = 0; i < v.elementNum; i++) {
		v.at(i)->print();
	}
	return os;
}

Vector::Vector(const Vector& theOther) {
	pData = NULL;
	*this = theOther;
}

void Vector::clear() {
	for (unsigned int i = 0; i < elementNum; i++) {
		delete pData[i];
	}
	delete[]pData;
	pData = NULL;
	elementNum = 0;
}


void Vector::erase(unsigned int position) {
	assert(position < elementNum);

	if (elementNum == 1) {
		delete pData[0];
		delete[] pData;
		pData = NULL;
		elementNum = 0;
		return;
	}

	elementNum--;
	Equipment** pTemp = new Equipment * [elementNum];

	for (unsigned int i = 0, j = 0; i < elementNum + 1; i++, j++) {
		if (i == position) {
			delete pData[i];
			j--;
		}
		else {
			pTemp[j] = pData[i];
		}
	}
	delete[] pData;
	pData = pTemp;
}

Equipment* Vector::at(unsigned int position) {
	assert(position < elementNum);
	return pData[position];
}

const Equipment* Vector::at(unsigned int position)const {
	assert(position < elementNum);
	return pData[position];
}

bool Vector::insert(unsigned int position, Equipment* element) {
	if (elementNum == UINT_MAX) {
		return false;
	}

	Equipment** pTemp = NULL;
	if (position < elementNum) {
		pTemp = new Equipment * [elementNum + 1];
		for (unsigned int i = 0, j = 0; i < elementNum; i++, j++) {
			if (j == position) {
				pTemp[position] = element;
				i--;
			}
			else {
				pTemp[j] = pData[i];
			}
		}
		elementNum++;
	}
	else {
		pTemp = new Equipment * [position + 1];
		for (unsigned int i = 0; i < position; i++) {
			if (i < elementNum) {
				pTemp[i] = pData[i];
			}
			else {
				pTemp[i] = 0;
			}
		}
		pTemp[position] = element;
		elementNum = position + 1;
	}
	delete[]pData;
	pData = pTemp;
	return true;
}

Equipment* Vector::operator[](unsigned int position) {
	return at(position);
}
const Equipment* Vector::operator[](unsigned int position)const {
	return at(position);
}

const Vector& Vector::operator= (const Vector& theOther) {
	assert(this != &theOther);
	for (unsigned int i = 0; i < elementNum; i++) {
		delete pData[i];
	}
	delete[]pData;
	if (theOther.elementNum == 0) {
		elementNum = 0;
		pData = NULL;
	}
	else {
		elementNum = theOther.elementNum;
		pData = new Equipment * [elementNum];
		for (unsigned int i = 0; i < elementNum; i++) {
			// it might be better to copy the data instead of the pointer, this is only the simple way
			pData[i] = theOther.pData[i];
		}
	}
	return *this;
}