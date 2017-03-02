/**
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes at each
 * depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 *
 * Programmer response:
 * Why, hello there, breadth first search.
 */

#include<iostream>
#include<forward_list>
#include<queue>
#include<vector>

#include"BinaryTree.h"

using namespace std;

vector<forward_list<BinaryTreeNode*>> separateDepths(BinaryTree& tree_);

int main(){
	BinaryTree tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(1);
	tree.insert(4);
	tree.insert(7);
	tree.insert(6);
	tree.insert(8);

	vector<forward_list<BinaryTreeNode*>> depth_lists = separateDepths(tree);


	return 0;
}

vector<forward_list<BinaryTreeNode*>> separateDepths(BinaryTree& tree_){
	vector<forward_list<BinaryTreeNode*>> depth_lists;
	forward_list<BinaryTreeNode*> current;
	if(tree_.root_ == NULL){
		return depth_lists;
	}
	current.push_front(tree_.root_);
//	while(!current.empty()){
//		depth_lists.push_back(current);
//		forward_list<BinaryTreeNode*> parents = current;
//		current = new forward_list<BinaryTreeNode*>;
//
//	}
	return depth_lists;
}
