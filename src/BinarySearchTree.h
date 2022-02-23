#pragma once

#include <vector>

//TODO Make a Red and Black Binary Search Tree. 

//Nodes
struct BstNode 
{
	BstNode() { data.reserve(2); };
	std::vector<int> data;
	BstNode* left;
	BstNode* right;

	int* index;
};

//BST
class BinarySearchTree
{
public:
	BinarySearchTree() { rootPtr = NULL; counter = 0; };
	BstNode* insert(BstNode* root, int& value);
	
private:
	BstNode* rootPtr;
	BstNode* getNewNode(int& data);
	int counter;
};

