//PROBLEM: Given two arrays which represent sets of BST keys, check if they represent the same BST or not. We are not allowed to build the trees.
//
//EARLY NOTES: I believe we can sort the arrays and then compare each element. This takes less space and has roughly the same execution time
//
//PLANNING: First check if they are the same length. If they aren't return false. If they are sort them and compare each element in order. If any element differs they are not the same bsts.
//
//FINALE NOTES: My solution doesn't actually work. Trees can have the same keys but not be the same. I will archive this and implement techie's solution.

#include <iostream>
#include <queue>
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
bool check_arrays(int X[],int n, int Y[], int m)
{
	if(n != m)
	{
		return false;
	}
	sort(X,X+n);
	sort(Y,Y+n);

	for(int i = 0; i < n; i++)
	{
		if(X[i] != Y[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int X[] = {15,25,20,22,30,18,10,8,9,12,6};
	int Y[] = {15,10,12,8,25,30,6,20,18,9,22};
	int n = sizeof(X)/sizeof(X[0]);
	int m = sizeof(Y)/sizeof(Y[0]);
	if(check_arrays(X,n,Y,m))
	{
		cout << "X and Y are the same BST\n";
	}
	else
	{
		cout << "X and Y are NOT the same BST\n";
	}
	return 0;
}
