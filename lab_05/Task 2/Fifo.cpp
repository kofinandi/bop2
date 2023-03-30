#include "Fifo.h"

Fifo::Fifo()
{
	elementNum = 0;
	pData = NULL;
}

Fifo::Fifo(const Fifo& theOther)
{
	elementNum = theOther.elementNum;
	pData = new int[elementNum];
	for (int i = 0; i < elementNum; i++)
	{
		pData[i] = theOther.pData[i];
	}
}

Fifo::~Fifo()
{
	delete[] pData;
}

void Fifo::push(int element)
{
	int* temp = new int[elementNum + 1];
	for (int i = 0; i < elementNum; i++)
	{
		temp[i] = pData[i];
	}
	temp[elementNum] = element;
	delete[] pData;
	pData = temp;
	elementNum++;
}

int Fifo::pop()
{
	int temp1 = pData[0];
	int* temp2 = new int[elementNum - 1];
	for (int i = 1; i < elementNum; i++)
	{
		temp2[i - 1] = pData[i];
	}
	delete[] pData;
	pData = temp2;
	elementNum--;
	return temp1;
}

bool Fifo::isEmpty()
{
	if (elementNum == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fifo::print()
{
	printf("\n");
	for (int i = 0; i < elementNum; i++)
	{
		printf("%d ", pData[i]);
	}
	printf("\n");
}