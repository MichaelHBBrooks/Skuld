/**
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in
 * real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of
 * several stacks and should create a new stack once the previous one exceeds capacity.
 * SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is,
 * pop() should return the same values as it would if there were just a single stack).
 *
 * FOLLOW UP
 * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 *
 * Programmer response:
 * This sounds... not so bad.
 * Make a counter.
 * Each time we push, add to the counter.
 * If we push and the threshold has been met, make a new stack.
 * Each time we pop, subtract from the counter.
 * If we pop and the counter is 0, delete the newest stack and use the old one.
 *
 * The follow up bit basically requires tracking the counter per stack rather than one.
 *
 * The end result of my SetOfStacks works, but I feel that my pop() function for the base stack
 * class could use some work for when it hits zero.
 * Also, I should probably create a destructor if I keep using the same premise for the Stack class.
 * I hope the vector class is allowed. The point of this exercise I feel is to show that I can make
 * custom Stack structures, not tinker with arrays in C++.
 */

#include<iostream>
#include<stdexcept>
#include<vector>

class Node{
public:
	Node(){
		next_ = NULL;
		data_ = 0;
	}
	Node* next_;
	int data_;
};
class Stack{
public:
	Node* head_;
	Stack(){
		head_ = NULL;
	}

	int pop(){
		if(head_ == NULL){
			throw std::runtime_error("Unable to pop empty list.");
		}
		int x = head_->data_;
		Node* popped_node = head_;
		head_ = head_->next_;
		delete popped_node;
		return x;
	}
	void push(int pushed_data_){
		Node* new_head = new Node;
		new_head->next_ = head_;
		new_head->data_ = pushed_data_;
		head_ = new_head;
	}
};

class SetOfStacks{
	const unsigned int threshold_;
	int current_stack_;
	unsigned int count_;
	std::vector<Stack> stacks_;
public:
	SetOfStacks(const unsigned int& new_threshold_) : threshold_(new_threshold_){
		count_ = 0;
		current_stack_ = 0;
		Stack new_stack;
		stacks_.push_back(new_stack);
	}
	int pop(){
		if(count_ == 0 && current_stack_ == 0){
			throw std::runtime_error("Unable to pop empty list.");
		}else if(count_ == 1){
			if(current_stack_ == 0){
				count_ = 0;
			}else{
				count_ = threshold_;
				int popped_value = stacks_[current_stack_--].pop();
				stacks_.pop_back();
				return popped_value;
			}
		}else{
			count_--;
		}
		return stacks_[current_stack_].pop();
	}
	void push(int pushed_data_){
		if(count_ == threshold_){
			Stack new_stack;
			stacks_.push_back(new_stack);
			current_stack_++;
			count_ = 1;
		}else{
			count_++;
		}
		stacks_[current_stack_].push(pushed_data_);
	}
};

int main(){
	SetOfStacks dishes(5);
	try{
		for(int i = 1; i <= 17; i++){
			dishes.push(i);
		}
		std::cout << dishes.pop() << std::endl;
		std::cout << dishes.pop() << std::endl;
		std::cout << dishes.pop() << std::endl;
		std::cout << dishes.pop() << std::endl;
	}catch(const std::exception& e){
		std::cerr << e.what();
		return -1;
	}

	return 0;
}
