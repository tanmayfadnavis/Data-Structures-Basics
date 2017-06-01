/*
	BinarySearchTree.cpp -> Implementation file for binary search tree.
	Author: Tanmay Fadnavis

*/


#include"BinarySearchTree.h"
#include <iostream>
#include <queue>
#include <stack>

//-------------------Default Constructor---------------------------------
BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}


//------------------Private function for adding data--------------------------
void BinarySearchTree::addDataHelper(Node* node, int value)
{
	if (node->data > value) {
		if (!node->left) {
			node->left = new Node(value);
		}
		else {
			addDataHelper(node->left, value);
		}
	}
	else {
		if (!node->right) {
			node->right = new Node(value);
		}
		else {
			addDataHelper(node->right, value);
		}
	}
}

//-------------------Public Function to add data/ create node-------------------------
void BinarySearchTree::addData(int value)
{
	if (root)
	{
		this->addDataHelper(root, value);
	}
	else
	{
		root = new Node(value);
	}

}

//------------------------Private In order traversal---------------------------------------
void BinarySearchTree::inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->left);
		std::cout << root->data << "\t";
		inOrder(root->right);
	}
}

//-----------------------Public In order Traversal--------------------------------------
void BinarySearchTree::inOrderTrav()
{
	this->inOrder(root);
}

//-----------------------------Private Pre Order traversal---------------------------------
void BinarySearchTree::preOrder(Node* root)
{
	if (root)
	{
		std::cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}

//----------------------------Public Function for pre order traversal------------------------
void BinarySearchTree::preOrderTrav()
{
	this->preOrder(root);

}

//-----------------------------Private Post Order Traversal---------------------------------
void BinarySearchTree::postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->data << "\t";
	}
}

//---------------------------Public Post order-------------------------------------------
void BinarySearchTree::postOrderTrav()
{
	this->postOrder(root);
}

//--------------------------Public Level Order Traversal---------------------------------
void BinarySearchTree::levelOrderTrav()
{
	Node* temp = nullptr;
	std::queue<Node *> q;

	if (root == nullptr)
		return;

	q.push(root);

	while (!q.empty())
	{
		temp = q.front();
		std::cout << temp->data << "\t";
		q.pop();

		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}

}

//------------------------------Public Find Data-----------------------------------------
void BinarySearchTree::findData(int data)
{
	if (this->findDataHelper(root, data))
		std::cout << "Data Found\n";
	else
		std::cout << "Data not found \n";

}


//----------------------------Private Find Data Helper---------------------------------------
int BinarySearchTree::findDataHelper(Node* root, int value)
{
	if (root == nullptr)
		return 0;
	if (root->data == value)
		return 1;
	if (root->data > value)
		findDataHelper(root->left, value);
	else
		findDataHelper(root->right, value);

}

//=-------------------------Find min element--------------------------------------
void BinarySearchTree::findMin()
{
	if (root == nullptr)
		return;

	while (root)
	{
		if (root->left == nullptr)
		{
			std::cout << "The min data is:" << root->data;
			break;
		}
			
		else
		{
			root = root->left;
		}
	}
}

//------------------------Public function to delete data-------------------------
void BinarySearchTree::deleteData(int data)
{
	this->deleteHelper(root, data);
}

//------------------------------Find Min function-----------------------------
Node* BinarySearchTree::findMinNode(Node* root)
{
	while (root->left != nullptr) root = root->left;
	return root;
}

//---------------------------Private function to delete a node from BST---------------------
Node* BinarySearchTree::deleteHelper(Node* root, int data)
{
	if (root == nullptr) return root;
	else if (data < root->data) root->left = deleteHelper(root->left, data);
	else if (data > root->data) root->right = deleteHelper(root->right, data);
	else {
		// Case 1: No Child
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
			// Case 2: one child
		}
		else if (root->left == nullptr) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node *temp = findMinNode(root->right);
			root->data = temp->data;
			root->right = deleteHelper(root->right, temp->data);
		}
	}
	return root;
}