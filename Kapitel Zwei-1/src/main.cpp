/**
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 *
 * Programmer response:
 * My first thought is having no buffer would truly suck and make linked lists very inefficient.
 * Removing duplicates with a buffer can be done by creating a new linked list, but that's a waste.
 * We do need a list that is at most size N in the worst case scenario.
 *
 * I have come to realize that I really should look into smart pointers for C++11. But how common
 * is it for companies to be using C++11? Any code base older than a decade would certainly not be
 * using them. I need to harden my
 */

#include<iostream>
#include<map>
#include"LinkedList.h"

void pruneList(LinkedList& list);

int main(int argc, char* argv[]){
	LinkedList list;
	list.head = new Node(1);
	list.appendToTail(2);
	list.appendToTail(3);
	list.appendToTail(15);
	list.appendToTail(7);
	list.appendToTail(3);   //  Duplicate item.
	list.appendToTail(15);  //  Duplicate item.
	list.appendToTail(20);
	list.printLinkedList(*list.head);
	pruneList(list);
	list.printLinkedList(*list.head);

	std::cout << "Exiting program.\n";

	return 0;
}

void pruneList(LinkedList& list){
	if(list.head == NULL){
		return;
	}
	std::map<int,bool> unique_items;
	Node* trailing_node = list.head;
	unique_items[trailing_node->data] = true;
	Node* itr = trailing_node->next;
	while(itr != NULL){
		if(unique_items[itr->data]){
			//  If a duplicate has been found, remove it. Do not advance the trailing node.
			std::cout << "Duplicate found: " << itr->data << std::endl;
			trailing_node->next = itr->next;
			delete itr;
		}else{
			//  No duplicate. Record it and move up the trailing node.
			unique_items[itr->data] = true;
			trailing_node = itr;
		}
		itr = trailing_node->next;
	}
}
