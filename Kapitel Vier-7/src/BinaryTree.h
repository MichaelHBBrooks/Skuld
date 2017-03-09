#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class BinaryTreeNode{
public:
	BinaryTreeNode();
	BinaryTreeNode(int new_data_);
	~BinaryTreeNode();

	BinaryTreeNode* left_;
	BinaryTreeNode* right_;
	BinaryTreeNode* parent_;
	int data_;
};

class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int new_data_);
	BinaryTreeNode search(int find_data_);

	BinaryTreeNode* root_;

private:
	void insert(int new_data_, BinaryTreeNode* leaf);
};



#endif /* BINARYTREE_H_ */
