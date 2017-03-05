#include<iostream>

#include"BinaryTree.h"

BinaryTreeNode::BinaryTreeNode(){
	left_ = NULL;
	right_ = NULL;
	parent_ = NULL;
	data_ = 0;
}

BinaryTreeNode::BinaryTreeNode(int new_data_){
	left_ = NULL;
	right_ = NULL;
	parent_ = NULL;
	data_ = new_data_;
}

BinaryTreeNode::~BinaryTreeNode(){
	if(left_ != NULL){
		delete left_;
	}
	if(right_ != NULL){
		delete right_;
	}
}

BinaryTree::BinaryTree(){
	root_ = NULL;
}

BinaryTree::~BinaryTree(){
	if(root_ != NULL){
		delete root_;
	}
}

void BinaryTree::insert(int new_data_){
	if(root_ == NULL){
		root_ = new BinaryTreeNode(new_data_);
	}else{
		BinaryTree::insert(new_data_,root_);
	}
}

void BinaryTree::insert(int new_data_, BinaryTreeNode* leaf_){
	if(new_data_ < leaf_->data_){
		if(leaf_->left_ == NULL){
			leaf_->left_ = new BinaryTreeNode(new_data_);
			leaf_->left_->parent_ = leaf_;
		}else{
			insert(new_data_, leaf_->left_);
		}
	}else if(new_data_ >= leaf_->data_){
		if(leaf_->right_ == NULL){
			leaf_->right_ = new BinaryTreeNode(new_data_);
			leaf_->right_->parent_ = leaf_;
		}else{
			insert(new_data_, leaf_->right_);
		}
	}
}
