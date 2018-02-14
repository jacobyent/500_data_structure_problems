//PROBLEM: Given a binary tree, print its nodes level by level. i.e. all nodes present at level 1 should be printed first followed by nodes of level 2 and son on.. All nodes for any level should be printed from left to right
//
//EARLY NOTES: I built this solution as part of my template I make for each problem set. I needed to print my trees so I knew they were working properly and bfs seemed like the best way to start
//
//PLANNING: BFS the tree. Add the root node to a queue. Then inside a loop pop and output the front node. Then add its left and right children if they exist to the queue

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
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);
	print_tree_level(root);
	return 0;
}
