//PROBLEM: Given a binary tree, print its nodes level by level in reverse order. i.e. all nodes present at last level should be printed first followed by nodes of second last level and so on.. All nodes for any level should be printed from left to right
//
//EALY NOTES: Perhaps another two queue/stack solution. 
//
//PLANNING: Create one queue and one stack. Push the root onto the the queue. Then pop the front element in the queue add it's right and left children to the queue and then push it onto the stack. Then empty the stack.
//
//FINAL NOTES: Their solution is identical to mine, which is great for me. Their hasing approach I think understand but haven't implemented a strategy like that yet. 
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

void print_tree_reverse_level(Node *& root)
{
	//function to output the tree in a level or bfs method
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}	
	cout << "Tree in level traversal: ";
	//will use a queue and a stack
	queue<Node*> q;
	stack<Node*> stk;

	//enqueue first node
	q.push(root);

	//current pointer
	Node * cur;

	while(!q.empty())
	{
		//Grab front element
		cur = q.front();
		
		//pop front element
		q.pop();

		//add children if any to queue
		if(cur->right)
		{
			q.push(cur->right);
		}
		if(cur->left)
		{
			q.push(cur->left);
		}
		//add element to the stack
		stk.push(cur);
	}
	
	//empty stack	
	while(!stk.empty())
	{
		//grab and pop top element
		cur = stk.top();
		stk.pop();
		
		//output
		cout << cur->key << " ";
	}

}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	print_tree_reverse_level(root);
	return 0;
}
