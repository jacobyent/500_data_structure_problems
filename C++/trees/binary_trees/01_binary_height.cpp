//PROBLEM: Write an efficient algorithm to compute the height of binary tree. The height or depth of a tree is number of edges or nodes on longest path from root node to leaf node.
//
//EARLY NOTES: The problom that brought me to the binary problems. Now that I have a better understanding of binary trees this problem seems more simple. I will use a breadth first search and the distance of the last node will be the farthest node
//
//PLANNING: bfs with queue. Distance of last node is the height of the tree
//
//FINAL NOTES: I used a map to keep track of the height values while techie flushed their queue at every level. Techie's uses less space but I'm fond of my solution

#include <iostream>
#include <queue>
#include <cmath>
#include <map>

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
		cout << "tree empty\n";
	}
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
int tree_height(Node *& root)
{
	//create a map to keep track of the heigh of a node
	map<Node*,int> height;

	//input first value
	height[root] = 1;

	//build our queue
	queue<Node*> q;

	//enqueue first element
	q.push(root);

	Node * cur;

	while(!q.empty())
	{
		//grab and pop front element
		cur = q.front();
		q.pop();

		//enqueue the leafs if they exist
		if(cur->left)
		{
			height[cur->left] = height[cur] + 1;
			q.push(cur->left);
		}
		if(cur->right)
		{
			height[cur->right] = height[cur] + 1;
			q.push(cur->right);
		}
	}
	//return the height value of the last node
	return height[cur];
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	cout << "Tree height: " << tree_height(root) << endl;
	print_tree_level(root);
	return 0;
}
