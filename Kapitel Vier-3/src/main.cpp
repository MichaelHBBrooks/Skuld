/**
 * Given a sorted (increasing order) array with unique integer elements, write an algorithm to
 * create a binary search tree with minimal height.
 *
 * Programmer response:
 * Okay, so binary search trees are different from binary trees. The left nodes must be <= the
 * parent node and the right nodes must be >= the parent node.
 * Most of the time the binary search trees are implemented with the left side is merely LESSER THAN
 * (<)the parent while the right side is GREATER THAN OR EQUAL TO (>=) the parent.
 * I've already implemented this in my earlier code, so I'll continue to use it.
 *
 * This sorted array has unique numbers, so there are no duplicate integers anywhere in it.
 *
 * The array is increasing in order, but that doesn't mean it's balanced. So it might look like:
 *   1, 95, 96, 97, 98, 99, 100
 * Does that matter?
 * Pick the middle value as the key. Then for each half split it down the middle again.
 *      97
 *     /  \
 *   95   99
 *  /\     /\
 * 1  96  98 100
 *
 * That should work. Divide each in half until there's nothing left.
 */

#include"BinaryTree.h"

#include<iostream>
#include<vector>

BinaryTree createBalancedBinaryTree(const std::vector<int>& list_);
void buildTree(BinaryTree& tree_, const std::vector<int>& list_, int start_, int end_);

int main(){
	std::vector<int> list1 = { 1, 95, 96, 97, 98, 99, 100 };
	BinaryTree list1_tree = createBalancedBinaryTree(list1);
	return 0;
}

BinaryTree createBalancedBinaryTree(const std::vector<int>& list_){
	BinaryTree tree;
	if(list_.size() == 0){
		return tree;
	}
	buildTree(tree, list_, 0, list_.size() - 1);  //  Remember the size can cause a one off error.
	return tree;
}

void buildTree(BinaryTree& tree_, const std::vector<int>& list_, int start_, int end_){
	std::cout << "Range: " << start_ << '-' << end_ << std::endl;
	if(end_ == start_){
		tree_.insert(list_[end_]);
		std::cout << "Inserting array #" << end_ << ": " << list_[end_] << std::endl;
	}else{
		int middle = (end_ + start_) / 2;
		tree_.insert(list_[middle]);
		std::cout << "Inserting array #" << middle << ": " << list_[middle] << std::endl;
		buildTree(tree_, list_, middle + 1, end_);
		buildTree(tree_, list_, start_, middle - 1);
	}
}
