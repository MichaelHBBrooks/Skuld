/**
 * Given a binary tree, design an algorithm which creates a linked list of all the nodes at each
 * depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 *
 * Programmer response:
 * Why, hello there, breadth first search.
 *
 * I had a good idea of what to do, but using a vector of a forward_list of my BinaryTreeNode*
 * seemed a little far fetched. I'd have to ask the interviewer what format they really expected the
 * data to be returned as.
 *
 * After looking quickly at the solution in the back of the book, I saw they had an implementation
 * for depth first search and breadth first search. Furthermore, it confirmed what I was thinking
 * about the vector<forward_list<BinaryTreeNode*>> idea.
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
	for(unsigned int x = 0; x < depth_lists.size(); x++){
		cout << x << ": ";
		for(auto y: depth_lists[x]){
			cout << y->data_ << ' ';
		}
		cout << endl;
	}

	return 0;
}

vector<forward_list<BinaryTreeNode*>> separateDepths(BinaryTree& tree_){
	vector<forward_list<BinaryTreeNode*>> depth_lists;
	forward_list<BinaryTreeNode*> current;
	if(tree_.root_ == NULL){
		return depth_lists;
	}
	current.push_front(tree_.root_);
	while(!current.empty()){
		depth_lists.push_back(current);
		forward_list<BinaryTreeNode*> parents = current;
		current.clear();
		for(auto itr: parents){
			if(itr->left_ != NULL){
				current.push_front(itr->left_);
			}
			if(itr->right_ != NULL){
				current.push_front(itr->right_);
			}
		}
	}
	return depth_lists;
}
