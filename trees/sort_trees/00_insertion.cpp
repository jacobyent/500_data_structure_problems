//PROBLEM: Insert given value inside BST
//
//PLANNING: Build a node pointer and a while loop. The pointer should start off pointing to root. Have the loop exit when we've found and created our new node. Every loop check cur's value against the insert value. If it is less than check the left child's value. If left child exists move cur to the left child. If it doesn't exist create our new node there. Do the same for the right child if the value is equal to or greater than cur.
//
//FINAL NOTES:

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>

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
		delete left;
		delete right;
		left = NULL;
		right = NULL;
		if(parent)
		{
			if(parent->left == this)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		parent = NULL;
	}
};

void build(Node *& root, int height = 3)
{
	//function to build a perfectly balanced tree of given height

	//initilize our tree	
	root->key = 1;	

	//I'll use a queue for now to build for now but I'll keep an eye 
	//out for better solutions
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	//number of nodes
	int num = pow(2,height);

	int i = 2;
	while(i < num)
	{
		//grab the lead node
		Node * cur = q.front();

		//pop lead node
		q.pop();

		//create left and right children
		cur->left = new Node(i++,cur);

		cur->right = new Node(i++,cur);

		q.push(cur->left);
		q.push(cur->right);
	}
}
void build(Node *& root, vector<pair<string,int>> v)
{
	//function to build tree using a provided vector
	
	//if the root is NULL immediately return
	if(!root)
	{
		return;
	}	
	//temporary containers for our inputs
	string str;
	int temp;

	//traversal pointer directed by our string input
	Node * cur = root;

	//iterate through the vector creating nodes with the given input
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		//grab current string and int
		str = it->first;
		temp = it->second;

		//iterate over string moving to the proper node
		for(int i = 0; i < str.length() - 1; i++)
		{
			if(str[i] == 'L')
			{
				cur = cur->left;
			}	
			else
			{
				cur = cur->right;
			}
		}

		//create new node at the left or right child
		if(str[str.length() - 1] == 'L')
		{
			cur->left = new Node(temp,cur);
		}
		else
		{
			cur->right = new Node(temp,cur);
		}

		//make sure to reset cur after each traversal
		cur = root;
	}
}
void print_tree_level(Node *& root)
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
void insert(Node *& root,int value)
{
	//function to insert a node in a BST
	
	//traversal pointer
	Node * cur = root;
	
	//loop to find the proper location
	while(cur)
	{
		if(cur->key < value)
		{
			//if left child exists move cur and continue
			if(cur->left)
			{
				cur = cur->left;
			}
			//if left doesn't exist this is the location
			else
			{
				cur->left = new Node(value,cur);
				cur = NULL;
			}
		}
		else
		{
			//if right child exists move cur and continue
			if(cur->right)
			{
				cur = cur->right;
			}
			//if right doesn't exist this is the location
			else
			{
				cur->right = new Node(value,cur);
				cur = NULL;
			}
		}
	}	
}
int main()
{
	Node * root = new Node;
	root->key = 15;
	vector<pair<string,int>> v = {
		{"L",10}, {"LL",8},{"LR",12},{"R",20},
		{"RL",16},{"RR",25}
	};
	build(root,v);
	insert(root,18);
	print_tree_level(root);
	return 0;
}
