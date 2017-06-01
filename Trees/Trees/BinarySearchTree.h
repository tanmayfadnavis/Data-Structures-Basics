#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include"Node.h"

class BinarySearchTree
{
private:
	Node* root;
	void addDataHelper(Node* node, int data);
	void inOrder(Node* root);
	void preOrder(Node* root);
	void postOrder(Node* root);
	int findDataHelper(Node* root, int data);
	Node* findMinNode(Node* root);
	Node* deleteHelper(Node* root, int data);
public:
	BinarySearchTree();
	void addData(int value);
	void inOrderTrav();
	void preOrderTrav();
	void postOrderTrav();
	void levelOrderTrav();
	void findData(int data);
	void findMin();
	void deleteData(int data);
};

#endif
