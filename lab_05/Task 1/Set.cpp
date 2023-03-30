#include "Set.h"

Set::Set()
{
	elementNum = 0;
	pData = NULL;
}

Set::Set(const Set& theOther)
{
	elementNum = theOther.elementNum;
	pData = new int[elementNum];
	for (int i = 0; i < elementNum; i++)
	{
		pData[i] = theOther.pData[i];
	}
}

Set::~Set()
{
	delete[] pData;
}

bool Set::insert(int element)
{
	if (isElement(element))
	{
		return true;
	}
	else
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
		return true;
	}
}

bool Set::remove(int element)
{
	if (isElement(element))
	{
		int* temp = new int[elementNum - 1];
		int j = 0;
		for (int i = 0; i < elementNum; i++)
		{
			if (pData[i] != element)
			{
				temp[j] = pData[i];
				j++;
			}
		}
		delete[] pData;
		pData = temp;
		elementNum--;
		return true;
	}
	else
	{
		return false;
	}
}

bool Set::isElement(int element)
{
	for (int i = 0; i < elementNum; i++)
	{
		if (pData[i] == element)
		{
			return true;
		}
	}
	return false;
}

void Set::print()
{
	printf("\n");
	for (int i = 0; i < elementNum; i++)
	{
		printf("%d ", pData[i]);
	}
	printf("\n");
}