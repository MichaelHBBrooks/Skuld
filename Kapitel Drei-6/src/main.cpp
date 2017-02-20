/**
 * Write a program to sort a stack in ascending order (with biggest items on top). You may use at
 * most one additional stack to hold items, but you may not copy the elements into any other data
 * structure (such as an array). The stack supports the following operations: push, pop, peek, and
 * isEmpty.
 *
 * Programmer response:
 * Sorting a stack in ascending order. I can use one additional stack.
 * What about using a temporary int? It's not exactly a structure...
 * This is a sorting algorithm. And it's going to be ugly.
 * Again, I'm thinking of pringle chips. One can full, the other is empty.
 *
 * Pop the top value into a temp int.
 * Start popping can 1 into can 2 until the temp int is in between the values of the two stacks.
 * Push the temp int into can 2, pop can 1 into can 2, pop can 1 again and put into temp int...
 * This is getting annoying to detail.
 * Basically, can 2 should always be sorted, but can 1 is a mystery until it is empty and in can 2.
 *
 *
 * After writing all this code, I feel like this is inefficient. I probably could've taken some
 * shortcuts somewhere, like maybe introducing a counter that kept track of how far I went without
 * assigning a value to temp. That way once I sorted a value into the sorted stack, I could quickly
 * go back to where I left off in stack_. It's functional without that extra math.
 *
 * Looking at the back of the book for their solution, I see they used two while loops. If there's
 * one thing I've learned from my job, it's that you rarely want to iterate on a structure you're
 * actively manipulating. It works here because they keep it tight though... it looks prettier than
 * my solution.
 */

#include<iostream>

#include"Stack.h"

void sortStack(Stack& stack_);

int main(){
	Stack disorganized_stack;
	disorganized_stack.push(15);
	disorganized_stack.push(5);
	disorganized_stack.push(6);
	disorganized_stack.push(12);
	disorganized_stack.push(1);
	disorganized_stack.push(100);

	std::cout << "Organizing time!\n";
	sortStack(disorganized_stack);
	while(disorganized_stack.head_ != NULL){
		std::cout << disorganized_stack.pop() << std::endl;
	}
	return 0;
}

void sortStack(Stack& stack_){
	if(stack_.isEmpty()){
		return;
	}
	Stack sorted;
	int temp = stack_.pop();
	while(!stack_.isEmpty()){
		if(sorted.isEmpty()){
			sorted.push(temp);
			temp = stack_.pop();
		}else if(sorted.peek() < temp){
			stack_.push(sorted.pop());
		}else{
			sorted.push(temp);
			temp = stack_.pop();
		}
	}
	//  In the end, there is still one value that hasn't been sorted. Since we need to pop values
	//  back into the original stack we started with, we can do some comparisons along the way.
	while(!sorted.isEmpty() && sorted.peek() < temp){
		stack_.push(sorted.pop());
	}
	stack_.push(temp);
	//  With the final value in place, shunt the remaining sorted values back into the original
	//  stack.
	while(!sorted.isEmpty()){
		stack_.push(sorted.pop());
	}
}
