/**
 * Implement a method to perform basic string compression using the counts of repeated stringacters.
 * For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not
 * become smaller than the original string, your method should return the original string. You can
 * assume the string has only upper and lower case letters (a-z).
 *
 * Programmer response:
 * The question asked for it to be returned. Not mutated as a side effect. I will take it literally.
 * If I use char, then I have to be concerned about an array that ends up being larger than it
 * arrived as.
 * So... two strings, an int to act as an index, and a counter int.
 */

#include<iostream>
#include<string>

using namespace std;

void attemptCompression(const string& someString);
string compressString(const string& str);

int main(int argc, char* argv[]){
	string a = "abcdefg";
	string b = "aabcccccaaa";
	string c = "aa";
	string d = "aabbcc"; //  a2b2c2 is the same size, but we won't know until the end.

	attemptCompression(a);
	attemptCompression(b);
	attemptCompression(c);
	attemptCompression(d);

	return 0;
}

void attemptCompression(const string& someString){
	std::cout << "Before: '" << someString << "'\n";
	std::cout << "After:  '" << compressString(someString) << "'\n";
}

string compressString(const string& str){
	if(str.length() <= 2){
		return str;
	}
	string c_str;
	c_str.push_back(str[0]);
	int count = 1;
	for(unsigned int x = 1; x < str.length(); x++){
		if(c_str.back() == str[x]){
			count++;
		}else{
			c_str.push_back(count+'0');
			c_str.push_back(str[x]);
			count = 1;
		}
	}
	c_str.push_back(count+'0');
	if(c_str.length() >= str.length()){
		return str;
	}
	return c_str;
}
