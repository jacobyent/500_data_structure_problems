//PROBLEM: Given a binary tree, write iterrative and recursive solution to traverse the tree using pre-order traversal in C++ and java.
//
//EARLY NOTES: I think we just need to modify the current pointer from the last problem and that will output the correct solution.
//
//FINAL NOTES: Worked as I thought it would. We only to change the output to when we have a node pointer than when we don't. 
#include <iostream>
#include <queue>
#include <stack>
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
		cout << "tree is empty\n";
		return;
	}	
	cout << "Tree in level order: ";
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
void print_tree_preorder(Node *& root)
{
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}
	cout << "Tree in preorder: ";
	//function to output the tree inorder
	stack<Node*> s;
	
	//set a node pointer to the root
	Node * cur = root;
	
	//while the stack is not empty or the current pointer has a value
	while(!s.empty() || cur)
	{
		//if current has a value
		if(cur)
		{
			//push the node onto the stack
			s.push(cur);

			//output current element 
			cout << cur->key << " ";

			//move current to the left node
			cur = cur->left;
		}
		else
		{
			//grab and pop the top element
			cur = s.top();
			s.pop();
			
			//change the current element to the right leaf
			cur = cur->right;
		}
	}
	cout << endl;
	
}
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);
	print_tree_preorder(root);
	print_tree_level(root);
	
	return 0;
}
