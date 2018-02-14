//PROBLEM: Given a binary tree, check if it is a complete binary tree or not.
//
//EARLY NOTES: I believe we only need to check for two conditions. The first is if we have a right child but not a left child for a node. That will automatically fail completness. The second is if we have a left but not a right and the left has any children. This will also violate completness. 
//
//PLANNING: Traverse the tree in any order. Check each node for left and right children. If they are missing a left but have a right fail the tree. If they have a left but not a right test the left node for children. If it has any, fail the tree.
//
//FINAL NOTES: Had to manually delete nodes from my perfect trees to test the code. Still worked but I think it might be time to create a destructor for my nodes in my template file. Anyways, I used the same approach as techie more or less. My code doesn't need to check all the other nodes so its marginally faster but their approach using the array nature is very cool. I might come back later and implement that. 

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
bool test_complete(Node *& root)
{
	//function to test a tree for completness
	if(!root)
	{
		cout << "Tree is empty\n";
		return false;
	}	
	//will use a queue
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	//declare node pointer
	Node * cur;

	//bool for our test
	bool test = true;

	while(!q.empty() && test)
	{
		//Grab front element
		cur = q.front();
		
		//pop front element
		q.pop();
		
		//if we have a right but not a left child we instantly fail
		if(cur->right && !cur->left)
		{
			test = false;
		}
		
		//if we are missing the right child and left has children fail the tree
		if(cur->left && !cur->right)
		{
			if(cur->left->left || cur->left->right)
			{
				test = false;
			}
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
	}
	return test;
}
int main()
{
	Node * root = new Node;
	int height = 2;
	build_tree(root,height);
	if(test_complete(root))
	{
		cout << "Tree is complete\n";
	}
	else
	{
		cout << "Tree is not complete\n";
	}
	return 0;
}
