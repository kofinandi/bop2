#include "String.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace TheUltimateString
{
	String::String()
	{
		pData = NULL;
		elementsNum = 0;
	}

	String::String(const String& string)
	{
		pData = NULL;
		copy(*this, string);
	}

	// What error do you see here?
	//String::String(const char* str)
	//{
	//	pData = NULL;
	//	copy(*this, str);
	//}

	String::String(const char* str)
	{
		pData = NULL;
		for (elementsNum = 0; str[elementsNum] != '\0'; elementsNum++);
		pData = new char[elementsNum + 1];
		for (unsigned int i = 0; i < elementsNum; i++)
		{
			pData[i] = str[i];
		}
		pData[elementsNum] = '\0';
	}

	String::String(const char c, unsigned int times)
	{
		elementsNum = times;

		if (elementsNum == 0)
		{
			pData = NULL;
			return;
		}

		pData = new char[elementsNum + 1];
		for (unsigned int i = 0; i < elementsNum; i++)
		{
			pData[i] = c;
		}
		pData[elementsNum] = '\0';
	}


	void String::print(ostream& os)
	{
		for (unsigned int i = 0; i < elementsNum; i++)
		{
			os << pData[i];
		}
	}

	char& String::operator[](unsigned int pos)
	{
		assert(pos < elementsNum);
		return pData[pos];
	}

	const char& String::operator[](unsigned int pos)const
	{
		assert(pos < elementsNum);
		return pData[pos];
	}

	String String::operator+(const String& theOther)const
	{
		return concatenate(*this, theOther);
	}

	const String& String::operator+=(const String& theOther)
	{
		String temp = concatenate(*this, theOther);
		copy(*this, temp);
		return *this;
	}

	const String& String::operator=(const String& theOther)
	{
		if (this == &theOther)
		{
			return *this;
		}
		copy(*this, theOther);
		return *this;
	}

	bool String::operator==(const String& theOther)const
	{
		return compare(*this, theOther);
	}

	String::operator const char* ()const
	{
		return pData;
	}

	String String::concatenate(const String& string1, const String& string2)
	{
		String s;
		s.elementsNum = string1.elementsNum + string2.elementsNum;

		if (s.elementsNum == 0)
		{
			s.pData = NULL;
			return s;
		}

		s.pData = new char[s.elementsNum + 1];

		for (unsigned int i = 0; i < string1.elementsNum; i++)
		{
			s.pData[i] = string1.pData[i];
		}
		for (unsigned int j = string1.elementsNum; j < s.elementsNum; j++)
		{
			s.pData[j] = string2.pData[j - string1.elementsNum];
		}

		s.pData[s.elementsNum] = '\0';
		return s;
	}

	bool String::compare(const String& string1, const String& string2)
	{
		if (string1.elementsNum != string2.elementsNum)
			return false;

		for (unsigned int i = 0; i < string1.elementsNum; i++)
		{
			if (string1.pData[i] != string2.pData[i])
				return false;
		}
		return true;
	}

	void String::copy(String& string1, const String& string2)
	{
		delete string1.pData;
		string1.elementsNum = string2.elementsNum;
		if (string1.elementsNum == 0)
		{
			string1.pData = NULL;
			return;
		}
		string1.pData = new char[string1.elementsNum + 1];
		for (unsigned int i = 0; i < string1.elementsNum; i++)
		{
			string1.pData[i] = string2.pData[i];
		}
		string1.pData[string1.elementsNum] = '\0';
	}

}