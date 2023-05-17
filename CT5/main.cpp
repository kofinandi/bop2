#include <iostream>
#include <cmath>

using namespace std;

double rootof(double n) {
	if (n >= 10000) {
		// You can throw any exception you want here
		throw invalid_argument("Error: number is greater than 10000!");
	}
	if (n < 0) {
		// You can throw any exception you want here
		throw invalid_argument("Error: square root of negative number is undefined!");
	}
	return sqrt(n);
}

int main()
{
	double num, res;
	cin >> num;
	try {
		res = rootof(num);
		cout << "Square root of " << num << " is " << res << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
	return 0;
}