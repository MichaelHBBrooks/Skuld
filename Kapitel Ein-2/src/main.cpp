/**
 * Implement a function void reverse(char* str) in C or C++ which reverses a null terminated string.
 *
 * Programmer response:
 * The first reverse function is what I would have come up with had I not found the existence of
 * reverse2's std::reverse function.
 */

#include<algorithm> //Used for std::reverse
#include<cstring>   //Used for std::strlen
#include<iostream>  //Used for std::cout, std::endl

void reverse(char* str);
void reverse2(char* str);

int main(int argc, char* argv[]){
	char someString[] = "asdf";
	std::cout << "String: " << someString << std::endl;
	reverse2(someString);
	std::cout << "Reversed string: " << someString << "\n\n";

	char someString2[] = "asXdf";
	std::cout << "String: " << someString2 << std::endl;
	reverse2(someString2);
	std::cout << "Reversed string: " << someString2 << "\n\n";

	return 0;
}

void reverse(char* str){
	for(unsigned int x = 0; x < strlen(str)/2; x++){
		char temp = str[x];
		str[x] = str[strlen(str)-x-1];
		str[strlen(str)-x-1] = temp;
	}
}

void reverse2(char* str){
	std::reverse(str, str + std::strlen(str));
}
