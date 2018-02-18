//PROBLEM: Given a BST and a positive number K, find k'th smallest and k'th largest element in BST.
//
//EARLY NOTES: I believe we can traverse in-order. When we've reached K elements that will be our smallest. Then we can traverse in reverse in-order and the kth element will be our largest.
//
//PLANNING: Traverse in order when we've reached K elements that will be our smallest. Then we can traverse in reverse in-order and the kth element will be our largest.
//
//FINAL NOTES: Forgot that inorder required a stack not a queue. Was pretty cool to learn how to traverse in reverse inorder. Which seemed really simple once I figured it out.

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

void level(Node *& root)
{
	//function to output the tree in a level or bfs method
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}	
	cout << "Tree in level traversal: ";
	//will use a queue
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	//declare node pointer
	Node * cur;

	while(!q.empty())
	{
		//Grab front element
		cur = q.front();

		//pop front element
		q.pop();

		//output current element
		cout << cur->key << " ";

		//add children if any to queue
		if(cur->left)
		{
			q.push(cur->left);
		}
		if(cur->right)
		{
			q.push(cur->right);
		}
	}
	cout << endl;
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
void kth_elements(Node * root, int k)
{
	//check the tree
	if(!root)
	{
		return;
	}

	//create our stack
	stack<Node*> stk;
	
	//declare our traversal pointer
	Node * cur = root;

	//declrae our count variable and initalize
	int count = 0;

	while(!stk.empty() || cur)
	{
		//if we have a node enqueue it and move to the left
		if(cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		//else we grab from the queue
		else
		{
			cur = stk.top();
			stk.pop();

			//if this is the kth smallest node we output it and leave the loop
			if(++count == k)
			{
				cout << "Kth smallest node: " << cur->key << endl;
				break;
			}

			//else we move the current node to the right subtree 
			cur = cur->right;
		}
	}
	
	//now for our largest
	
	//reset our stack, traversal pointer, and count
	cur = root;
	count = 0;
	
	//this will clear the stk efficetely
	stack<Node*> temp;
	swap(temp,stk);

	while(!stk.empty() || cur)
	{
		if(cur)
		{
			stk.push(cur);
			cur = cur->right;
		}
		else
		{
			cur = stk.top();
			stk.pop();

			if(++count == k)
			{
				cout << "Kth largest node: " << cur->key << endl;
				break;
			}

			cur = cur->left;
		}
	}
}
void inorder(Node * root)
{
	stack<Node*> stk;

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
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);
	kth_elements(root,2);
	inorder(root);
	return 0;
}
