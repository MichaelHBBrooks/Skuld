/**
 * Given two strings, write a method to decide if one is a permutation of the other.
 *
 * Programmer response:
 * Do I have any expectations that the strings will ever be pre-sorted?
 * I'm going to assume the algorithm library is available, therefore sort is available.
 * If sort isn't available and they don't really care about me implementing a quick sort algorithm,
 * then I'll go with character counts.
 */

#include<algorithm>
#include<iostream>

using namespace std;

void attemptPermutation(string str1, string str2);
bool isPermutation(string str1, string str2);
bool isPermutation2(string str1, string str2);

int main(int argc, char* arv[]){
	string a1 = "racecar";
	string a2 = "racecar";
	string b1 = "i am lord voldemort";
	string b2 = "tom marvolo riddle "; //Yes... I know I need this extra space for it to count.
	string c1 = "apple";
	string c2 = "banana";
	string d1 = "asdfghjkl";  // same size, different letters.
	string d2 = "qwertyuio";

	attemptPermutation(a1,a2);
	attemptPermutation(b1,b2);
	attemptPermutation(c1,c2);
	attemptPermutation(d1,d2);

	return 0;
}

void attemptPermutation(string str1, string str2){
	std::cout << "Is '" << str1 << "' a permutation of '" << str2 << "'? ";
	if(isPermutation2(str1, str2)){
		std::cout << "Yes!\n";
	}else{
		std::cout << "No.\n";
	}
}

bool isPermutation(string str1, string str2){
	if(str1.length() != str2.length()){
		return false;
	}else if(str1 == str2){
		return true;
	}
	std::sort(str1.begin(),str1.end());
	std::sort(str2.begin(),str2.end());
	if(str1 == str2){
		return true;
	}
	return false;
}

bool isPermutation2(string str1, string str2){
	if(str1.length() != str2.length()){
		return false;
	}else if(str1 == str2){
		return true;
	}
	int char_count1[256] = {};  //I don't want to have to make another hash map, but I could.
	int char_count2[256] = {};
	//  Get a count of all letters in the first string.
	for(unsigned int x = 0; x < str1.length(); x++){
		char_count1[static_cast<int>(str1[x])]++;
	}
	//  Get a count of all letters in the second string. If a character appears that we didn't see
	//  in the first one, we know it's bogus.
	for(unsigned int y = 0; y < str2.length(); y++){
		char_count2[static_cast<int>(str2[y])]++;
		if(char_count2[static_cast<int>(str2[y])] > char_count1[static_cast<int>(str2[y])]){
			return false;
		}
	}
	//  If we get this far, then we never exceeded the first string's counts, and they're equal in
	//  length. Therefore they are permutations of each other.
	return true;
}
