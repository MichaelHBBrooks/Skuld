#ifndef STACK_H_
#define STACK_H_

class Node{
public:
	Node* next_;
	int data_;

	Node();
};

class Stack{
public:
	Node* head_;
	const int name_;

	Stack(const int& new_name_);

	int pop();
	void push(const int& pushed_data_);
	int peek();
	bool isEmpty();
};


#endif /* STACK_H_ */
