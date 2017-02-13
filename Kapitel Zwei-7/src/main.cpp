/**
 * Implement a function to check if a linked list is a palindrome.
 *
 * Programmer response:
 * This would be so much easier if it were a doubly-linked list.
 * I could attempt to find the midpoint.
 * Once there, I could start reversing the linked list.
 * After reversed, starting from the midpoint I traverse with two iterators: one from the head and
 * the other from the midpoint. Keep going until I find something doesn't match or until I hit the
 * end of the list with the midpoint traverser.
 *
 * All of this was done without looking at the back of the book for a solution. I feel it works, but
 * it does mutate the singly linked list. They might not be too happy about that, but it wasn't in
 * the rules not to do it.
 */

#include<iostream>

#include"LinkedList.h"

bool isPalindrome(const LinkedList& list_);

int main(){
	LinkedList list1;
	list1.appendToTail(5);
	list1.appendToTail(4);
	list1.appendToTail(3);
	list1.appendToTail(4);
	list1.appendToTail(5);
	list1.printLinkedList(*list1.head);

	if(isPalindrome(list1)){
		std::cout << "It's a palindrome!\n";
	}else{
		std::cout << "It is NOT a palindrome.\n";
	}

	return 0;
}

bool isPalindrome(const LinkedList& list_){
	if(list_.head == NULL){
		return false;
	}else if(list_.head->next == NULL){
		return true;
	}
	Node* slow_runner = list_.head;
	Node* fast_runner = list_.head;
	while(fast_runner->next != NULL){
		fast_runner = fast_runner->next;
		fast_runner = fast_runner->next;
		if(fast_runner == NULL){
			break;
		}
		slow_runner = slow_runner->next;
	}
	//  slow_runner is now at the halfway point.
	//  Even if fast_runner is NULL.
	//  Odd if fast_runner->next is NULL.
	//  Start the reversal process starting at the midpoint.
	Node* new_tail = slow_runner->next;
	Node* itr = slow_runner->next;
	while(itr != NULL){
		Node* swapper = itr;
		itr = itr->next;
		Node* temp = slow_runner->next;
		slow_runner->next = swapper;
		swapper->next = temp;
	}
	new_tail->next = NULL;

	Node* head_parser = list_.head;
	slow_runner = slow_runner->next;
	while(slow_runner != NULL){
		if(head_parser->data != slow_runner->data){
			return false;
		}
		head_parser = head_parser->next;
		slow_runner = slow_runner->next;
	}
	return true;
}
