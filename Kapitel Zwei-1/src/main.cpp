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
 * using them. I need to harden my knowledge on memory management.
 */

#include<iostream>
#include<map>
#include"LinkedList.h"

void pruneList(LinkedList& list);
void inefficientPruneList(LinkedList& list);

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

	LinkedList list2;
	list2.head = new Node(100);
	list2.appendToTail(101);
	list2.appendToTail(101);  //  Duplicate item.
	list2.appendToTail(102);
	list2.appendToTail(103);
	list2.appendToTail(103);  //  Duplicate item.
	list2.printLinkedList(*list2.head);
	inefficientPruneList(list2);
	list2.printLinkedList(*list2.head);

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

/**
 * For each element, traverse the entire linked list to guarantee there are no duplicates. If a
 * duplicate is found, remove it. This is done without buffers and is really, really inefficient.
 * @param list
 */
void inefficientPruneList(LinkedList& list){
	if(list.head == NULL){
		return;
	}
	for(Node* itr1 = list.head; itr1 != NULL; itr1 = itr1->next){
		Node* previous_node = itr1;
		Node* itr2 = itr1->next;
		while(itr2 != NULL){
			if(itr2->data == itr1->data){
				//  Duplicate found!
				previous_node->next = itr2->next;
				delete itr2;
			}else{
				previous_node = itr2;
			}
			itr2 = previous_node->next;
		}
	}
}
