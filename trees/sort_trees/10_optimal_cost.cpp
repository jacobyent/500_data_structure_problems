//PROBLEM: Find optimal cost to construct binary search tree where each key can repeat several times. We are given frequency of each key in same order as corresponding keys in inorder traversal of a BST.
//
//EARLY NOTES:
//
//PLANNING:
//
//FINAL NOTES: 

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

//node structure
struct Node {
	int key;

	Node *left, *right;
	Node *parent;

	//constructor	
	Node(int value = 0,Node * par = NULL)
	{
		key = value;
		left = NULL;
		right = NULL; 
		parent = par;
	}

	//destructor
	~Node()
	{
		key = 0;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

void inorder(Node * root)
{
	//function to print tree in order
	if(!root)
	{
		return;
	}

	cout << "Tree in order: ";
	
	//create stack and traversal pointer
	stack<Node *> stk;
	Node * cur = root;

	while(!stk.empty() || cur)
	{
		if(cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = stk.top();
			stk.pop();

			cout << cur->key << " ";

			cur = cur->right;
		}
	}
}
void build(int arr[], int low, int high, Node *& root)
{
	//recursive portion to build the bts
	
	//base case
	if(low > high)
	{
		return;
	}

	//find middle element
	int mid = (low + high)/2;

	//create new node
	root = new Node(arr[mid]);
	
	//continue building
	build(arr,low,mid-1,root->left);
	build(arr,mid+1,high,root->right);
	
	//if left or right are created add to their parent field
	if(root->left)
	{
		root->left->parent = root;
	}
	if(root->right)
	{
		root->right->parent = root;
	}
}
Node * build(int arr[],int n)
{
	//function to sort the array for recursion
	sort(arr,arr+n);
	
	Node * root;
	build(arr,0,n-1,root);

	return root;
}
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);
	inorder(root);
	return 0;
}
