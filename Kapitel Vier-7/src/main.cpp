/**
 * Design an algorithm and write code to find the first common ancestor of two nodes in a binary
 * tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary
 * search tree.
 *
 * Programmer response:
 * Am I guaranteed the nodes are in the same tree?
 * For the sake of this exercise, I will assume yes. If it's not computationally difficult to check,
 * I will add it.
 *
 * Do these nodes have access to their parents?
 * I suspect I may look in the back of the book to get that specific answer, but I'll see what I can
 * do for now without knowing.
 *
 * If we have a pointer to the parent, then I suppose what I would do is:
 * 1) Set search_node to A.
 * 2) Set prev_node to NULL.
 * 3) Check all children of search_node, but skip prev_node (if it's NULL, search all children
 *    nodes).
 * 4) If node B is found, return search_node.
 * 5) If node B is not found, set prev_node to search_node. Set search_node to parent of
 *    search_node.
 * 6) Repeat from step 3.
 *
 * I may need two functions. One for moving up the parents and another to perform the actual
 * searches.
 *
 *
 * Without parents, this gets awfully annoying.
 * If I can't store nodes in a data structure, then I suppose a depth first search will be
 * necessary. I wouldn't be able to use a queue for the breadth first search.
 * I'd search until I found either node A or node B. Then... ugh. I could do a brutally inefficient
 * search starting from the root constantly.
 *
 *
 * After writing this, I'll be honest... I'm a little shocked it worked the first time it compiled.
 */

#include<iostream>

#include"BinaryTree.h"

BinaryTreeNode* findCommonAncestor(BinaryTreeNode* node_a_, BinaryTreeNode* node_b_);
BinaryTreeNode* searchFor(BinaryTreeNode* start_node_, BinaryTreeNode* prev_node_,
		BinaryTreeNode* searching_for_);
bool leafContains(BinaryTreeNode* start_, BinaryTreeNode* searching_for_);

int main(){
	/*  50
	 *   \
	 *    75
	 *    /
	 *   60
	 *   /\
	 * 55 65
	 *     \
	 *     70
	 */
	BinaryTree tree;
	tree.insert(50);
	tree.insert(75);
	tree.insert(60);
	tree.insert(55);
	tree.insert(65);
	tree.insert(70);
	BinaryTreeNode* node_a = tree.root_->right_->left_->left_;          //  55
	BinaryTreeNode* node_b = tree.root_->right_->left_->right_->right_; //  70
	std::cout << "Node A: " << node_a->data_ << '\n' << "Node B: " << node_b->data_ << '\n';
	BinaryTreeNode* node_c = findCommonAncestor(node_a, node_b);
	if(node_c == NULL){
		std::cout << "No common ancestor found.\n";
	}else{
		std::cout << "Common Ancestor: " << node_c->data_ << '\n';
	}

	return 0;
}

BinaryTreeNode* findCommonAncestor(BinaryTreeNode* node_a_, BinaryTreeNode* node_b_){
	return searchFor(node_a_, NULL, node_b_);
}

BinaryTreeNode* searchFor(BinaryTreeNode* start_node_, BinaryTreeNode* prev_node_,
		BinaryTreeNode* searching_for_){
	if(start_node_ == NULL){
		return NULL;
	}else if(start_node_ == searching_for_){
		return start_node_;
	}
	if(start_node_->left_ != prev_node_){
		if(leafContains(start_node_->left_, searching_for_)){
			return start_node_;
		}
	}
	if(start_node_->right_ != prev_node_){
		if(leafContains(start_node_->right_, searching_for_)){
			return start_node_;
		}
	}
	return searchFor(start_node_->parent_, start_node_, searching_for_);
}

bool leafContains(BinaryTreeNode* start_, BinaryTreeNode* searching_for_){
	if(start_ == NULL){
		return false;
	}else if(start_ == searching_for_){
		return true;
	}
	if(leafContains(start_->left_,searching_for_)){
		return true;
	}else if(leafContains(start_->right_, searching_for_)){
		return true;
	}
	return false;
}
