/*
	Convert a tree into a BST.
	Solution: This is done by storing the tree elements onto a set first.
*/

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

//keep original structure of binary tree intact
struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node node;

node* newNode(int key)
{
	node* t = new node;
	t->data = key;
	t->left = t->right = nullptr;

	return t;
}

void fillset(node *i,set <int> &s)
{
	if(i==NULL)
		return;
	
	fillset(i->left,s);
	s.insert(i->data);
	fillset(i->right,s);
}

void convert(node *i, set <int>::iterator &it)
{
	if(i==NULL)
		return;
	
	convert(i->left,it);
	i->data = (*it);
	//cout<<"\nInserted "<<i->data;
	it++;
	convert(i->right,it);
}

void inorder(node *i)
{
	if(i==NULL)
		return;
	inorder(i->left);
	cout<<i->data<<" ";
	inorder(i->right);
}

int main()
{
	/* Construct below tree
			  8
			/   \
		   /	 \
		  3	   5
		 / \	 / \
		/   \   /   \
	   10	2 4	 6   */

	node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(10);
	root->left->right = newNode(2);
	root->right->left = newNode(4);
	root->right->right = newNode(6);
	
	cout<<"\nInorder traversal before conversion: ";
	inorder(root);
	cout<<endl;
	
	set <int> s;
	fillset(root,s);
	auto it = s.begin();
	convert(root,it);
	
	cout<<"\nInorder traversal after conversion: ";
	inorder(root);
	cout<<endl;
	
	return 0;
}