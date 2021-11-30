//PROBLEM: Given a binary tree, write iterative and recursive solution to traverse the tree using in-order traversal in C++ and java.
//
//EARLY NOTES: I will be skipping the recursive and java. I've already written a function that traverses in a level way. I think this method will require a stack instead of a queue.
//
//MID NOTES: I was going to use a map with the stack but then I thought that would probably be over kill so I looked at techie's solution. I will be implementing it
//
//PLANNING: Create a stack. Set a current pointer to the root. Then inside a while loop if the current element is not null push it onto the stack and move the current pointer to the left child. Else grab the first element from the stack, pop it and output it's data. Then set current to the right leaf.
//
//FINAL NOTES: Works like a charm. Hopefully won't need to peak at the answer for the next one.

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
void print_tree_inorder(Node *& root)
{
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}
	cout << "Tree in inorder: ";
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

			//move current to the left node
			cur = cur->left;
		}
		else
		{
			cur = s.top();
			s.pop();
			cout << cur->key << " ";
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
	print_tree_inorder(root);
	print_tree_level(root);
	
	return 0;
}
