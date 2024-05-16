/*
	Find the lowest common ancestor of a given BST, given two elements in it.
	Solution: Traverse from the top of the tree and keep going down recursively according to the two elements' values.
	If both are smaller than the node being considered, go to the left. Else if both are larger, go to the right. 
	Else, that is where they branch, and that is the lowest common ancestor.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	public:
	friend ostream &operator<<(ostream &os,const struct Node val)
	{
		os<<val.data;
		return os;
		
	} 
	
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node node;

class bst
{
	node *root;
	int size;

	public:
	bst()
	{
		size=0;
	}
	
	node* returnroot()
	{
		return root;
	}
	
	node* insertnode(int elt, node *i) //returns inserted 
	{	

		node *toinsert = new node;
		toinsert->data = elt;
		toinsert->left=NULL;
		toinsert->right=NULL;
		if(size==0)
		{
			root = toinsert;
			size++;
			return root;
		}
		
		if(i->right==NULL && elt > i->data)
		{
			i->right = toinsert;
			size++;
			return toinsert;
		}
		else 
		if(i->left==NULL && elt < i->data)
		{
			i->left = toinsert;
			size++;
			return toinsert;
		}
		else if(elt > i->data)
		{
			return insertnode(elt, i->right);
		}
		else 
		{
			return insertnode(elt,i->left);
		}
	}
	
	void insertelts(vector <int> input)
	{
		for(int elt:input)
		{
			//cout<<elt<<" ";
			insertnode(elt,root);
			//cout<<endl;
		}
	}
	
	node* findLCArecursive(node* i, int x, int y)
	{
		if(i==NULL)
			return NULL;
		
		//if x and y both smaller
		if(i->data > ((x>y)? x:y) )
			return findLCArecursive(i->left,x,y);
		else if(i->data < ((x<y)? x:y) ) //if x and y both greater than root
			return findLCArecursive(i->right,x,y);
		//else, that is where they branch.
		return i;
	}
	
	void findLCA(int x, int y)
	{
		if(root==NULL) return;
		node* temp = findLCArecursive(root,x,y);
		if(temp!=NULL)
			cout<<"\nLCA is "<<temp->data;
		else cout<<"\nLCA does not exist";
	}
};


int main()
{
	bst b;
	vector <int> arr = {15,10,20,8,12,16,25};
	b.insertelts(arr);
	
	b.findLCA(8,12);
	b.findLCA(15,16);
	b.findLCA(8,25);
	b.findLCA(16,20);
	b.findLCA(16,25);
	return 0;
}
