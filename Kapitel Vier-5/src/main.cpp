/**
 * Implement a function to check if a binary tree is a binary search tree.
 *
 * Programmer response:
 * Binary tree = basically any tree with two child nodes. Their values don't matter.
 * Binary Search tree = a tree whose left child is <= to the parent node and right child is >= to
 * the parent.
 *
 * I'm thinking a depth first search makes the most sense here. Work our around recursively until
 * we find a node that doesn't fit a binary search tree's criteria or we run out of nodes.
 *
 * The tricky part is that just because the left child is lesser than its parent doesn't mean it's
 * also less than its grandparent or root. This is tricky. How to track a value against all parent
 * nodes before it...
 *
 * Is it as simple as making sure it's in between the parent and grandparent values?
 *
 * How strict of an implementation of a binary search tree are we talking about here? They can lean
 * left or right. As in, all left children are <, but all right children are >=. If the parent node
 * is 5 and a left leaf is found to also be 5, is that okay?
 *
 * I looked at the solutions in the book. I like neither of them. Their implementation of using an
 * array and checking if it's sorted doesn't work when duplicate values are in the tree.
 *
 * Their second implementation isn't thorough enough, here's why:
 * They're checking each value against the previous value. But this means we can put the BST into
 * an impossible state. Consider this:
 *     5
 *      \
 *       6
 *      / \
 *     3   7
 *        /
 *       4
 * Is this a valid Binary Search Tree? This should be impossible to build. That 4 should be a child
 * of 3, not the 7. Yet their implementation won't detect that.
 *
 * I feel that this scenario should fail, but it would be up to the interviewer to determine what is
 * good enough. I would point out that this isn't as easy to resolve without making compromises.
 *
 * For the sake of writing a proper program, I will use their second algorithm since it was closest
 * to what I had in mind before looking in the back of the book.
 *
 * ... and after writing my code, I understand what they're doing would actually catch the scenario
 * I gave. It would check in the sequence of: 5 <= 3 <= 6 <= 4, then fail before it checked 7.
 *
 * And this is why I'm doing these questions.
 */

#include<iostream>

#include"BinaryTree.h"

struct IntWrap{
	int value_;
};

bool isBinarySearchTree(const BinaryTree& tree_);
bool checkLeaf(BinaryTreeNode* node_, IntWrap* prev_value_);
bool checkLeaf2(BinaryTreeNode* node_, IntWrap* prev_value_);

int main(){
	BinaryTree good_tree;
	good_tree.insert(10);
	good_tree.insert(5);
	std::cout << "Is the good tree good? " << std::boolalpha << isBinarySearchTree(good_tree) << '\n';
	return 0;
}

bool isBinarySearchTree(const BinaryTree& tree_){
	if(tree_.root_ == NULL){
		return true;
	}
	IntWrap *prev_value = NULL;
	return checkLeaf(tree_.root_, prev_value);
}

bool checkLeaf(BinaryTreeNode* node_, IntWrap* prev_value_){
	if(node_ == NULL){
		return true;
	}

	if(!checkLeaf(node_->left_, prev_value_)){
		return false;
	}

	if(prev_value_ != NULL && node_->data_ <= prev_value_->value_){
		return false;
	}

	if(prev_value_ == NULL){
		prev_value_ = new IntWrap;
	}
	prev_value_->value_ = node_->data_;
//	std::cout << prev_value_->value_ << std::endl;

	if(!checkLeaf(node_->right_, prev_value_)){
		return false;
	}

	return true;
}

bool checkLeaf2(BinaryTreeNode* node_, IntWrap* prev_value_){
	if(prev_value_ == NULL){
		std::cout << "Null\n";
	}else{
		std::cout << "class defined.\n";
	}
	return true;
}
