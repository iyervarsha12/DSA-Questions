/*
	Check whether two given BSTs are equal, given two vectors of their elements. 
	Solution: This is done by recursively going down the trees from the root onwards. 
	(if parent is ith index, left child is 2*i+1, right child is 2*i+2)
*/

#include <iostream>
#include <vector>

using namespace std;

bool checkequalbst(vector <int> arr1, vector <int> arr2)
{
	if(arr1.size()!=arr2.size()) //if unequal size, it's gone already,
		return false;
	if(arr1.size()==0)
		return true;
	
	if(arr1.at(0)!=arr2.at(0)) //if unequal root, it's gone already,
		return false;
	if(arr1.size()==1)
		return true;
	
	vector <int> arr1lower,arr2lower,arr1higher,arr2higher;
	for(int elt: arr1)
	{
		if(elt<arr1[0])
			arr1lower.push_back(elt); //all elts lower than given root
		else if(elt>arr1[0]) 
			arr1higher.push_back(elt); //all elts higher
	}
	for(int elt: arr2)
	{
		if(elt<arr2[0])
			arr2lower.push_back(elt);
		else if(elt>arr2[0]) 
			arr2higher.push_back(elt);
	}
	
	if(arr1lower.size()!=arr2lower.size() || arr1higher.size()!=arr2higher.size()) //if unequal size, it's not equal BST.
		return false;
	else
		return (checkequalbst(arr1lower,arr2lower) && checkequalbst(arr1higher,arr2higher));
	
}


int main()
{
	vector <int> arr1 = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
	vector <int> arr2 = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };
	cout<<checkequalbst(arr1,arr2)<<endl;
	
	arr1 = {9,1,2};
	arr2 = {9,7,2};
	cout<<checkequalbst(arr1,arr2)<<endl;
	
	arr1 = {9};
	arr2 = {9};
	cout<<checkequalbst(arr1,arr2)<<endl;
	
	arr1 = {1,2,3};
	arr2 = {3,2,1};
	cout<<checkequalbst(arr1,arr2)<<endl;
	
	return 0;
}