//PROBLEM: Given a binary tree, in place convert it to its sum tree. In a sum tree, value at each node is equal to the sum of all elements present in its left and right subtree. The value of an empty node is conssidered as 0. 
//
//EARLY NOTES: Recursion seems like the most efficent way to do this problem. I imagine there is a way to do it in a iterative way but I doubt it would be very clean.
//
//PLANNING: Check if this node has children. If it does set its value to the sum of its children inside the recursion. Eitherway return this nodes value as the last step.
//
//FINAL NOTES: Took me awhile to understand how sum trees were supposed to work. Geeks for geeks.org had a better write up imo because they made it clear the botoom nodes were supposed to be zero.

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
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);
	convert_sum(root);
	print_tree_level(root);
	return 0;
}
