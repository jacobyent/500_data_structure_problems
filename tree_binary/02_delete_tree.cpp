//PROBLEM: Given a binary tree, write an efficient algorithm to delete the entire tree.
//
//EARLY NOTES: I'm just going to modify my height traversal to solve this problem iteratively
//
//PLANNING: BFS the tree from the root using a queue. Delete the node after adding possible leafs to queue.
//
//FINAL NOTES: I'm going to skip most of the recursive solutions because I've done a lot of recursion before. My solution matches techie's iterative solution. The only difference is I included a counter
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
	//destructor
	~Node()
	{
		key = 0;
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
	//if the tree is empty return without printing
	if(!root)
	{
		cout << "tree empty\n";
		return;
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
int delete_tree(Node *& root)
{
	//build our queue
	queue<Node*> q;

	//enqueue first element
	q.push(root);
	
	//keep track of deleted nodes
	int deleted = 0;

	while(!q.empty())
	{
		//grab and pop front element
		Node * cur = q.front();
		q.pop();

		//enqueue the leafs if they exist
		if(cur->left)
		{
			q.push(cur->left);
		}
		if(cur->right)
		{
			q.push(cur->right);
		}
		//delete current node
		delete cur;
		deleted++;
	}

	//remove the inital pointer
	root = NULL;

	//return the height value of the last node
	return deleted;
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	cout << "Deleted nodes: " << delete_tree(root) << endl;
	print_tree_level(root);
	return 0;
}
