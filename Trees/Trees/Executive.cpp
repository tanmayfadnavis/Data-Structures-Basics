/*
	Executive.cpp -> This is the main driver class.
	Author: Tanmay Fadnavis
*/

#include"BinaryTree.h"
#include "BinarySearchTree.h"
#include <iostream>

int main(int argc, char** argv)
{

	/*BinaryTree bt;
	bt.addData(45);
	bt.addData(34);
	bt.addData(50);
	bt.addData(100);
	bt.addData(3);
	bt.addData(1);
	bt.addData(75);
	std::cout << "------------------In order Traversal----------------------\n";
	bt.inOrderTrav();
	std::cout << "\n-----------------Pre oder traversal-----------------------\n";
	bt.preOrderTrav();
	std::cout << "\n-------------------Post order traversal--------------------\n";
	bt.postOrderTrav();
	std::cout << "\n";
	std::cout << "----------------------Level Order Traversal----------------------\n";
	bt.levelOrderTrav();
	std::cout << "\n";
	bt.findMax();
	bt.search(100);
	bt.findSize();
	std::cout << "\n";
	bt.levelOrderReverse();
	bt.findHeight();
	bt.maxLevelSum();*/

	BinarySearchTree bst;
	bst.addData(45);
	bst.addData(34);
	bst.addData(3);
	bst.addData(40);
	bst.addData(100);
	bst.addData(50);
	bst.addData(75);
	bst.addData(110);

	std::cout << "The inorder traversal is----------------------\n";
	bst.inOrderTrav();
	std::cout << "\n Pre order traversal is -------------------------\n";
	bst.preOrderTrav();
	std::cout << "\n Post order Traversal is------------------------------\n";
	bst.postOrderTrav();
	bst.findData(11);
	//bst.findMin();
	//bst.deleteData(100);
	//bst.inOrderTrav();
	getchar();

}