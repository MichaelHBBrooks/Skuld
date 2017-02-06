/**
 * Implement an algorithm to delete a node in the middle of a singly linked list, given only access
 * to that node.
 * EXAMPLE
 * Input: the node c from the linked list a->b->c->d->e
 * Result: nothing is returned, but the new linked list looks like a->b->d->e
 *
 * Programmer response:
 * I feel bad about this one. I immediately recognized the problem that you can't modify the
 * previous node's data to point to a different spot in the sequence.
 *
 * I admit that I looked in the back of the book for clarification since the question was a little
 * terse. I didn't realize that they were looking for me to copy data from the next node, place it
 * in the current node, then delete the next node.
 *
 * This solution is extremely bad and I can't believe this would be a realistic scenario. It would
 * only result in very bad things. Leaving aside the scenario that you cannot mark delete the last
 * node in the linked list this way, this also means any pointers to that old node would become
 * corrupt. This solution would not instill confidence in the system! I'd have to question why we're
 * using a singly linked list in the first place.
 *
 * Side note: I decided to harden the error checking a bit more since it seemed like a requirement
 * for this question.
 */

#include<iostream>
#include<stdexcept>
#include"LinkedList.h"

void poorlyDeleteNode(Node* some_node_);

int main(){
	LinkedList list;
	list.head = new Node(1);
	list.appendToTail(2);
	list.appendToTail(3);
	list.appendToTail(15);
	list.appendToTail(7);
	list.appendToTail(20);
	list.printLinkedList(*list.head);
	try{
		poorlyDeleteNode(list.head->next);  //  Kill the second node.
		list.printLinkedList(*list.head);
	}catch(std::runtime_error& error){
		std::cerr << error.what() << std::endl;
	}catch(std::invalid_argument& error){
		std::cerr << error.what() << std::endl;
	}

	try{
		poorlyDeleteNode(list.head->next->next->next->next);  //  Kill the last node (20).
		list.printLinkedList(*list.head);
	}catch(std::runtime_error& error){
		std::cerr << error.what() << std::endl;
	}catch(std::invalid_argument& error){
		std::cerr << error.what() << std::endl;
	}

	return 0;
}

void poorlyDeleteNode(Node* some_node_){
	if(some_node_ == NULL){
		throw std::invalid_argument("Unable to delete NULL pointer");
	}
	Node* innocent_bystander = some_node_->next;
	if(innocent_bystander == NULL){
		throw std::runtime_error("Unable to delete node.");
	}
	some_node_->data = innocent_bystander->data;
	some_node_->next = innocent_bystander->next;
	delete(innocent_bystander);
}
