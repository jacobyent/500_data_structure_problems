//PROBLEM: Given two arrays which represent sets of BST keys, check if they represent the same BST or not. We are not allowed to build the trees.
//
//PLANNING: Use recursion to check both arrays. Each recursion divide the arrays into subarrays with elements less than the zeroth element and elements greater than the zeorth element. Then recurse again checking the less than arrays against each other and the greater than ones against one another. Return false if the first elements don't equal one another, if the subarrays are not equal in length. Return true if the length is 0 or 1. Finally, return the AND value of the less and greater recursion resutls.
//
//FINAL NOTES: Very cool solution by techie. My inital approach was a bit naive but this helped me remember not all keys make the same tree!

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
bool check_arrays(int X[],int Y[],int n)
{
	//check if the arrays are empty or have only one element
	if(!n)
	{
		return true;
	}
	if(X[0] != Y[0])
	{
		return false;
	}
	if(n == 1)
	{
		return true;
	}
	
	//create our new arrays
	int x_l[n-1],y_l[n-1],x_g[n-1],y_g[n-1];
	
	//counters for the size of our arrays after being sorted
	int q = 0,w = 0,r = 0,t = 0;
	
	//stable sort the keys into subarrays
	for(int i = 1; i < n; i++)
	{
		//x_l is for keys less than the root, x_g greater
		if(X[i] < X[0])
		{
			x_l[q++] = X[i];	
		}
		else
		{
			x_g[w++] = X[i];
		}
		//y_l is for keys less than the root, y_g greater
		if(Y[i] < Y[0])
		{
			y_l[r++] = Y[i];
		}
		else
		{
			y_g[t++] = Y[i];
		}
	}

	//check the size of the arrays, if they differ return false
	if(q != r || w != t)
	{
		return false;
	}

	//finally continue with recursion if all the tests have been passed
	return check_arrays(x_l,y_l,q) && check_arrays(x_g,y_g,t);
}
int main()
{
	int X[] = {15,25,20,22,30,18,10,8,9,12,6};
	int Y[] = {15,10,12,8,25,30,6,20,18,9,22};
	int n = sizeof(X)/sizeof(X[0]);
	int m = sizeof(Y)/sizeof(Y[0]);
	if(n==m && check_arrays(X,Y,n))
	{
		cout << "X and Y are the same BST\n";
	}
	else
	{
		cout << "X and Y are NOT the same BST\n";
	}
	return 0;
}
