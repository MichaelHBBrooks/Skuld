/**
 * Implement a MyQueue class which implements a queue using two stacks.
 *
 * Programmer response:
 * Stacks = FILO. First in, last out.
 * Queues = FIFO. First in, first out.
 *
 * To make a queue using two stacks sounds tricky.
 *
 * Which functions do I need to support? My half assed implementation of a stack isn't fully defined
 * as it is, so adding a queue will likely have similar limitations.
 *
 * This feels like it's going to be extremely inefficient unless I can come up with some sort of
 * clever mechanism to do things in less than O(n^2) time or whatever.
 *
 * I suppose I could treat it like moving pringle chips between two cans. At the start, if you want
 * to push data, that can be done in O(1) time no problem. If you switch to popping values, then the
 * values in one stack need to be shunted to the other stack so the first entry added can be popped
 * out. Then when you want to push again, they get shunted back into the first can so the data can
 * be added to the end.
 * This idea can work, but a worse case scenario is when you repeatedly push and pop sequentially.
 * Every time there is a transition from one action to the other, things need to get shunted around.
 *
 * After coding this, I kinda like this question. It's inefficient as hell and should never be used
 * in the wild, but it shows what a determined, blind programmer can do when given tools to do bad
 * things.
 */

#include<iostream>

#include"Stack.h"

class MyQueue{
	Stack pushing_stack_;
	Stack popping_stack_;
public:
	MyQueue(){}

	void push(const int& new_data_){
		while(popping_stack_.head_ != NULL){
			pushing_stack_.push(popping_stack_.pop());
		}
		pushing_stack_.push(new_data_);
	}

	int pop(){
		while(pushing_stack_.head_ != NULL){
			popping_stack_.push(pushing_stack_.pop());
		}
		return popping_stack_.pop();
	}

	int peek(){
		while(pushing_stack_.head_ != NULL){
			popping_stack_.push(pushing_stack_.pop());
		}
		return popping_stack_.peek();
	}

	bool isEmpty(){
		return popping_stack_.isEmpty() && pushing_stack_.isEmpty();
	}
};

int main(){
	MyQueue q;
	for(int x = 0; x < 5; x++){
		q.push(x);
	}
	while(!q.isEmpty()){
		std::cout << q.pop() << std::endl;
	}
	return 0;
}
