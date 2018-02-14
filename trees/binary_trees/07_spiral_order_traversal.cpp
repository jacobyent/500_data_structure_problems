//PROBLEM: Given a binary tree, print its nodes level by level in spiral order. i.e. all nodes present at leve l1 should be printed first from left to right, followed by nodes of level 2 right to left, followed by nodes of level 3 from left to right and son on.. In other words, odd levels should be printed from left to right and even levels should be printed from right to left or vice versa
//
//EARLY NOTES: I think this should only require a small modification to the level output but that could be underestimating.
//
//PLANNING: Use two stacks, one for odd, one for even. Push the root onto the odd stack. Run a while loop that checks for both odd and even being empty. Then another while loop for each stack. Inside the odd loop pop the top element and add its children from left to right, then output. Do the same with the even stack but add right to left.
//
//FINAL NOTES: I'm pretty sure this program takes n space and is in n time. While there is two stacks each node only gets put into one stack. Techie's queue solution is probably better because they only initalize a single queue but they also have extra fixings. I imainge both implementations are quite quick.
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
void print_tree_spiral(Node *& root)
{
	//function to output the tree in a spiral order
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}	
	cout << "Tree in spiral order: ";
	//two queues, even and odd
	stack<Node*> odd;
	stack<Node*> even;

	//enqueue first node
	odd.push(root);

	//declare node pointer
	Node * cur;

	while(!odd.empty() || !even.empty())
	{
		while(!odd.empty())
		{
			//Grab front element
			cur = odd.top();

			//pop front element
			odd.pop();

			//output current element
			cout << cur->key << " ";

			//add children if any to queue
			if(cur->left)
			{
				even.push(cur->left);
			}
			if(cur->right)
			{
				even.push(cur->right);
			}
		}
		while(!even.empty())
		{
			//Grab front element
			cur = even.top();

			//pop front element
			even.pop();

			//output current element
			cout << cur->key << " ";

			//add children if any to queue
			if(cur->right)
			{
				odd.push(cur->right);
			}
			if(cur->left)
			{
				odd.push(cur->left);
			}
		}
	}
	cout << endl;
}
int main()
{
	Node * root = new Node;
	int height = 5;
	build_tree(root,height);
	print_tree_spiral(root);
	return 0;
}
