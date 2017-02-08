/**
 * You have two numbers represented by a linked list, where each node contains a single digit. The
 * digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a
 * function that adds the two numbers and returns the sum as a linked list.
 *
 * Programmer response:
 * This sounds easy compared to the last one I had.
 * I'm assuming the numbers are in base 10.
 * I will likely just start adding the numbers up, carrying the 1s and multiply a value by 10 per
 * iteration.
 *
 * And now I just realized that my printLinkedList probably shouldn't be using a node reference. It
 * should just print the list's head value by default.
 *
 * After coding my solution, my linked list implementation is not fantastic. Ideally I could append
 * to the tail even if the head is not defined. In fact... screw it. I'll modify it so it works.
 * I removed the requirement to create the head as a new node prior to appending to the tail. I feel
 * that any serious implementation of a singly linked list would allow that. I also believe it would
 * track the location of the tail rather than search for it in O(n) time, but whatever. It's really,
 * really basic.
 */

#include<iostream>

#include"LinkedList.h"

LinkedList sum(const LinkedList& list1, const LinkedList& list2);

int main(){
	LinkedList list1;
	list1.head = new Node(7);
	list1.appendToTail(1);
	list1.appendToTail(6);
	list1.printLinkedList(*list1.head);

	LinkedList list2;
	list2.head = new Node(5);
	list2.appendToTail(9);
	list2.appendToTail(2);
	list2.printLinkedList(*list2.head);

	LinkedList x = sum(list1, list2);
	x.printLinkedList(*x.head);

	return 0;
}

LinkedList sum(const LinkedList& list1, const LinkedList& list2){
	LinkedList sum_list;
	bool carry_the_one = false;
	Node* digit1_node = list1.head;
	Node* digit2_node = list2.head;

	while(digit1_node != NULL || digit2_node != NULL){
		int x = digit1_node == NULL ? 0 : digit1_node->data;
		int y = digit2_node == NULL ? 0 : digit2_node->data;
		int digit_sum = (x + y + carry_the_one);
		carry_the_one = ((digit_sum/10) > 0);
		sum_list.appendToTail(digit_sum % 10);
		if(digit1_node != NULL){
			digit1_node = digit1_node->next;
		}
		if(digit2_node != NULL){
			digit2_node = digit2_node->next;
		}
	}
	if(sum_list.head == NULL){
		sum_list.head = new Node(0);
	}

	return sum_list;
}
