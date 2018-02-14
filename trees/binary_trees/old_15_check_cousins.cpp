//PROBLEM: Given a binary tree, determine if two given nodes are cousins of each other or not. Two nodes of a binary tree are cousins of each other only if they have different parents but are at the same level
//
//EARLY NOTES: Definetly a level order approach.
//
//PLANNING: Check each node's left child for both of the canidates. If we find one search the right node for the other one. If they are the same then return that they are not cousins. If they are different check the rest of the level's children for the other cousin. If it is there then they are cousins. If we don't find it they aren't.
//
//FINAL NOTES:

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

//our basic node structure
struct Node {
	int key;

	Node *left, *right;

	//constructor	
	Node(int value = 0)
	{
		key = value;
		left = NULL;
		right = NULL; 
	}

	//destructor
	~Node()
	{
		key = 0;
		delete left;
		delete right;
		left = NULL;
		right = NULL;
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
		cur->left = new Node(i++);

		cur->right = new Node(i++);

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
bool check(Node * cur, int one, int two)
{
	//helper function to check if a node exists and value's mataches a cousin
	if(!cur)
	{
		return false;
	}
	if(cur->key == one || cur->key == two)
	{
		return true;
	}
	return false;
}
bool cousin_check(Node *& root,int one, int two)
{
	//function to test for cousiness
	if(!root)
	{
		cout << "Tree is empty\n";
		return false;
	}	
	//will use a queue
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	//declare node pointer and child temp pointers
	Node * cur;

	//our integers for counting the level
	int i, size;

	//bool value testing for couisness and exit bool
	bool left;
	bool right;

	while(!q.empty())
	{
		i = 0;
		size = q.size();
		while(i < size)
		{
			//Grab front element
			cur = q.front();

			//pop front element
			q.pop();

			//increment counter
			i++;

			//this is slightly cleaner than writing it out long form
			left = check(cur->left,one,two);
			right = check(cur->right,one,two);

			//if both left and right contain a canidate then they are not cousins
			if(left && right)
			{
				return false;
			}
			//if either contain a canidate then we test the rest of the level
			else if(left || right)
			{
				while(i < size)
				{
					cur = q.front();
					q.pop();
					left = check(cur->left,one,two);
					right = check(cur->right,one,two);
					if(left || right)
					{
						cousins = true;
					}
				}
			}

			else
			{
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
		}
	}
	return cousins;
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	cousin_check(root, 4, 6);
	return 0;
}
