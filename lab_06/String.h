#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace HomeMadeString
{
	class String
	{
		// Number of characters in the string
		int elementNum;
		// Pointer to the memory segment containing the characters
		char* pData;
	
	public:
		// Default constructor (without arguments):
		String();

		// Copy constructor:
		String(const String& str);


		// Conversion constructor that expects a char* with '\0' at the end
		// This constructor is responsible for the conversion char*-> String
		String(const char* str);

		// Constructor with a char (c) and an int parameter (times)
		// This constructor creates a string that contains 'times' pieces of the character c
		// e.g. if c='$' and times=5 then String="$$$$$"
		String(char c, int times);

		// Destructor:
		~String();

		// Copies the string to the buffer and terminates it with '\0' (string terminating character)
		// Memory allocation for the buffer is to be done by a caller
		void getStr(char * pBuff) const;
		
		// Returns with the string length
		int getLength() const {return elementNum;}

		// Writes the string to the given stream		
		void print(std::ostream& os) const;

		// Returns with the character at the given position, othewise 0
		char getChar(int pos) const;

		// --- Static Class Members. They work with two strings passed as parameters. ---
		
		// Returns with a concatenated string
		static String concatenate(const String& string1, const String& string2);

		// Compares two strings
		static bool compare(const String& string1, const String& string2);

		// Copies string2 to string1
		static void copy(String& string1, const String& string2);
	};
}
#endif /* STRING_H */