#include<iostream>
#include<limits>

#include"Stack.h"

Node::Node(){
	next_ = NULL;
	data_ = 0;
}

Stack::Stack(const int& new_name_) : name_(new_name_){
	head_ = NULL;
}

int Stack::pop(){
	if(head_ == NULL){
		throw std::runtime_error("Unable to pop empty list.");
	}
	int x = head_->data_;
	Node* popped_node = head_;
	head_ = head_->next_;
	delete popped_node;
	return x;
}

void Stack::push(const int& pushed_data_){
	Node* new_head = new Node;
	new_head->next_ = head_;
	new_head->data_ = pushed_data_;
	head_ = new_head;
}

int Stack::peek(){
	if(head_ == NULL){
		return std::numeric_limits<int>::max();
	}
	return head_->data_;
}

bool Stack::isEmpty(){
	return head_ == NULL ? true : false;
}
