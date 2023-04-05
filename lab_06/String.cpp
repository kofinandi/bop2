#include "String.h"
#include <iostream>

namespace HomeMadeString {
	String::String() {
		elementNum = 0;
		pData = nullptr;
	}

	String::String(const String& str) {
		elementNum = str.elementNum;
		pData = new char[elementNum];
		for (int i = 0; i < elementNum; i++) {
			pData[i] = str.pData[i];
		}
	}

	String::String(const char* str) {
		elementNum = 0;
		while (str[elementNum] != '\0') {
			elementNum++;
		}
		pData = new char[elementNum];
		for (int i = 0; i < elementNum; i++) {
			pData[i] = str[i];
		}
	}

	String::String(char c, int times) {
		elementNum = times;
		pData = new char[elementNum];
		for (int i = 0; i < elementNum; i++) {
			pData[i] = c;
		}
	}

	String::~String() {
		delete[] pData;
	}

	void String::getStr(char* pBuff) const {
		for (int i = 0; i < elementNum; i++) {
			pBuff[i] = pData[i];
		}
		pBuff[elementNum] = '\0';
	}

	char String::getChar(int pos) const {
		if (pos < elementNum && pos >= 0) {
			return pData[pos];
		}
		else {
			return 0;
		}
	}

	void String::print(std::ostream& os) const {
		for (unsigned int i = 0; i < elementNum; i++) {
			os << pData[i];
		}
	}

	String String::concatenate(const String& string1, const String& string2) {
		String result;
		result.elementNum = string1.elementNum + string2.elementNum;
		result.pData = new char[result.elementNum];
		for (int i = 0; i < string1.elementNum; i++) {
			result.pData[i] = string1.pData[i];
		}
		for (int i = 0; i < string2.elementNum; i++) {
			result.pData[string1.elementNum + i] = string2.pData[i];
		}
		return result;
	}

	bool String::compare(const String& string1, const String& string2) {
		if (string1.elementNum != string2.elementNum) {
			return false;
		}
		
		for (int i = 0; i < string1.elementNum; i++) {
			if (string1.pData[i] != string2.pData[i]) {
				return false;
			}
		}
		return true;
	}

	void String::copy(String& string1, const String& string2) {
		string1.elementNum = string2.elementNum;
		delete[] string1.pData;
		string1.pData = new char[string1.elementNum];
		for (int i = 0; i < string1.elementNum; i++) {
			string1.pData[i] = string2.pData[i];
		}
	}
}