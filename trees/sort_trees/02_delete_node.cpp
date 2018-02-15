//PROBLEM: Given a BST, write an efficient function to delete a given key in it.
//
//EARLY NOTES: This can be done in two ways. One way would be to modify the destructor and let it handle reorgainzing the tree. The other way is to write a function. I will write a function.
//
//PLANNING: Pass through the tree until we found the node. If the node has no children delete it. If the node has one child that child occupies its former parent's location. If there are two children the right most child of the left subtree will then occupy the deleted node's place.
//
//FINAL NOTES: Techie provided a good outline for the different cases and I was able to turn that into code pretty well. I've been using a parent field in my nodes that makes problems like these a bit simpler. I'd be interested in the different merits of slightly more space intensive nodes for less complicated code vs the alternative. I imagine if one had to write a quick and dirty tree they would just throw a parent field into the node creation. However, for larger projects the more space efficent nodes would probably prevail.

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>

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
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

void build(Node *& root, int height = 3)
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
void build(Node *& root, vector<pair<string,int>> v)
{
	//function to build tree using a provided vector

	//if the root is NULL immediately return
	if(!root)
	{
		return;
	}	
	//temporary containers for our inputs
	string str;
	int temp;

	//traversal pointer directed by our string input
	Node * cur = root;

	//iterate through the vector creating nodes with the given input
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		//grab current string and int
		str = it->first;
		temp = it->second;

		//iterate over string moving to the proper node
		for(int i = 0; i < str.length() - 1; i++)
		{
			if(str[i] == 'L')
			{
				cur = cur->left;
			}	
			else
			{
				cur = cur->right;
			}
		}

		//create new node at the left or right child
		if(str[str.length() - 1] == 'L')
		{
			cur->left = new Node(temp,cur);
		}
		else
		{
			cur->right = new Node(temp,cur);
		}

		//make sure to reset cur after each traversal
		cur = root;
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
void delete_found(Node *& cur)
{
	//function to move pointers around and delete a node in a bst

	//if the node lacks children just delete it outright
	if(!cur->left && !cur->right)
	{
		//replace the parent's pointer with this node 
		if(cur->parent->left == cur)
		{
			cur->parent->left = NULL;
		}
		else
		{
			cur->parent->right = NULL;
		}
	}
	//if the node has both children then we need the right most leaf of its left subtree
	else if(cur->left && cur->right)
	{
		//grab is our traversal pointer, initalize at the left subtree
		Node * grab = cur->left;

		//traverse until we find the rightmost node
		while(grab->right)
		{
			grab = grab->right;
		}

		//first remove the node from the tree
		grab->parent->right = NULL;

		//then replace the left, right, and parent values with the to-be deleted node's
		grab->parent = cur->parent;
		if(cur->left == grab)
		{
			grab->left = NULL;
		}
		else
		{
			grab->left = cur->left;
		}
		grab->right = cur->right;

		//finally replace the parent's pointer with this node 
		if(cur->parent->left = cur)
		{
			cur->parent->left = grab;
		}
		else
		{
			cur->parent->right = grab;
		}
	}
	else
	{
		//if only one child replace the node with that child
		if(cur->left)
		{
			if(cur->parent->left = cur)
			{
				cur->parent->left = cur->left;
			}
			else
			{
				cur->parent->right = cur->right;
			}
		}
		else
		{

			if(cur->parent->left = cur)
			{
				cur->parent->left = cur->left;
			}
			else
			{
				cur->parent->right = cur->right;
			}
		}
	}

	//finally, delete the node and set the pointer to null
	delete cur;
	cur = NULL;
}
void delete_node(Node *& root, int key)
{
	//initalize traversal pointer to root
	Node * cur = root;

	//traverse the bst until we find the key or until we hit a null pointer
	while(cur)
	{
		if(cur->key == key)
		{
			//if we found the node delete it with this function
			delete_found(cur);
		}
		else if(cur->key > key)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
}
int main()
{
	Node * root = new Node;
	root->key = 15;
	vector<pair<string,int>> v = {
		{"L",10}, {"LL",8},{"LR",12},{"R",20},
		{"RL",16},{"RR",25}
	};
	build(root,v);
	delete_node(root,10);
	print_tree_level(root);
	return 0;
}
