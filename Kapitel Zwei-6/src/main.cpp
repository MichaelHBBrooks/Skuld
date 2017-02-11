/**
 * Given a circular linked list, implement an algorithm which returns the node at the beginning of
 * the loop.
 * Example:
 *   Input: A -> B -> C -> D -> E -> C
 *   Output: C
 *
 * Programmer response:
 * This was seriously difficult. My first instinct was to create a map that would map pointers to a
 * boolean value. Reading the solution in the back of the book gave me an answer I would not be able
 * to give on the spot in an interview. I believe I would be able to puzzle it out if I had no time
 * constraints, but that's not going to happen.
 */

#include<iostream>

#include"LinkedList.h"

Node* findCircularNode(const LinkedList& list_);

int main(){
	//  First we need to create a circular linked list.
	LinkedList circular1;
	for(int x = 0; x<20; x++){
		circular1.appendToTail(x);
	}
	Node* broken_node = circular1.head;
	for(int y = 0; y<10; y++){
		broken_node = broken_node->next;
	}
	Node* tail = broken_node;
	while(tail->next != NULL){
		tail = tail->next;
	}
	circular1.printLinkedList(*circular1.head);
	//  Break the linked list!
	tail->next = broken_node;

	Node* found_node = findCircularNode(circular1);
	if(broken_node != NULL){
		std::cout << "Broken Node: " << broken_node->data << std::endl;
	}else{
		std::cout << "Broken Node: NULL\n";
	}
	if(found_node != NULL){
		std::cout << "Found Node: " << found_node->data << std::endl;
	}else{
		std::cout << "Found Node: NULL\n";
	}
	//  If the circular linked list isn't fixed, the destructor will go crazy and crash.
	tail->next = NULL;

	return 0;
}

Node* findCircularNode(const LinkedList& list_){
	if(list_.head == NULL){
		return NULL;
	}else if(list_.head == list_.head->next){
		return list_.head;
	}
	Node* slow = list_.head;
	Node* fast = list_.head;

	do{
		slow = slow->next;
		fast = fast->next;
		if(fast == NULL){
			return NULL;
		}
		fast = fast->next;
	}while(slow != fast && fast != NULL);
	if(fast == NULL){
		return NULL;
	}
	slow = list_.head;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
