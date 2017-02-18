/**
 * Describe how you could use a single array to implement three stacks.
 *
 * Programmer response:
 * At first glance, this question doesn't make a lot of sense to me. Three stacks?
 *
 * I guess the first problem to resolve would be making one stack?
 *
 * Stacks are last in first out (LIFO).
 *
 * Looking at the solution in the back, I can see one of my other questions being answered: what are
 * we planning on storing in each of these entries? The example uses an int array, which is
 * convenient for the problem since it stores the node values in there.
 *
 * They also assume a fixed size.
 *
 * I keep forgetting that these problems are contrived and so can my answers. They set the stage, I
 * just need to respond with something that fits their criteria.
 *
 * I know I get bonus points for making it more fancy, but the amount of time I have to answer the
 * question depends on how much I have left to answer.
 */

#include<iostream>

class ArrayStack{
	const unsigned int size_;
	const unsigned int num_of_stacks_ = 3;
	int* stack_;

	int getStackOffset(const unsigned int& stack_num_){
		return stack_num_*size_+stack_[stack_num_]+num_of_stacks_;
	}
public:
	ArrayStack(const unsigned int& new_size_) : size_(new_size_){
		stack_ = new int[(size_ * num_of_stacks_)+num_of_stacks_];
		for(unsigned int x = 0; x < num_of_stacks_; x++){
			stack_[x] = -1;
		}
	}

	/**
	 * With 3 stacks, the array looks like:
	 * [0-2][3-102][103-202][203-202]
	 * [0-2] - These contain the offsets for the last entry in the stack.
	 * @param stack_num_
	 */
	void push(const unsigned int& stack_num_, const unsigned int& pushed_data_){
		if(stack_num_ > (num_of_stacks_ - 1)){
			throw std::invalid_argument("Invalid stack number.");
		}
		if(static_cast<unsigned int>(stack_[stack_num_])+1 >= size_){
			throw std::runtime_error("Overflow detected.");
		}
		stack_[stack_num_]++;
		int new_position = getStackOffset(stack_num_);
		stack_[new_position] = pushed_data_;
	}

	int pop(const unsigned int& stack_num_){
		if(stack_num_ > (num_of_stacks_ - 1)){
			throw std::invalid_argument("Invalid stack number.");
		}
		if(stack_[stack_num_] == -1){
			throw std::runtime_error("Cannot pop an empty stack.");
		}
		int position = getStackOffset(stack_num_);
		stack_[stack_num_]--;
		return stack_[position];
	}
};
int main(){
	ArrayStack ten_stack(10);
	try{
		ten_stack.push(0,1);
		ten_stack.push(1,20);
		ten_stack.push(1,-61);
		ten_stack.push(2,548);
	}catch(std::runtime_error& error){
		std::cerr << error.what() << std::endl;
	}

	try{
		std::cout << "Stack 1 popped value: " << ten_stack.pop(0) << std::endl;
		std::cout << "Stack 2 popped value: " << ten_stack.pop(1) << std::endl;
		std::cout << "Stack 3 popped value: " << ten_stack.pop(2) << std::endl;
	}catch(std::runtime_error& error){
		std::cerr << error.what() << std::endl;
	}

	return 0;
}
