//Bailie Allemand
//Lab04TreeTraversals
//Due 3.11.2019
//Help Statement:

#include "stdafx.h"

#include<iostream>


using namespace std;
struct Node {
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};
Node * searchNode(Node * root, int value) {
	Node * rightResult;
	Node * leftResult;
	if (root == NULL) {
		return NULL;
	}
	else if (root->value == value) {
		return root;
	}
	else {
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL) {
			return NULL;
		}
		else if (rightResult != NULL) {
			return rightResult;
		}
		else {
			return leftResult;
		}
	}
}
void insertLeft(Node * Parent, Node * nodeToInsert) 
{
	Parent->leftNode = nodeToInsert;
}
void insertRight(Node * Parent, Node * nodeToInsert) 
{
	Parent->rightNode = nodeToInsert;
}

int inOrderTraversal(Node * root)//(left, root, right)
{
	if (root != NULL) {
		inOrderTraversal(root->leftNode);
		cout << root->value << endl;
		inOrderTraversal(root->rightNode);
	}
	return 0;
}
int postOrderTraversal(Node * root) //(left, right, root)
{ 
	if (root != NULL)
	{
		postOrderTraversal(root->leftNode);
		postOrderTraversal(root->rightNode);
		cout << root->value << endl;
	}
	return 0; 
}

int preOrderTraversal(Node * root) //(root, left, right)
{ 
	if (root != NULL)
	{
		cout << root->value << endl;
		preOrderTraversal(root->leftNode);
		preOrderTraversal(root->rightNode);
	}
	return 0; 

}
int main() {
	Node * BinaryTree = new Node;
	BinaryTree->value = 5;
	
	//right side of tree
	Node * tmp = new Node;
	tmp->value = 1;
	BinaryTree->rightNode = tmp;

	tmp = new Node;
	tmp->value = 7;
	BinaryTree->rightNode->rightNode = tmp;

	tmp = new Node;
	tmp->value = 9;
	BinaryTree->rightNode->rightNode->rightNode = tmp;

	/*tmp = new Node;
	tmp->value = NULL;
	BinaryTree->rightNode->leftNode = tmp;*/

	//left side of tree
	tmp = new Node;
	tmp->value = 4;
	BinaryTree->leftNode = tmp;

	tmp = new Node;
	tmp->value = 10;
	BinaryTree->leftNode->leftNode = tmp;

	tmp = new Node;
	tmp->value = 15;
	BinaryTree->leftNode->rightNode = tmp;

	tmp = new Node;
	tmp->value = 8;
	BinaryTree->leftNode->rightNode->leftNode = tmp;

	/*tmp = new Node;
	tmp->value = NULL;
	BinaryTree->leftNode->rightNode->rightNode = tmp;*/

	cout << "inOrderTraversal" << endl;
	inOrderTraversal(BinaryTree);
	cout << "postOrderTraversal" << endl;
	postOrderTraversal(BinaryTree);//
	cout << "preOrderTraversal" << endl;
	preOrderTraversal(BinaryTree);
	Node * searchResult = searchNode(BinaryTree, 2);
	if (searchResult != NULL) {
		cout << searchResult << endl;
	}
	else {
		cout << "The node searched does not exist." << endl;
	}
}
