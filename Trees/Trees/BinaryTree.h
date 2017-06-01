#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"Node.h"

class BinaryTree
{
private:
	Node* root;
	void addDataHelper(Node* node, int data);
	void inOrder(Node* root);
	void preOrder(Node* root);
	void postOrder(Node* root);
	int findMaxHelper(Node* root);
	int searchHelperRec(Node* root, int data);
	int findSizeHelper(Node* root);
	int findHeightHelper(Node* root);
public:
	BinaryTree();
	void addData(int value);
	void inOrderTrav();
	void preOrderTrav();
	void postOrderTrav();
	void levelOrderTrav();
	void findMax();
	void search(int data);
	void findSize();
	void levelOrderReverse();
	void findHeight();
	void maxLevelSum();
};

#endif
