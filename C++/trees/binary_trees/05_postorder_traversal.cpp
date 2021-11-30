//PROBLEM: Given a binary tree, write iterative and recursive solution to traverse the tree using in-order traversal in C++ and java.
//
//PLANNING: Create two stacks. One for the nodes, the other for the key values. Push the root node into the first stack. Then inside a loop pop the top of the node stack and push its data into the int stack. If it has left and/or right leafs push them onto the stack. Left first, then right. Once finished empty the int stack
//
//FINAL NOTES: I could not figure out how to only do one stack. I ended up looking at techie's solution which worked well. 

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
void print_tree_postorder(Node *& root)
{
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}
	cout << "Tree in postorder: ";
	//stack for nodes 
	stack<Node*> stk;

	//push root
	stk.push(root);
	
	//stack for keys	
	stack<int> out;	
	
	Node * cur;

	//while the stack is not empty or the current pointer has a value
	while(!stk.empty())
	{
		cur = stk.top();
		stk.pop();

		out.push(cur->key);

		if(cur->left)
			stk.push(cur->left);

		if(cur->right)
			stk.push(cur->right);
	}
	while(!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
	cout << endl;
	
}
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);
	print_tree_postorder(root);
	print_tree_level(root);
	
	return 0;
}
