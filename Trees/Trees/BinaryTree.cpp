/*
	BinaryTree.cpp -> Implementation file.
	Author: Tanmay Fadnavis
*/

#include"BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>

//-------------------Default Constructor---------------------------------
BinaryTree::BinaryTree()
{
	root = nullptr;
}


//------------------Private function for adding data--------------------------
void BinaryTree::addDataHelper(Node* node,int value)
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
void BinaryTree::addData(int value)
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
void BinaryTree::inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->left);
		std::cout << root->data << "\t";
		inOrder(root->right);
	}
}

//-----------------------Public In order Traversal--------------------------------------
void BinaryTree::inOrderTrav()
{
	this->inOrder(root);
}

//-----------------------------Private Pre Order traversal---------------------------------
void BinaryTree::preOrder(Node* root)
{
	if (root)
	{
		std::cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}

//----------------------------Public Function for pre order traversal------------------------
void BinaryTree::preOrderTrav()
{
	this->preOrder(root);

}

//-----------------------------Private Post Order Traversal---------------------------------
void BinaryTree::postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->data << "\t";
	}
}

//---------------------------Public Post order-------------------------------------------
void BinaryTree::postOrderTrav()
{
	this->postOrder(root);
}

//--------------------------Public Level Order Traversal---------------------------------
void BinaryTree::levelOrderTrav()
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

//----------------Public Find Max-----------------------------------
void BinaryTree::findMax()
{
	int x = findMaxHelper(root);

	std::cout << "The max element is:" << x << "\n";

}

//---------------------------Function to find Max element-------------------------------
int BinaryTree::findMaxHelper(Node* root)
{
	int root_data, left, right, max = 0;

	if (root != nullptr)
	{
		root_data = root->data;
		left = findMaxHelper(root->left);
		right = findMaxHelper(root->right);

		if (left > right)
			max = left;
		else
			max = right;

		if (max < root_data)
			max = root_data;
	}
	return max;
}

//-----------------Public search function-----------------------------------
void BinaryTree::search(int data)
{
	if (this->searchHelperRec(root, data))
	{
		std::cout << "Element Found\n";

	}
	else
	{
		std::cout << "Element Not Found\n";
	}
}

//------------------------------------Private search helper function-----------------------
int BinaryTree::searchHelperRec(Node* root, int data)
{
	int temp = 0;
	if (root == nullptr)
		return 0;

	else
	{
		if (root->data == data)
			return 1;
		else
		{
			temp=searchHelperRec(root->left, data);
			if (temp)
				return 1;
			else
			{
				temp = searchHelperRec(root->right, data);
				if (temp)
					return 1;
			}
		}
	}

	return 0;
}

//-----------------------------------Public find size-----------------------------------
void BinaryTree::findSize()
{
	int x = this->findSizeHelper(root);
	std::cout << " The size of binary tree is" << x << "\n";
}

//----------------------------------Private Find Size Helper----------------------------------
int BinaryTree::findSizeHelper(Node* root)
{
	if (root == nullptr)
		return 0;
	else
		return findSizeHelper(root->left) + 1 + findSizeHelper(root->right);
}

//--------------------------Function to print level order in reverse------------------------------
void BinaryTree::levelOrderReverse()
{
	Node* temp = nullptr;
	if (root == nullptr)
		return;

	std::queue<Node* > q;
	std::stack<Node* > s;

	q.push(root);

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		s.push(temp);

		if (temp->right)
			q.push(temp->right);
		if (temp->left)
			q.push(temp->left);
	}

	while (!s.empty())
	{
		std::cout << s.top()->data << "\t";
		s.pop();
	}

}

//---------------------Public find height function-----------------------------
void BinaryTree::findHeight()
{
	int x = this->findHeightHelper(root);
	std::cout << " The height of the tree is:" << x << "\n";
}

//-----------------------Private find height helper-----------------------
int BinaryTree::findHeightHelper(Node* root)
{
	int leftHeight, rightHeight;

	if (root == nullptr)
		return 0;

	else
	{
		leftHeight = findHeightHelper(root->left);
		rightHeight = findHeightHelper(root->right);

		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}

	return 0;
}

//-------------------------Function to find the level which has max sum-------------------
void BinaryTree::maxLevelSum()
{

	int currentSum = 0;
	int maxSum = 0;
	int maxLevel = 0;
	int level = 0;
	Node* temp = nullptr;

	if (root == nullptr)
		return;

	std::queue<Node *> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp == nullptr)
		{
			if (currentSum > maxSum)
			{
				maxSum = currentSum;
				maxLevel = level;
			}
				currentSum = 0;
				if (!q.empty())
				{
					q.push(nullptr);
				}
					level++;
		}
		else
		{
			currentSum += temp->data;

			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}

	std::cout << "Max sum is at level:" << maxLevel << "\n";
}