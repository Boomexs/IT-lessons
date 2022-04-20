#include <iostream>
#include <string>

bool isPalindrome(char word[]) {
	// Find the string termination char to determine string lenght
	int len = 0;
	while (word[len] != '\0') { len++; };
	std::cout << "Word lenght: " << len << std::endl;

	// Make the string lowercase
	for (int i = 0; i < len; i++) {
		word[i] = tolower(word[i]);
	}

	// Get the lenght of the string that we need to check
	int hLen = len - len % 2;
	hLen = hLen / 2;

	// Check whether the chars from the beggining and the end are the same
	std::cout << "Comparing: " << std::endl;
	for (int i = 0; i < hLen; i++) {
		std::cout << i + 1 << ": " << word[i] << "	" << len - i << ": " << word[len - i - 1] << std::endl;;
		if (word[i] != word[len - i - 1]) { return false; }; // If not return false
	}
	// If they are, return true
	return true;
}

int main() {

	// Create a string to store our word
	char string[256];
	std::cout << "Palindrome cheat sheet: redivider, deified, civic, radar, level, rotor, kayak, reviver, racecar, madam, refer" << std::endl << "Enter word: ";
	// Get the word from the user
	std::cin.getline(string, 256);

	//Check if it's a palindrome and give the answer back to the user
	std::cout << std::endl << "Is your word a Palindrome: " << isPalindrome(string) << std::endl;
}