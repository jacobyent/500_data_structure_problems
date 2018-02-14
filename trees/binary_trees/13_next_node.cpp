//PROBLEM: Given a binary tree and a node in it, write an efficient algorithm to find its next node in the same level as the given node.
//
//EARLY NOTES: Level order traversal should do the trick. We traverse until we find the node we are looking for and then print the next node in level order.
//
//PLANNING: Traverse in level order as normal. When we find the node we are looking for output the next node in level order. If there isn't a node output null.
//
//FINAL NOTES: I used the same approach as techie's first solution. Their second solution looks good as well. It could be interesting to try to do the same but in an iterative way.

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
void print_next_node(Node *& root, int search)
{
	//function to output the next node after the given node
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}	
	//will use a queue
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	//start a counter and size variable
	int i, size;

	//exit condition
	bool found = false;

	while(!q.empty() && !found)
	{
		//reset the counter and grab the current level size
		i = 0;
		size = q.size();

		while(i < size && !found)
		{
			//Grab front element
			Node * cur = q.front();

			//pop front element
			q.pop();

			//check if we've found our node
			if(cur->key == search)
			{
				cout << "Next node of " << search << " is ";
				if(size == i + 1)
				{
					cout << "null\n";
				}
				else
				{
					cur = q.front();
					cout << cur->key << endl;
				}
				found = true;

			}
			//add children if any to queue
			if(cur->left)
			{
				q.push(cur->left);
			}
			if(cur->right)
			{
				q.push(cur->right);
			}
			i++;
		}
	}
	if(!found)
	{
		cout << "Node not in tree\n";
	}
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	print_next_node(root, 13);
	return 0;
}
