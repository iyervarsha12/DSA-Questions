/*
	Given a Balanced Binary Search Tree and a target sum, write a function that returns true 
	if there is a pair with sum equals to target sum, otherwise return false.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

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
	//set or unordered set of elts called "elts";
	unordered_set <int> elts;
	
	public:
	bst()
	{
		size=0;
	}
	
	void inorder(node *i)
	{
		if(i==NULL)
			return;
		inorder(i->left);
		cout<<i->data<<" ";
		inorder(i->right);
		
	}
	
	void inorder_print()
	{
		cout<<endl;
		inorder(root);
		cout<<endl;
	}
	
	
	bool findpair(node *i, int sum)
	{
		if(i==NULL)
			return false;
		bool ans1 = findpair(i->left,sum);
		if(elts.find(sum-(i->data))!=elts.end() && (2*(i->data)!=sum))
		{
			cout<<"\n"<<i->data<<" and "<<(sum-(i->data))<<" added together form "<<sum;
			return true;
		}
	    elts.insert(i->data);
		bool ans2 = findpair(i->right,sum);
		if(ans1&&ans2)
			return true;
	}
	
	bool findpairsum(int sum)
	{
		return findpair(root,sum);
	}
	
	bool insertnode(int elt, node *i)
	{	
		node *toinsert = new node;
		toinsert->data = elt;
		toinsert->parent = NULL;
		toinsert->left=NULL;
		toinsert->right=NULL;
		
		if(size==0)
		{
			root = toinsert;
			size++;
			cout<<"\n"<<elt<<"inserted as root";
			return true;
		}
		
		if(i->right==NULL && elt > i->data)
		{
			i->right = toinsert;
			toinsert->parent = i;
			size++;
			cout<<"\n"<<elt<<"inserted in right of "<<i->data;
			return true;
		}
		else 
		if(i->left==NULL && elt < i->data)
		{
			i->left = toinsert;
			toinsert->parent = i;
			size++;
			cout<<"\n"<<elt<<"inserted in left of "<<i->data;
			return true;
		}
		else if(elt > i->data)
			return insertnode(elt, i->right);
		else return insertnode(elt,i->left);
	}
	
	void insertelts(vector <int> input)
	{
		for(int elt:input)
		{
			insertnode(elt,root);
		}
		
	}
};


int main()
{
	bst b;
	b.insertelts({ 15, 10, 20, 8, 12, 16, 25 });
	cout<<endl<<"Tree inputted is "<<endl;
	b.inorder_print();
	cout<<b.findpairsum(28)<<endl;
	cout<<b.findpairsum(30)<<endl;
	return 0;
}