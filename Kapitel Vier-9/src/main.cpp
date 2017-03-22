/**
 * You are given a binary tree in which each node contains a value. Design an algorithm to print all
 * paths which sum to a given value. The path does not need to start or end at the root or a leaf,
 * but it must go in a straight line down.
 *
 * Programmer response:
 * Depth first search until you hit a value less than the sum. Once found, call a new function to
 * perform another depth first search adding each of the numbers together as we go. If the numbers
 * add up, add them to the list. This second function must inspect every branch for pass or fail.
 *
 * I didn't like this method when I started. And now that I've read the solution in the back of the
 * book, I can see there is a better way to do this. I believe my way will work, but it can take a
 * lot longer to accomplish it. As my method traverses downward, the findSums call is repeatedly
 * called if the values are less than the sum. The book's method traverses the tree, but it adds the
 * numbers repeatedly. It's going to take a while to do its job, but I feel it won't take nearly as
 * long in most scenarios.
 *
 * Upon even further thought, the idea that negative ints were being permitted is what throws my
 * solution out the window. For example, if we searched for 54 and I saw the first value is 56, my
 * algorithm ignores it. One of its leafs might be -2 however and my code wouldn't catch this sum.
 * Had I known this, my approach would have to be entirely different.
 *
 * I suspect the reason I discounted negative values is because all of the previous questions only
 * dealt with positive integers. This threw me off. My functions will only work with positive
 * integers.
 */

#include<iostream>
#include<vector>
#include"BinaryTree.h"

using namespace std;

void traverseTree(const BinaryTreeNode* node_, int sum_, vector<vector<int>>& list_);
void findSums(const BinaryTreeNode* node_, int sum_, vector<vector<int>>& list_, vector<int>& ongoing_list_);

int main(int argc, char* argv[]){
	BinaryTree some_tree;
	vector<vector<int>> sum_list;

}

void traverseTree(const BinaryTreeNode* node_, int sum_, vector<vector<int>>& list_){
	if(node_ == NULL){
		return;
	}
	if(node_->data_ == sum_){
		vector<int> one_entry;
		one_entry.push_back(sum_);
		list_.push_back(one_entry);
	}
	if(node_->data_ < sum_){
		vector<int> temp_list;
		temp_list.push_back(node_->data_);
		findSums(node_->left_, sum_, list_, temp_list);
		findSums(node_->right_, sum_, list_, temp_list);
	}
	traverseTree(node_->left_, sum_, list_);
	traverseTree(node_->right_, sum_, list_);
}

void findSums(const BinaryTreeNode* node_, int sum_, vector<vector<int>>& list_, vector<int>& ongoing_list_){
	if(node_ == NULL){
		return;
	}
	int ongoing_sum = 0;
	for(auto itr : ongoing_list_){
		ongoing_sum += itr;
	}
	ongoing_sum += node_->data_;
	if(ongoing_sum == sum_){
		ongoing_list_.push_back(node_->data_);
		list_.push_back(ongoing_list_);
		//  If negative values are permitted, these must be uncommented.
//		findSums(node_->left_, sum_, list_, ongoing_list_);
//		findSums(node_->right_, sum_, list_, ongoing_list_);
		ongoing_list_.pop_back();  //  Clean up in case an earlier branch needs to be inspected.
	}else if(ongoing_sum < sum_){
		ongoing_list_.push_back(node_->data_);
		findSums(node_->left_, sum_, list_, ongoing_list_);
		findSums(node_->right_, sum_, list_, ongoing_list_);
		ongoing_list_.pop_back();
	}
}
