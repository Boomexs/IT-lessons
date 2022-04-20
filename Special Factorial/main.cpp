#include <iostream>
#include <string>

long long factorial(int n) {
	// If the input number is smaller then 0 return an error
	if (n < 0) { return -1; };

	// Create a return number equal to 1
	long long ret = 1;

	// Factorial
	for (int i = 0; i < n; i++) {
		ret *= (i + 1);
	}

	return ret;
}


bool special(unsigned int n) {
	// Create a string from n, init a var
	std::string str = std::to_string(n);
	unsigned long long iN = 0;

	// Special func
	for (int i = 0; i < str.length(); i++) {
		iN += factorial(str.data()[i]-48); // x - 48 char into int conversion
	}

	// create a string from iN
	std::string nstr = std::to_string(iN);

	// Compare the two strings
	if (strcmp(str.data(), nstr.data()) == 0) { return true; };
	return false;
}

int main() {

	// Init some variables
	unsigned long arr[4];
	short cFound = 0;

	// Find the 4 numbers that mmet the criteria
	for (int i = 0; cFound != 4; i++) {
		if (special(i)) { arr[cFound] = i; cFound++; };
	}
	
	//Output those numbers to the screen
	std::cout << "Numbers meeting the criteria: ";
	for (int i = 0; i < cFound; i++) {
		std::cout << arr[i];
		if (i + 1 != cFound) { std::cout << ","; };
	}

	getchar();
	return 0;
}
