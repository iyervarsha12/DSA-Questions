/*
	Find the 'k'th smallest and largest element of a BST.
	Solution: find kth smallest element using inorder traversal, and kth largest using reverse inorder traversal.
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
			insertnode(elt,root);
		}
	}
	
	
	vector <int> inorder;
	void inorder_traversal(node* i, int &count, int k, int &ans) //left root right
	{
		if(i==NULL || count>=k)
			return;
		
		inorder_traversal(i->left,count,k,ans);
		if(count>=k)
			return;

		ans=i->data;
		count++;
		cout<<"\nPushed "<<i->data<<" at "<<count;
		if(count>=k)
			return;
		
		inorder_traversal(i->right,count,k,ans);	
	}
	
	void reverse_inorder_traversal(node *i,int &count, int k, int &ans) //right root left
	{
		if(i==NULL || count>=k)
			return;
		
		reverse_inorder_traversal(i->right,count,k,ans);
		if(count>=k)
			return;

		ans=i->data;
		count++;
		cout<<"\nPushed "<<i->data<<" at "<<count;
		if(count>=k)
			return;
		
		reverse_inorder_traversal(i->left,count,k,ans);
	}
	
	void kth(int k)
	{
		
		
		int count1=0;
		int ans1;
		inorder_traversal(root,count1,k,ans1);
		cout<<"\n"<<k<<"th smallest element is "<<ans1<<endl;
		
		
		int count2=0;
		int ans2;
		reverse_inorder_traversal(root,count2,k,ans2);
		cout<<"\n"<<k<<"th largest element is "<<ans2<<endl;

		
	}
		
};

int main()
{
	bst b;
	vector <int> arr = {20,8,22,4,12,10,14};
	b.insertelts(arr);
	b.kth(3);
	b.kth(1);
	return 0;
}