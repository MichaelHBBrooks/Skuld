/**
 * Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary
 * representation. If the number cannot be represented accurately in binary with at most 32
 * characters, print "ERROR".
 *
 * Programmer response:
 * I hate floating points.
 *
 * After like... an hour or two of researching how floats and doubles, I remember why I hated them.
 * Signs, exponents, significand, and just the fact that I plain forgot how decimal numbers are
 * represented in binary makes me hate them.
 * Ints make sense to me. 32 = 2^5 = 0b100000. Easy.
 * Decimals make sense, but my brain can't convert them anywhere as easily as ints to binary:
 * 0.5 = 1/(2^1) = 1 (base 2)
 * 0.625 = 1/(2^1) + 0/(2^2) + 1/(2^3) = 0.101 (base 2)
 *
 * So after a week of not wanting to copy the back of the book's answer, I ended up doing it anyway.
 * I understand what it's doing, but I feel that this question is a bit too difficult to ask in an
 * interview setting. If they do, they're jerks.
 */

#include<bitset>
#include<iostream>
#include<string>

void printBinary(double number_, std::string label_);

int main(int argc_, char* argv_[]){
	double num1 = 0.72;
	printBinary(num1, "Num 1");
	double num2 = 0.75;
	printBinary(num2, "Num 2");
	double num3 = 0.625;
	printBinary(num3, "Num 3");
	double num4 = 1.72;
	printBinary(num4, "Num 4");
	return 0;
}

void printBinary(double number_, std::string label_){
	std::cout << label_ << '\n';
	if(number_ >= 1 || number_ <= 0){
		std::cout << "\tERROR - out of bounds\n";
		return;
	}

	std::cout << "\tDouble: " << number_ << '\n';

	double fraction = 0.5;
	std::string binary_str;
	while(number_ > 0){
		if(binary_str.length() > 32){
			std::cout << "\tERROR - binary value longer than 32 characters\n";
			return;
		}
//		std::cout << "fraction: " << fraction << '\n';
//		std::cout << "number: " << number_ << '\n';
		if(number_ >= fraction){
			binary_str.append("1");
			number_ -= fraction;
		}else{
			binary_str.append("0");
		}
		fraction /= 2;
	}
	std::cout << "\tBinary: " << binary_str << '\n';
}
