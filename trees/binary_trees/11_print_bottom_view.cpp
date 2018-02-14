//PLANNING: Given a binary tree, print bottom view of it. Assume the left and right child of a node make 45 degree angles with the parent.
//
//EARLY NOTES: I was trying to think of a iterative way to solve this problem. There probably is but looking at the recursive solution provided by techie I think I will just implement that.
//
//PLANNING: Start a map of ints and pairs. The ints being the horizontial distance and the pair being the node value and the height of the node. Start the recursion at the root. Every time we see a new key value (distance) at it to the map. Every time we see a repeat compare the the node's level, pick the geater one. At the end output the node values by their keys.

#include <iostream>
#include <queue>
#include <map>
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
void print_bottom(Node * node, int dist, int level, auto &map)
{
	//base case
	if(!node)
	{
		return;
	}
	//if we've not seen this distance before or the level is greater
	if(map.find(dist) == map.end() || level >= map[dist].second)
	{
		map[dist] = {node->key,level};
	}
	//increase the level by one for both
	//Decrease distance by one for the left tree and increase for right
	print_bottom(node->left, dist-1, level + 1, map);
	print_bottom(node->right, dist+1, level + 1, map);
}
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);
	map<int,pair<int,int>> map;
	print_bottom(root,0,0,map);
	for(auto it: map)
		cout << it.second.first << " ";
	return 0;
}
