#include "Header.h"
using namespace std;

void ShowTree(Node *pNode , int l) {
	if (pNode != NULL) {
		ShowTree(pNode->right, l + 1);
		for (int i = 0; i < l; i++)
			cout << "\t";
		cout << pNode->key << endl;
		ShowTree(pNode->left, l + 1);
	}
};


Node* SearchNodeBST(Node* pNode, datatype key) {
	if (pNode != NULL) {
		if (pNode->key == key) {
			return pNode;
		}
		else if (pNode->key > key) {
			return SearchNodeBST(pNode->left, key);

		}
		else if (pNode->key < key) {
			return SearchNodeBST(pNode->right, key);
		}
	}
	else
		return NULL;
};

Node* CreateRootBST(Node*& pNode,datatype value) {
	pNode = new Node;
	pNode->key = value;
	pNode->parent = pNode->left = pNode->right = NULL;
	return pNode;
};

void InsertNodeBST(Node* pNode ,datatype value) {
	if (SearchNodeBST(pNode, value)) {
		 cout << "Âæå ³ñíóº" << endl;
	} 
	else {
		Node* pNew = new Node;
		pNew->key = value;
		pNew->parent = pNew->left = pNew->right = NULL;
		Node* previous;
		while (pNode != NULL) {
			previous = pNode;
			if (pNode->key > value) {
				pNode = pNode->left;
			}
			else if (pNode->key < value) {
				pNode = pNode->right;
			}
			if (pNode == NULL) {
				pNew->parent = previous;
				if (previous->key > value) {
					previous->left = pNew;
				}
				else if (previous->key < value) {
					previous->right = pNew;
				}

			}
		}
	}
};

Node* SuccessorNodeBST(Node* pNode) {
	Node* previous = pNode;
	if (pNode->right  != NULL){
		previous = pNode->right;
	while (previous->left != NULL)
		previous = previous->left;
	return previous;
	}
	else if (pNode->right == NULL) {
		previous = pNode->parent;
		while (previous != NULL && pNode == previous->right) {
			pNode = previous; 
			previous = previous->parent;
		}
	return previous;
	}
};

Node* PredessorNodeBST(Node* pNode) {
	Node* previous = pNode;
	if (pNode->left != NULL) {
		previous = pNode->left;
		while (previous->right != NULL)
			previous = previous->right;
		return previous;
	}
	else if (pNode->left == NULL) {
		previous = pNode->parent;
		while (previous != NULL && pNode == previous->left) {
			pNode = previous;
			previous = previous->parent;
		}
		return previous;
	}
};

Node* DelNodeBST(Node*& delNode,datatype value) {
	if (SearchNodeBST(delNode, value) == NULL) {
		cout << "Íå ³ñíóº" << endl;
	}
	else if (delNode == NULL) {
		return delNode;
	}
	else if (delNode->key > value) {
		DelNodeBST(delNode->left, value);
	}
	else if (delNode->key < value) {
		DelNodeBST(delNode->right, value);
	}
	else if (delNode->left == NULL && delNode->right == NULL) {
		delete delNode;
		delNode = NULL;
	}
	else if (delNode->left == NULL) {
		Node* temp = delNode;
		delNode = delNode->right;
		delete temp;
	}
	else if (delNode->right == NULL) {
		Node* temp = delNode;
		delNode = delNode->left;
		delete temp;
	}
	else {
	Node* temp = delNode->left;
	while (temp->right != NULL)
	temp = temp->right;
	delNode->key = temp->key;
	delNode->left = DelNodeBST(delNode->left, temp->key);
	}
	return delNode;
}; 