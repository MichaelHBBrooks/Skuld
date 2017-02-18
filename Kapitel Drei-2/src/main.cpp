/**
 * How would you design a stack which, in addition to push and pop, also has a function min which
 * returns the minimum element? Push, pop, and min should all operate in O(1) time.
 *
 * Programmer response:
 * This sounds super easy at first, but it gets tricky as values are pushed and popped off the
 * stack. As the values are popped off, the value of min can change. If all 3 functions operate in
 * O(1) time, then suddenly that means none of them are doing maintenance or sorting through to find
 * the minimum value every time.
 * This basically means I need some way of tracking a sorted list of all values in the stack.
 *
 * If I push values: 5, 4, 3, 2, 1, 2, 3, 4, 5... then we have one 1, two 2s, two 3s, etc.
 * Popping the stack means the min goes from 1 to 2. We have to pop the stack twice more before 3
 * is returned as the minimum. That means keeping track of the number of times an element appears.
 *
 * I suppose we could store the min value with every node in the stack?
 * For example, the nodes used to just contain their values:
 * [5] -> [4] -> [3] -> [2] -> [1] -> [2] -> [3] -> [4] -> [5]
 * Maybe now we can store the min alongside them?
 * In the form of [stack value, min value]
 * [5,5] -> [4,4] -> [3,3] -> [2,2] -> [1,1] -> [2,1] -> [3,1] -> [4,1] -> [5,1]
 * This would increase the memory space, but it would be O(1) time to track them down.
 */

#include<algorithm>
#include<iostream>
#include<stdexcept>

class Node{
public:
	Node(){
		next_ = NULL;
		min_ = 0;
		data_ = 0;
	}
	Node* next_;
	int min_;
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
		if(head_ == NULL){
			new_head->min_ = pushed_data_;
		}else{
			new_head->min_ = std::min(pushed_data_,head_->min_);
		}
		new_head->data_ = pushed_data_;
		head_ = new_head;
	}
	int min(){
		return head_->min_;
	}
};

int main(){
	Stack asdf;
	asdf.push(5);
	asdf.push(4);
	asdf.push(3);
	asdf.push(2);
	asdf.push(1);
	asdf.push(2);
	asdf.push(3);
	asdf.push(4);
	asdf.push(5);

	while(asdf.head_ != NULL){
		std::cout << "Min value: " << asdf.min() << std::endl;
		asdf.pop();
	}
	return 0;
}
