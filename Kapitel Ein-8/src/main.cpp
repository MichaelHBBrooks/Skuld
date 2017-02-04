/**
 * Assume you have a method isSubstring which checks if one word is a substring of another. Given two
 * strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to
 * isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
 *
 * Programmer response:
 * I don't really understand the question. What does substring really do? Does it say "df" is a
 * substring of "asdf"? Would it say "sf" is a substring of "asdf"?
 * Without the interviewer in front of me I only have conjecture and the solutions in the back of
 * the book. I don't really want to look though.
 * ...
 * So I looked. This was a dumb question. If I knew for sure that "sf" did not count, then it would
 * clear up a lot of my confusion. As penance, I will write up an implementation of isSubstring.
 *
 * And then after coding a portion of isSubstring I realized it's basically the same thing as the
 * string library's find function. At least this exercise taught me about std::string::npos.
 * I didn't really like this question.
 */

#include<iostream>
#include<string>

using namespace std;

bool isRotation(string str1, string str2);
bool isSubstring(string master, string possible_substr);

int main(int argc, char* argv[]){
	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	cout << "string 1: " << s1 << endl
			<< "string 2: " << s2 << endl
			<< "is rotation? " << boolalpha << isRotation(s1,s2) << endl;

	return 0;
}

bool isRotation(string str1, string str2){
	if(str1.length() > 0 && str1.length() == str2.length()){
		return isSubstring(str1+str1,str2);
	}
	return false;
}
bool isSubstring(string master, string possible_substr){
//	if(master.length() < possible_substr.length()){
//		return false;
//	}else if(master.length() == 0){
//		//  '' is a substring of ''
//		return true;
//	}

	return master.find(possible_substr) != std::string::npos;
}
