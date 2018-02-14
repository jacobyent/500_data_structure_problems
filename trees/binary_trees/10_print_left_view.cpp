//PROBLEM: Given a binary tree, write an efficient algorithm to print left view of binary tree
//
//EARLY NOTES: I think I'll have to modify my level order solution for this problem. 
//
//PLANNING: Build a level order solution using a q and a counter, but only output the first key. Then pop and enqueue the rest as normal
//

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

	while(!q.empty())
	{
		//Grab front element
		Node * cur = q.front();

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
void print_left_view(Node *& root)
{
	//function to print the left view of the tree
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}	
	cout << "Left view: ";
	//counter and size
	int size;

	//will use a queue
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	Node * cur;

	while(!q.empty())
	{
		//initalize our counter
		size = q.size();

		//pop and output the left node
		cur = q.front();
		q.pop();
		cout << cur->key << " ";

		if(cur->left)
		{
			q.push(cur->left);
		}
		if(cur->right)
		{
			q.push(cur->right);
		}
		for(int i = 1; i < size; i++)
		{	
			//Grab front element
			cur = q.front();

			//pop front element
			q.pop();

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

	cout << endl;
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	print_left_view(root);
	return 0;
}
