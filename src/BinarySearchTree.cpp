#include "BinarySearchTree.h"
#include <iostream>



BstNode* BinarySearchTree::insert(BstNode* root, int& value)
{
    if (root == NULL)
        return getNewNode(value);

    if (value == root->data.front()) // If already present
        root->data.back() += 1;
    else if (value < root->data.front())
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

BstNode* BinarySearchTree::getNewNode(int& distinctValue)
{
	BstNode* newNode = new BstNode();
    counter++;
 
    newNode->data.emplace_back(distinctValue);
	newNode->data.emplace_back(1);
    newNode->index = &counter;
    newNode->left = newNode->right = nullptr;


	return newNode;
}
