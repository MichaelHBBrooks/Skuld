/**
 * Implement an algorithm to find the kth to last element of a singly linked list.
 *
 * Programmer response:
 * Yet another reason to not like linked lists. They work nicely, but when you have to do
 * shenanigans like this, you really ought to reconsider your data storage. If only it was doubly
 * linked...
 *
 * I can think of a few ways to do this. I'd have to ask the interviewer a couple questions:
 *   1) Does our linked list store its size anywhere? It would make error checking easier.
 *   2) Are the nodes numbered at all? I'm guessing not since deleting is annoying to keep these
 *      updated.
 *
 * I'm assuming the answer is no for both questions.
 * The next question I have is how efficient do we want this? At the cost of memory, I can map the
 * linked list to an array of either the same size or in a stack of k elements in size. That way,
 * once I'm done traversing the linked list to the end, I can perform an O(1) operation to find the
 * entry and return it.
 *
 * On the other hand, if memory is too costly, we can traverse the list to find the size of the
 * list, then start from the beginning and traverse it one more time to find that kth to last
 * element.
 *
 * Since the interviewer isn't here to ask, I guess I'll code both?
 *
 * No... wait. All of that is dumb. I'll just use two iterators. One will traverse the linked list,
 * the second one will be set once k elements have been counted. When the traversing iterator
 * reaches the end, I'll have the end result right where I want it.
 */

#include<iostream>
#include"LinkedList.h"

Node* findElement1(LinkedList& list_, unsigned int from_end_);

int main(){
	LinkedList list;
	list.head = new Node(1);
	list.appendToTail(2);
	list.appendToTail(3);
	list.appendToTail(15);
	list.appendToTail(7);
	list.appendToTail(20);
	list.printLinkedList(*list.head);
	Node* kth_element = findElement1(list, 2);
	std::cout << "2nd from end is: " << kth_element->data << std::endl;

	return 0;
}

/**
 * In my mind, I'm going through base case scenarios:
 *   1) from_end is 0, list has only one element. Result happens to be the list's head.
 *   2) from_end is 0, list has numerous elements. Result should be that last element. This is an
 *      edge case scenario that is more efficient without a second node to increment. Just use itr.
 *   3) from_end is 1, list has only one element. Result should be NULL.
 *   3) from_end is larger than the size of the list.
 * @param list
 * @param from_end
 * @return NULL if the list is too short. Otherwise it counts 'from_end' elements from the end and
 *         returns that node.
 */
Node* findElement1(LinkedList& list_, unsigned int from_end_){
	Node* itr = list_.head;
	if(from_end_ == 0){
		while(itr->next != NULL){
			itr = itr->next;
		}
		return itr;
	}

	unsigned int count = 0;
	while(itr->next != NULL && count < from_end_){
		itr = itr->next;
		count++;
	}
	if(count < from_end_){
		return NULL;
	}
	Node* trailing_itr = list_.head;
	while(itr->next != NULL){
		trailing_itr = trailing_itr->next;
		itr = itr->next;
	}
	return trailing_itr;
}
