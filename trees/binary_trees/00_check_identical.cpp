//PROBLEM: Write an efficient algorithm to check if two binary trees are identical or not. i.e. if they have identical structure & their contents are also same
//
//EARLY NOTES: I believe a bfs approach works well here. We'll traverse both trees using a single queue. Every iteration we'll pop two elements and check their values. If they match enqueue any children. Continue until the queue is empty or the trees diagree in value
//
//PLANNING: See early notes
//
//FINAL NOTES: I used a queue solution while techie used a stack. I know the main difference between a queue and a stack is lifo v fifo but beyond that I'm uncertian if the overhead for either is more efficent. Both solutions execute in n+m time though and use n+m space

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
	int num = pow(2,height + 1);
	
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
}

bool identical_trees(Node *& root_0, Node *& root_1)
{
	//build our queue
	queue<Node *> q;

	//enqueue our starting elements
	q.push(root_0);
	q.push(root_1);

	while(!q.empty())
	{
		//grab and pop our first element
		Node * one = q.front();
		q.pop();
		
		//if the queue is empty then our trees don't match
		if(q.empty())
		{
			return false;
		}
		
		//grab the next node	
		Node * two = q.front();
		q.pop();
		
		//if our nodes have different values return false	
		if(one->key != two->key)
		{
			return false;
		}

		if(one->left)
		{
			q.push(one->left);
		}
		if(two->left)
		{
			q.push(two->left);
		}
		if(one->right)
		{
			q.push(one->right);
		}
		if(two->right)
		{
			q.push(two->right);
		}
	}
	return true;
}
int main()
{
	Node * root = new Node;
	int height = 3;
	build_tree(root,height);

	Node * root_2 = new Node;
	build_tree(root_2,height);

	bool test = identical_trees(root,root_2);
	if(test)
	{
		cout << "Trees are identical!\n";
	}
	else
	{
		cout << "Trees are not identical!\n";
	}
	return 0;
}
