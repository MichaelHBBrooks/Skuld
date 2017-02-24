/**
 * Implement a function to check if a binary tree is balanced. For the purposes of this question, a
 * balanced tree is defined to be a tree such that the heights of the two subtrees of any node never
 * differ by more than one.
 *
 * Programmer response:
 * I need to make a binary tree class first.
 */

#include<iostream>

#include"BinaryTree.h"

int main(){
	BinaryTree bonzai;

	bonzai.insert(50);
	bonzai.insert(45);
	bonzai.insert(55);

	std::cout << bonzai.root_->data_ << std::endl;
	std::cout << bonzai.root_->left_->data_ << std::endl;
	std::cout << bonzai.root_->right_->data_ << std::endl;

	return 0;
}
