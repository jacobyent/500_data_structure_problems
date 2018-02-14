//PROBLEM: Given a binary tree, determine if two given nodes are cousins of each other or not. Two nodes of binary tree are cousins of each other only if they have different parents but they have same level
//
//EARLY NOTES: My first attempt at this solution involved checking the children of each node as we came across it in level order. The solution was more or less fine but it looked really ugly. After viewing techie's solution I restarted and implemented their parent solution. However, I changed my template a bit to include the parent in the constructor and destructor. 
//
//PLANNING: Traverse the tree in level order. If we encounter a cousin check the rest of the nodes in the level. If we don't find the other canidate then they aren't cousins and we can exit. If we do find the other canidiate then check their parents. If they have the same parent they are not cousins and we exit. If they are different then they are cousins and we can exit.
//
//FINAL NOTES: It occured to me that many of these problems could be rendered much more simple by keeping track of the height value inside the nodes themselves. This would of course use extra space but I'm curious about the trade off in terms of speed and extra space. Of course so far all these problems assume that we aren't given that value and have to traverse the bare minimum way. 

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

//our not so basic node structure
struct Node {
	int key;

	Node *left, *right;
	Node *parent;

	//constructor	
	Node(int value = 0,Node * par = NULL)
	{
		key = value;
		left = NULL;
		right = NULL; 
		parent = par;
	}

	//destructor
	~Node()
	{
		key = 0;
		delete left;
		delete right;
		left = NULL;
		right = NULL;
		if(parent)
		{
			if(parent->left == this)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		parent = NULL;
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
		cur->left = new Node(i++,cur);

		cur->right = new Node(i++,cur);

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
bool check_cousins(Node *& root,int one, int two)
{
	//function to test if two numbers are cousins 
	if(!root)
	{
		cout << "Tree is empty\n";
		return false;
	}	
	//will use a queue
	queue<Node*> q;

	//enqueue first node
	q.push(root);

	//declare node pointer and parent pointer
	Node * cur;
	Node * par;

	//ints for level traversal
	int i,size;

	while(!q.empty())
	{
		i = 0;
		size = q.size();
		par = NULL;
		while(i < size)
		{
			//Grab and pop front element
			cur = q.front();
			q.pop();

			//increment counter
			i++;

			//if the current node has a cousin
			if(cur->key == one || cur->key == two)
			{
				//if parent is not null we've seen a cousin this level already
				if(par && par != cur->parent)
				{
					//if this node doesn't have the same parent then we've found cousins
					return true;
				}
				else if(par)
				{
					//this triggers if the parents are equal so we return false
					return false;
				}
				//if par is still NULL we defualt and assign parent to par
				par = cur->parent;
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
		//if we've reached this point in the loop and par is flagged then we didn't find the other cousin and can return false
		if(par)
		{
			return false;
		}
	}
	//if we never see either candiate then we can return false
	return false;
}
int main()
{
	Node * root = new Node;
	int height = 4;
	build_tree(root,height);

	int one = 1;
	int two = 2;
	if(check_cousins(root, one,two))
	{
		cout << one << " & " << two << " are cousins\n";
	}
	else
	{
		cout << one << " & " << two << " are not cousins\n";
	}	
	
	return 0;
}
