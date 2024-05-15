/*
	Inorder, reverse inorder, preorder and postorder traversals of a BST tree.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Node
{
	friend ostream &operator<<(ostream &os,const struct Node val)
	{
		os<<val.data;
		return os;
		
	} 
	
	int data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
};

typedef struct Node node;


class bst
{
	node *root;
	int size;
	
	vector <int> arr;
	
	
	public:
	bst()
	{
		size=0;
	}
	
	node* insertnode(int elt, node *i) //returns inserted 
	{	

		//cout<<"\nTrying to insert "<<elt;
		node *toinsert = new node;
		toinsert->data = elt;
		toinsert->parent = NULL;
		toinsert->left=NULL;
		toinsert->right=NULL;
		if(size==0)
		{
			root = toinsert;
			cout<<"\n"<<elt<<" inserted as root";
			size++;
			return root;
		}
		
		if(i->right==NULL && elt > i->data)
		{
			i->right = toinsert;
			toinsert->parent = i;
			size++;
			cout<<"\n"<<elt<<" inserted to the right of parent "<<i->data;
			return toinsert;
		}
		else 
		if(i->left==NULL && elt < i->data)
		{
			i->left = toinsert;
			toinsert->parent = i;
			size++;
			cout<<"\n"<<elt<<" inserted to the left of parent "<<i->data;
			return toinsert;
		}
		else if(elt > i->data)
		{
			cout<<"\ngoing through "<<i->data;
			return insertnode(elt, i->right);
		}
		else 
		{
			cout<<"\ngoing through "<<i->data;
			return insertnode(elt,i->left);
		}
	}
	
	void insertion_binary(int low, int high, vector <int> elts, node* i)
	{
		
		if(low>high)
			return;
		int mid = (low + high)/2;
		node* parent_of_next = insertnode(elts.at(mid),i);
		insertion_binary(low,mid-1,elts, parent_of_next);
		insertion_binary(mid+1,high,elts, parent_of_next);
		
	}
	
	void insertelts(vector <int> elts)
	{
		sort(elts.begin(),elts.end());
		//8 10 12 15 18 20 25
		//a binary search of sorts
		insertion_binary(0,elts.size()-1,elts, root);
	}
	
	
	//INORDER TRAVERSAL: left root right
	//used for non decreasing order
	void inorder_traversal(node *i)
	{
		if(i==NULL)
			return;
		inorder_traversal(i->left);
		cout<<i->data<<" ";
		inorder_traversal(i->right);
		
	}
	
	void reverse_inorder_traversal(node *i)
	{
		if(i==NULL)
			return;
		reverse_inorder_traversal(i->right);
		cout<<i->data<<" ";
		reverse_inorder_traversal(i->left);
		
	}
	
	//PREORDER TRAVERSAL: root left right
	//used to create copy of tree, and to get prefix expression of expression tree
	void preorder_traversal(node *i)
	{
		if(i==NULL)
			return;
		cout<<i->data<<" ";
		preorder_traversal(i->left);
		preorder_traversal(i->right);
		
	}
	
	//POSTORDER traversal: left right root
	//to delete tree, and to get postfix expression of expression tree
	void postorder_traversal(node *i)
	{
		if(i==NULL)
			return;
		postorder_traversal(i->left);
		postorder_traversal(i->right);
		cout<<i->data<<" ";
		
	}
	
	void printtraversals()
	{
		cout<<"\nInorder: ";
		inorder_traversal(root);
		cout<<"\nReverse inorder: ";
		reverse_inorder_traversal(root);
		cout<<"\nPreorder: ";
		preorder_traversal(root);
		cout<<"\nPostorder: ";
		postorder_traversal(root);
	}
	
};


int main()
{
	bst b;
	vector <int> arr = {15,10,20,8,12,18,25};
	b.insertelts(arr);
	cout<<endl;
	b.printtraversals();
	return 0;
}