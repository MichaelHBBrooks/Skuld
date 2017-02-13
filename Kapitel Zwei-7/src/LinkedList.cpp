#include<iostream>

#include"LinkedList.h"

Node::Node(int new_data){
	data = new_data;
	next = NULL;
}

Node::Node(){
	data = 0;
	next = NULL;
}


LinkedList::LinkedList(){
	head = NULL;
}

LinkedList::~LinkedList(){
	Node* this_node = head;
	while(this_node != NULL){
		Node* next_node = this_node->next;
		delete this_node;
		this_node = next_node;
	}
}

void LinkedList::appendToTail(int new_data){
	Node* new_tail = new Node(new_data);
	Node* n = head;
	if(n == NULL){
		head = new_tail;
	}else{
		while(n->next != NULL){
			n = n->next;
		}
		n->next = new_tail;
	}
}

void LinkedList::printLinkedList(const Node& some_node){
	Node* n = some_node.next;
	std::cout << some_node.data << ' ';
	while(n != NULL){
		std::cout << n->data << ' ';
		n = n->next;
	}
	std::cout << std::endl;
}
