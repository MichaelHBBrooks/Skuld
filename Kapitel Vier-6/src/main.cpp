/**
 * Write an algorithm to find the 'next' node (i.e. in-order successor) of a given node in a binary
 * search tree. You may assume that each node has a link to its parent.
 *
 * Programmer response:
 * This sounds like I'll need to tweak the binary tree file I created. I'll need to create parent
 * references.
 *
 * It's a binary search tree. The in-order successor probably means the next value greater than or
 * equal to the given node.
 *
 * If a right branch exists, go right then left as far as possible.
 * If not, find a parent where we did not come from its right child. If we come from the right, it
 * means the previous node is greater than the parent. If we come from the left, it means the parent
 * is the in-order successor.
 * It's also possible there is no successor if we go all the way up to the root via right-side
 * children.
 */

#include<iostream>

#include"BinaryTree.h"

BinaryTreeNode* findSuccessor(BinaryTreeNode* node_);

int main(){
	BinaryTree tree;
	tree.insert(50);
	tree.insert(70);
	tree.insert(60);
	tree.insert(100);
	tree.insert(40);
	tree.insert(30);

	BinaryTreeNode* node1 = tree.root_->left_;
	BinaryTreeNode* next1 = findSuccessor(node1);
	std::cout << "Original node: " << node1->data_ << '\n'
			<< "Next node: " << next1->data_ << '\n';
	return 0;
}

BinaryTreeNode* findSuccessor(BinaryTreeNode* node_){
	if(node_ == NULL){
		return NULL;
	}
	BinaryTreeNode* next;
	if(node_->right_ != NULL){
		next = node_->right_;
		while(next->left_ != NULL){
			next = next->left_;
		}
	}else{
		BinaryTreeNode* prev = node_;
		next = node_->parent_;
		while(next != NULL && next->left_ != prev){
			prev = next;
			next = next->parent_;
		}
	}
	return next;
}
