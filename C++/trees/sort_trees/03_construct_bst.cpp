//PROBLEM: Given an unsorted array of integers which represents binary search tree keys, construct a height balanced BST from it.
//
//EARLY NOTES: This function will probably replace my build template for the bst problems. We can use the inbuilt sort function to sort the array. Then we can recursively build the tree by splitting the lists. I'm sure there is a way to build this iteratively but nothing comes to mind immediately
//
//PLANNING: Sort the array. Then pick the middle element to be the root. Split the list into left and right arrays. Enter each list into a recursive function that returns a node pointer as its output. Set the left and right child of the root to the value of these functions. 
//
//FINAL NOTES: I modified their solution a bit to accomodate my parent field. However, I realized I could still modify the parent field the same way with their solution.

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//our not so basic node structure
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

Node * build(int arr[], int low, int high)
{
	//recursive portion to build the bts
	
	//base case
	if(low > high)
	{
		return NULL;
	}

	//find middle element
	int mid = (low + high)/2;

	//create new node
	Node * root = new Node(arr[mid]);
	
	//continue building
	root->left = build(arr,low,mid-1);
	root->right = build(arr,mid+1,high);
	
	//if left or right are created add to their parent field
	if(root->left)
	{
		root->left->parent = root;
	}
	if(root->right)
	{
		root->right->parent = root;
	}

	//finally return the node pointer
	return root;
}
Node * build(int arr[],int n)
{
	//function to sort the array for recursion
	sort(arr,arr+n);

	Node * root = build(arr,0,n-1);

	return root;
}
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);
	level(root);
	return 0;
}
