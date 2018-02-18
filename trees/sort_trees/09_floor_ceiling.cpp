//PROBLEM: Find the floor and ceiling of a given key. If that key is in the tree then the floor and ceiling is that key.
//
//EARLY NOTES: I believe we can sort traverse the tree, keeping two values floor and ceiling. 
//
//PLANNING: Traverse the tree using keys. Every time we find a value less than our value we update floor to this value, do the same for ceiling with greater values. Once we've hit a null pointer we are at the end and can output floor and ceiling. If we get a direct match we update floor and ceiling to the key value and exit traversal.
//
//FINAL NOTES: Fairly simple problem. Techie used node pointers to keep track of their values. Probably better if we want the nodes for something besides int values but otherwise very similar

#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

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
void floor_ceiling(Node * root, int ser)
{
	//initalize floor and ceiling with their respective limit values
	int floor = INT_MIN;
	int ceil = INT_MAX;

	Node * cur = root;

	while(cur)
	{
		if(ser < cur->key)
		{
			ceil = cur->key;
			cur = cur->left;
		}
		else if(ser > cur->key)
		{
			floor = cur->key;
			cur = cur->right;
		}
		else
		{
			floor = ser;
			ceil = ser;
			cur = NULL;
		}
	}

	if(floor == INT_MIN)
	{
		cout << ser << " does not have a floor value\n";
	}
	else
	{
		cout << "Floor value of " << ser << " is " << floor << endl;
	}
	if(ceil == INT_MAX)
	{
		cout << ser << " does not have a ceiling value\n";
	}
	else
	{
		cout << "Ceiling value of " << ser << " is " << ceil << endl;
	}
}
int main()
{
	int arr[] = {15,10,20,8,12,18,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node * root = build(arr,n);
	floor_ceiling(root, 14);
	level(root);
	return 0;
}
