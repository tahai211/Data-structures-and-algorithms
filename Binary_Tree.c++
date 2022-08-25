#include <iostream>
using namespace std;

struct tNode{
	int data;
	tNode *pLeft, *pRight;
};

tNode *root;

//create new node
tNode *newNode(int data){
	tNode *node = new tNode;
	node->data = data;
	node->pLeft = NULL;
	node->pRight = NULL;
	return node;
}

//insert new Node into tree
void insertNode(tNode *p, int value){
	tNode *node = newNode(value);
	if (p->pLeft == NULL){
		p->pLeft = node;
	}else if (p->pRight == NULL) {
		p->pRight = node;
	}else{
		node->pLeft = p->pLeft;
		p->pLeft = node;
	}
}

//insert new Node into root
void insertNewRoot(int value){
	tNode *node = newNode(value);
	node->pLeft = root;
	root = node;
}

void NLR(tNode *root){
	if(root!=NULL){
			if(root!=NULL){
				cout<<root->data<<" ";
			}
			NLR(root->pLeft);
			NLR(root->pRight);
	}
}

void LNR(tNode *root){
	if(root!=NULL){
		LNR(root->pLeft);
		if(root!=NULL){
			cout<<root->data<<" ";
		}
		LNR(root->pRight);
	}
}

void LRN(tNode *root){
	if(root!=NULL){
		LRN(root->pLeft);
		LRN(root->pRight);
		if(root!=NULL){
			cout<<root->data<<" ";
		}
	}
}

int main()
{
	//create Nodes
	root = newNode(1);
	tNode *node2 = newNode(2);
	tNode *node3 = newNode(3);
	tNode *node4 = newNode(4);
	tNode *node5 = newNode(5);
	tNode *node6 = newNode(6);
	tNode *node7 = newNode(7);
	//assign childnodes
	root->pLeft = node2;
	root->pRight = node3;
	node2->pLeft = node4;
	node2->pRight = node5;
	node5->pLeft = node6;
	node5->pRight = node7;
	//traverse binary tree with NLR
	cout<<"traverse tree with NLR:";
	NLR(root);
	//traverse tree LNR
	cout<<"\ntraverse tree with LNR:";
	LNR(root);
	//traverse tree LRN
	cout<<"\ntraverse tree with LRN:";
	LRN(root);
	//insert new Node into tree
	insertNode(node2, 9);
	//traverse binary tree with NLR after insert new Node
	cout<<"\ntraverse tree with NLR:";
	NLR(root);
	system("pause");
}