/**
 * Implement a function to check if a binary tree is balanced. For the purposes of this question, a
 * balanced tree is defined to be a tree such that the heights of the two subtrees of any node never
 * differ by more than one.
 *
 * Programmer response:
 * I need to make a binary tree class first.
 * Recursion is fun. After I figured out the base case I was able to work my way back to how it
 * should get added up.
 * I didn't need to use the max function from the algorithm library.
 * Likewise, I didn't need to use a shorthand if statement for the return value for isBalanced, I
 * could've used the abs() function.
 *
 * My insert function is designed to put values lesser than the root to the left child and values
 * equal to or greater than the root to the right child. Hence why adding 55 multiple times branches
 * the tree off to the right heavily.
 */

#include<algorithm>
#include<iostream>

#include"BinaryTree.h"

bool isBalanced(const BinaryTree& tree_);
unsigned int getDepth(BinaryTreeNode* node_,  unsigned int depth_);

int main(){
	BinaryTree bonzai;

	bonzai.insert(50);
	bonzai.insert(45);
	bonzai.insert(55);
//	bonzai.insert(55);
	bonzai.insert(55);

	std::cout << bonzai.root_->data_ << std::endl;
	std::cout << bonzai.root_->left_->data_ << std::endl;
	std::cout << bonzai.root_->right_->data_ << std::endl;

	if(isBalanced(bonzai)){
		std::cout << "Balanced!\n";
	}else{
		std::cout << "Not balanced.\n";
	}

	return 0;
}

bool isBalanced(const BinaryTree& tree_){
	BinaryTreeNode* root = tree_.root_;
	if(root == NULL){
		return true;
	}
	unsigned int left_depth = getDepth(root->left_, 0);
	unsigned int right_depth = getDepth(root->right_, 0);

	std::cout << "Left depth: " << left_depth << std::endl
			<< "Right depth: " << right_depth << std::endl;
	return left_depth > right_depth ? left_depth-right_depth <= 1 : right_depth-left_depth <= 1;
}

unsigned int getDepth(BinaryTreeNode* node_, unsigned int depth_){
	if(node_ == NULL){
		return depth_;
	}
	unsigned int left_depth = getDepth(node_->left_, depth_+1);
	unsigned int right_depth = getDepth(node_->right_, depth_+1);
	return std::max(left_depth,right_depth);
}
