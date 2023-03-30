#pragma once

#include <stdio.h>

class Fifo
{
	int elementNum;
	int* pData;

public:
	Fifo();

	Fifo(const Fifo &theOther);

	~Fifo();

	void push(int element);

	int pop();

	bool isEmpty();

	void print();
};