/**
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to
 * insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j
 * through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are
 * at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M
 * could not fully fit between bit 3 and 2.
 *
 * EXAMPLE
 * Input: N = 100 0000 0000, M = 1 0011, i = 2, j = 6
 * Output: 100 0100 1100
 *
 * Programmer response:
 * I am weak on bit manipulation. Simply put, it's never come up before. I've done the homework on
 * it in college so I know I can do it. The tricks will escape me until I review and practice them a
 * bit.
 */

#include<bitset>
#include<iostream>

void printBinary(const int& number_);
int spliceBinary(const int& b_num1_, const int& b_num2_, const int start_, const int end_);

int main(int argc_, char* argv_[]){
	//int a = 0b00000011;
	int N = 0b10000000000;
	int M = 0b10011;
	printBinary(N);
	printBinary(M);

	int result = spliceBinary(N, M, 2, 6);

	printBinary(result);

	return 0;
}

void printBinary(const int& number_){
	std::cout << "Int: " << number_ << '\n';
	std::cout << "Binary: " << std::bitset<sizeof(int)*8>(number_) << '\n';
}

int spliceBinary(const int& b_num1_, const int& b_num2_, const int start_, const int end_){
	int shifted_splice = b_num2_ << start_;
	printBinary(shifted_splice);
	return 0;
}
