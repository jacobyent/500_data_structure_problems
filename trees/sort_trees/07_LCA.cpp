//PROBLEM: Given a BST and two nodes x and y int it, find lowest common ancestor (LCA) of x and y in it.
//
//PLANNING:: I believe we can serach for one node building a queue of its visited nodes. Then we can search for the other value. Every traversal store the value of the previous queue value. When we differ or the queue is empty the previous value will be the lca.
//
//FINAL NOTES: Their iterative solution is very good. It traverses with both values at once. If both nodes are less than or greater than the root then it traverses appropriatly. Once they find a node they can't traverse to they return the current node because that is the LCA. Very cool.

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

Node * LCA(Node * root, int x, int y)
{
	queue<Node *> q;
	q.push(root);
	
	Node * cur = root;
	Node * prev = root;
	while(cur)
	{
		if(x < cur->key)
		{
			cur = cur->left;
			if(cur)
			{
				q.push(cur);
			}
		}
		else if(x > cur->key)
		{
			cur = cur->right;
			if(cur)
			{
				q.push(cur);
			}
		}
		else
		{
			q.push(cur);
			cur = NULL;
		}
	}
	cur = root;
	q.pop();
	while(cur)
	{
		if(y < cur->key)
		{
			cur = cur->left;
		}
		else if(y > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			prev = cur;
			break;
		}
		if(cur != q.front())
		{
			break;
		}
		else
		{
			prev = q.front();
			q.pop();
		}
	}
	return prev;
}
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);
	Node * lca = LCA(root, 8,25);
	if(lca)
	{
		cout << "LCA is: " << lca->key << endl;
	}
	return 0;
}
