#pragma once
#include <iostream>
typedef int datatype;


struct Node {
	datatype key; 
	Node* parent;
	Node* left;
	Node* right;
};
	
	void ShowTree(Node* pNode , int l );
	Node *CreateRootBST(Node*& pNode, datatype value);
	Node *SearchNodeBST(Node* pNode, datatype value);
	Node* SuccessorNodeBST(Node* pNode);
	void InsertNodeBST(Node* pNode,datatype value);
	Node* DelNodeBST(Node*& delNode, datatype value);
	Node* PredessorNodeBST(Node* pNode);