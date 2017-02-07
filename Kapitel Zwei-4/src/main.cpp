/**
 * Write code to partition a linked list around a value x, such that all nodes less than x come
 * before all nodes greater than or equal to x.
 *
 * Programmer response:
 * The order before and after x does not really matter, just as long as there's a clear partition.
 * I'm thinking maybe some pointers?
 *
 * Looking at the solutions in the book, my initial algorithm looked more similar to the first
 * suggested solution. I was going to end up using a bunch of pointers to hack the list apart and
 * reinsert the value in another portion of the list. This became complicated and felt like
 * unnecessary work.
 *
 * I used the book's second solution. It feels wrong to use their algorithm that I did not think
 * of by myself. It made no sense at first because the first iteration through the list makes the
 * head point to itself. Manually setting it to NULL makes sense, but all this rearranging of data
 * feels inefficient.
 *
 * I hope I don't get asked this question since it feels unrelatable to real world scenarios. It is
 * a tricky question, so I do consider it legitimate. I've learned that these interview questions
 * might be convoluted, but that doesn't matter. The point is solving them.
 */

#include<iostream>

#include"LinkedList.h"

void partitionList(LinkedList& list, int num);

int main(){
	LinkedList list;
	list.head = new Node(1);
	list.appendToTail(3);
	list.appendToTail(15);
	list.appendToTail(7);
	list.appendToTail(2);
	list.appendToTail(20);
	list.printLinkedList(*list.head);
	partitionList(list,5);
	list.printLinkedList(*list.head);

	return 0;
}

void partitionList(LinkedList& list, int num){
	Node* new_head = list.head;
	Node* new_tail = list.head;
	Node* itr = list.head;
	while(itr != NULL){
		Node* next = itr->next;
		if(itr->data < num){
			itr->next = new_head;
			new_head = itr;
		}else{
			new_tail->next = itr;
			new_tail = itr;
		}
		itr = next;
	}
	new_tail->next = NULL;
	list.head = new_head;
}
