//PROBLEM: Given a binary tree, check if it is a sum tree or not. In a sum tree, value at each non-leaf node is equal to the sum of all elements present in its left and right subtree. The value of a leaf node can be anything.
//
//EARLY NOTES: The recursive method here would recurse down the tree returning the none leaf node's value. Then we'd check if the final value is equal to the root value. The iterative method would be to create a sum and pass through the whole tree adding non-leaf nodes to the sum. Then at the end we check if the sum is equal to the root node. 
//
//PLANNING: Search through the tree using whatever order (exclude the root for this one). Create a sum value and initalize it to zero. Then, each non-leaf node add it's value to the running sum. At the end of the loop check if the root's value is equal to this sum. If it is not then the tree is not a sum tree.
//
//MID NOTES: So this solution doesn't work with their solution for making a sum tree in all cases. This solution only works if the sum tree is "perfect" i.e. every node is
#include <iostream>
#include <queue>
#include <cmath>

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

void build_tree(Node *& root, int height)
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
int convert_sum(Node *& root)
{
	//base case
	if(!root)
	{
		return 0;
	}
	int old = root->key;

	//continue recursion and add left and right values to this node
	root->key = convert_sum(root->left) + convert_sum(root->right);

	//return new key value
	return root->key + old;
}
int check_sum(Node *& root)
{
	//base case
	if(!root)
	{
		return 0;
	}
	
	//check for leafs
	if(!root->left && !root->right)
	{
		return 0;
	}
	return root->key + check_sum(root->left) + check_sum(root->right);
}
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);
	convert_sum(root);
	print_tree_level(root);
	if(check_sum(root->left) + check_sum(root->right) == root->key)
	{
		cout << "Tree is a sum tree\n";
	}
	else
	{
		cout << "Tree is not a sum tree\n";
	}
	return 0;
}
