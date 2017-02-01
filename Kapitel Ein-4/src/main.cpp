/**
 * Write a method to replace all spaces in a string with '%20'. You may assume that the string has
 * sufficient space at the end of the string to hold the additional characters, and that you are
 * given the "true" length of the string.
 * Example:
 * Input:  "Mr John Smith    ", 13
 * Output: "Mr%20John%20Smith"
 *
 * Programmer response:
 * Can I use regex?
 */

#include<cstring>   //Used for std::strlen
#include<iostream>
#include<string>

void replaceSpaces(char* str, int str_size);

int main(int argc, char* argv[]){
	char str[] = "Mr John Smith    ";
	int str_size = 13;

	std::cout << "Before: '" << str << '\'' << std::endl;
	replaceSpaces(str,str_size);
	std::cout << "After:  '" << str << '\'' << std::endl;

	return 0;
}

/**
 * Error check for edge cases such as an empty string, strings with leading spaces, and strings with
 * no spaces.
 *
 * Work backwards?
 * By working backwards, we can use two indices. One will parse the string, the other will trail
 * from the end and replace text as it goes.
 *
 * @param str
 * @param str_size
 */
void replaceSpaces(char* str, int str_size){
	int end_position = std::strlen(str)-1;
	for(int x = str_size-1; x >= 0; x--){
		if(str[x] == ' '){
			str[end_position] = '0';
			str[end_position-1] = '2';
			str[end_position-2] = '%';
			end_position -= 3;
		}else{
			str[end_position] = str[x];
			end_position--;
		}
	}
}
