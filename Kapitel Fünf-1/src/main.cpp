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
 *
 * I didn't need this, but I'm writing it here as knowledge that I learned while experimenting:
 *   unsigned int max = std::numeric_limits<unsigned int>::max();
 *
 * I misinterpreted the question at first. I thought it was shifting the values to the left to make
 * room for the bits we planned to merge in. After further inspection, I realized that it keeps the
 * original bits in their original location with the merged value superimposed onto it.
 *
 * To handle this I knew which bits needed to be overwritten, so I created a mask, shifted it into
 * place, erased the bits that were in the original value, then ANDed the merge value into place
 * after some more shifting.
 *
 * Overall, not too bad of a problem. I had to print out my results an awful lot to visualize it
 * however. I'm hoping this isn't a question that is asked on paper. It's very easy for me to get a
 * off-by-one error somewhere.
 */

#include<bitset>
#include<iostream>
#include<limits>
#include<string>

void printBinary(const unsigned int& number_, std::string label_);
unsigned int spliceBinary(const unsigned int& b_num1_, const unsigned int& b_num2_, const unsigned int start_, const unsigned int end_);

int main(int argc_, char* argv_[]){
	//unsigned int N = 0b10000000000;
	unsigned int N = 0b10000000001;
	unsigned int M = 0b10011;
	printBinary(N,"N");
	printBinary(M,"M");

	unsigned int result = spliceBinary(N, M, 2, 6);

	printBinary(result,"Result");

	return 0;
}

void printBinary(const unsigned int& number_, std::string label_){
	std::cout << label_ << '\n';
	std::cout << "\tUnsigned Int: " << number_ << '\n';
	std::cout << "\tBinary: " << std::bitset<sizeof(unsigned int)*8>(number_) << '\n';
}

/**
 * @param b_num1_ The original value.
 * @param b_num2_ The value being merged into the original value.
 * @param start_ The starting location where the merged value will be inserted into.
 * @param end_ The last bit location where the merged value stops.
 * @return The spliced values of the first and second numbers.
 */
unsigned int spliceBinary(const unsigned int& b_num1_, const unsigned int& b_num2_, const unsigned int start_, const unsigned int end_){
	unsigned int diff = end_ - start_;
	unsigned int mask = (1 << (diff+1))-1;
	mask <<= start_;
	printBinary(mask, "Mask");
	unsigned int spliced_val = (b_num1_ & ~mask) | (b_num2_<<start_);

	return spliced_val;
}
