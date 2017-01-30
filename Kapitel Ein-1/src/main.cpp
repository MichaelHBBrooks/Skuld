/**
 * Implement an algorithm to determine if a string has all unique characters. What if you cannot use
 * additional data structures?
 *
 * Programmer response: I am assuming the number of possible characters is undefined.
 * If ASCII or unicode of some sort was defined, then my response would be to use a bool array
 * rather than a map.
 */

#include<iostream>
#include<map>
#include<string>

using namespace std;

bool hasUniqueChars(string someString);

int main(int argc, char* argv[]){
	string a = "apple";
	string b = "noduplicates";
	if(hasUniqueChars(a)){
		cout << '\'' << a << "' is unique.\n";
	}else{
		cout << '\'' << a << "' is NOT unique.\n";
	}

	if(hasUniqueChars(b)){
		cout << '\'' << b << "' is unique.\n";
	}else{
		cout << '\'' << b << "' is NOT unique.\n";
	}

	return 0;
}

bool hasUniqueChars(string someString){
	map<char, bool> charHash;
	for(unsigned int x = 0; x < someString.length(); x++){
		if(charHash[someString[x]]){
			return false;
		}else{
			charHash[someString[x]] = true;
		}
	}
	return true;
}
