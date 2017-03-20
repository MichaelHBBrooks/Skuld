/**
 * You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes.
 * Create an algorithm to decide if T2 is a subtree of T1.
 *
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is
 * identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
 *
 * Programmer response:
 * Contriving an example for this would be annoying to set up. I may have to work with smaller size
 * trees.
 *
 * After looking at the back of the book for the solution... damn. I like the elegance of the first
 * solution of comparing pre-order and in-order substrings, but I don't think I would've come up
 * with that first. I should keep it in mind though as a viable solution.
 *
 * The book's second solution is more in line with what I was thinking: we only need to compare the
 * root of the smaller tree to nodes in the first tree. If a match is found, inspect it further to
 * see if there's a match.
 *
 * Since contriving millions of nodes together for one tree and hundreds of thousands of nodes for
 * another tree is a bit more ambitious than what I'd like to accomplish here, I'll settle for a
 * demonstration of the code.
 */

#include<iostream>
#include"BinaryTree.h"

bool containsTree(const BinaryTree& main_, const BinaryTree& sub_);
bool subTree(const BinaryTreeNode* main_node_, const BinaryTreeNode* sub_root_);
bool matchTree(const BinaryTreeNode* main_node_, const BinaryTreeNode* sub_node_);

int main(int argv, char* argc[]){
	BinaryTree tree1;
	BinaryTree tree2;

	bool contains = containsTree(tree1, tree2);
	std::cout << "Does tree1 contain tree2? " << std::boolalpha << contains << std::endl;
	return 0;
}

bool containsTree(const BinaryTree& main_, const BinaryTree& sub_){
	if(sub_.root_ == NULL){
		return true;
	}

	return subTree(main_.root_, sub_.root_);
}

bool subTree(const BinaryTreeNode* main_node_, const BinaryTreeNode* sub_root_){
	if(main_node_ == NULL){
		return false;
	}
	if(main_node_->data_ == sub_root_->data_){
		//  We have a match for the root, but does the rest of the tree match?
		if(matchTree(main_node_, sub_root_)){
			return true;
		}
	}
	return (subTree(main_node_->left_, sub_root_) || subTree(main_node_->right_, sub_root_));
}

bool matchTree(const BinaryTreeNode* main_node_, const BinaryTreeNode* sub_node_){
	//  If any null nodes are detected, we want to stop traversing the tree.
	if(main_node_ == NULL && sub_node_ == NULL){
		return true;
	}
	if(main_node_ == NULL || sub_node_ == NULL){
		return false;
	}
	if(main_node_->data_ != sub_node_->data_){
		return false;
	}
	//  If we reach here, then the tree hasn't mismatched yet, but there are more nodes to check.
	return (matchTree(main_node_->left_, sub_node_->left_) &&
			matchTree(main_node_->right_, sub_node_->right_));
}
