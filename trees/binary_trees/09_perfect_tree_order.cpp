//PROBLEM: Given a perfect binary tree, write an efficient algorithm to print all nodes of it in specific order. We need to print nodes of ever level in alternating left and right.
//
//EARLY NOTES: I think a queue and a deque here work best.
//
//PLANNING: Initalize one queue and one deque. Also initalie a counter to 0. Push root onto the queue. Then start a while loop that checks if both queues are empty. Then start a for loop initalized to zero and upper bound being less than 2 to the power of the counter (1,2,4,8...). Since this is a perfect binary tree we can do it this way. Inside the for loop pop the top element add its left and right children to the queue, and add itself to the dequeue. When the for loop is finished increment the counter and then enter a while loop for the deque. Inside the deque each iteration pop and output its front element and its last element. Continue until empty
//
//FINAL NOTES: My solution should execute in n time and in n space. Techie's solutions uses two queues. There was a solution in the comments that used a single queue. They noticed that the order follows a regular pattern starting at the second row. Enqueue first node's left, second node's right, first's right, then right's left. This order holds for a perfect tree throughout. Credit to nitinj for the solution. Link: https://ideone.com/cKHzi2

#include <iostream>
#include <queue>
#include <deque>
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
void print_alt_left_right(Node *& root)
{
	//function to output in alternating left and right
	if(!root)
	{
		cout << "Tree is empty\n";
		return;
	}	
	cout << "Tree in level alt left and right: ";

	//need a counter, a queue, deque, and node pointer
	int j =0, k;
	queue<Node*> q;
	deque<int> dq;
	Node * cur;

	//enqueue root
	q.push(root);

	while(!q.empty() || !dq.empty())
	{
		k = pow(2,j);
		for(int i = 0; i < k; i++)	
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
			//enqueue into the deque
			dq.push_back(cur->key);
		}
		j++;
		while(!dq.empty())
		{
			//output and pop first element
			cout << dq.front() << " ";
			dq.pop_front();

			//output and pop back element if it exists
			if(!dq.empty())
			{
				cout << dq.back() << " ";
				dq.pop_back();
			}
		}
	}
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);
	print_alt_left_right(root);
	return 0;
}
