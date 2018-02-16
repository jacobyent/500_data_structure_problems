//PROBLEM: Given a Binary Tree, determine if it is a BST or not.
//
//EARLY NOTES: I believe we can traverse the tree checking if the left and right child of each node is less than or greater than it respectively.
//
//PLANNING: Traverse in any order checking the children of each node. If any left child is greater than the parent or any right child is less than parent return false.
//
//MID NOTES: So I missed the point that it is possible for a tree to meet the parent child condition and still not be a bst. All I need to add to my solution is a check for parent

#include <iostream>
#include <queue>
#include <climits>
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
void delete_branch(Node *& root)
{
	//function to recursively delete a whole branch
	
	//base case
	if(!root)
	{
		return;
	}

	//delete children before deleting root
	delete_branch(root->left);
	delete_branch(root->right);
	delete root;
}

bool check_bst(Node * root, Node *& prev)
{
	//function to check if tree is binary search tree or not
	
	//base case: empty tree is a BST	
	if(!root)
	{
		return true;
	}

	bool left = check_bst(root->left,prev);

	if(root->key <= prev->key)
	{
		return false;
	}
	prev = root;
	return left && check_bst(root->right,prev);
}
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);

	//comment out these two lines to get the regular check
	delete_branch(root->left);
	root->left = new Node(100);
	
	Node * prev = new Node(INT_MIN);

	if(check_bst(root,prev))
	{
		cout << "Tree is a binary sort tree!\n";
	}
	else
	{
		cout << "Tree is not a binary sort tree!\n";
	}

	level(root);
	return 0;
}
