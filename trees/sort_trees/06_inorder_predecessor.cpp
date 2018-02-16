//PROBLEM: Given a BST, find in-order predeessor of a given key in it. If the given key does not lie in the BST, then return the previous greater key in the BST.
//
//EARLY NOTES: I believe we can search for the key like normal. Then when we find the key we check for it's predesessor using in order logic.
//
//PLANNING: Set a predesessor pointer to NULL. Search for the given key using BST logic. Every time we move to the right update the pointer to the current node. When we find the key update the pointer the maximum value in the left subtree, if it has a left child. If we can't find the key then the pointer will point to the location before where the key would be. Then return the pointer. 
//
//FINAL NOTES: Tricky problem that I would have had only the most naive solution for. 

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
Node * predecessor(Node * root, int key)
{
	//predecessor pointer
	Node * prec = NULL;

	//find the given key using BS, and keep track of the predecessor 
	while(root)
	{
		//if the given key is the smallest in the tree then it has no predecessor
		if(root->key > key)
		{
			root = root->left;
		}
		//every time we move to the right we update prec to the current node
		else if(root->key < key)
		{
			prec = root;
			root = root->right;
		}
		//if/when we find the proper node its predecessor will be the rightmost element in its left tree
		else
		{
			if(root->left)
			{
				root = root->left;
				while(root->right)
				{
					root = root->right;
				}
				prec = root;
			}
			//set root to NULL to exit
			root = NULL;
		}	
	}
	//return predecessor pointer 
	return prec;
}
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);
	Node * prec = NULL;
	for(int key:arr)
	{
		prec = predecessor(root,key);
		if(!prec)
		{
			cout << "NULL is the predecessor of " << key << endl;
		}
		else
		{
			cout << prec->key << " is the predecessor of " << key << endl;
		}
	}
	level(root);
	return 0;
}
