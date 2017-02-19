/**
 * In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes
 * which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size
 * from top to bottom (i.e., each disk sits on top of an even larger one). You have the following
 * constraints:
 * 1) Only one disk can be moved at a time.
 * 2) A disk is slid off the top of one tower onto the next tower.
 * 3) A disk can only be placed on top of a larger disk.
 * Write a program to move the disks from the first tower to the last using stacks.
 *
 * Programmer response:
 * hahahaha... I've done this before in games, in math class, and in college. It's fun.
 * I've created the Stack.h and Stack.cpp files this time and I've added peek and isEmpty functions.
 * It's been a while since I've done some recursive functions. I'll change it up by solving this
 * with one.
 * I added names to the stacks (they're just ints) and printed out their movements as they go.
 */

#include<iostream>

#include"Stack.h"

void hanoi(Stack& source, Stack& temp, Stack& destination, unsigned int size);
void hanoi2(Stack& source, Stack& temp, Stack& destination, unsigned int size);

int main(){
	Stack tower1(1);
	Stack tower2(2);
	Stack tower3(3);
	unsigned int size = 5;

	//  First we set up the Tower of Hanoi. The smallest number will be on top of course.
	for(unsigned int x = size; x > 0; x--){
		tower1.push(x);
	}
	hanoi2(tower1, tower2, tower3, size);
	while(!tower3.isEmpty()){
		std::cout << tower3.pop() << std::endl;
	}
	return 0;
}

//  If source tower size is 1, move it to the target tower.
void hanoi(Stack& source, Stack& temp, Stack& destination, unsigned int size){
	if(size == 1){
		int val = source.pop();
		std::cout << "Assigning " << val << " from tower " << source.name_ << " to tower " << destination.name_ << std::endl;
		destination.push(val);
	}else{
		hanoi(source, destination, temp, size-1);
		int val2 = source.pop();
		std::cout << "Assigning " << val2 << " from tower " << source.name_ << " to tower " << destination.name_ << std::endl;
		destination.push(val2);
		hanoi(temp, source, destination, size-1);
	}
}

//  Without the instructions being sent to console.
void hanoi2(Stack& source, Stack& temp, Stack& destination, unsigned int size){
	if(size == 1){
		destination.push(source.pop());
	}else{
		hanoi2(source, destination, temp, size-1);
		destination.push(source.pop());
		hanoi2(temp, source, destination, size-1);
	}
}
