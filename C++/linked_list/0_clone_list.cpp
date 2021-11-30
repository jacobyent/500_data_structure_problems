//PROBLEM: Write a function that takes a singly linked list and returns a compete copy of that list
//PLANNING: I've done this problem before in class. We can use a recursive call to clone each node and then move both lists onto the next node. 
//NOTES: Had to look up some old code from class to remember how to build the struct. Techiedelight used the recursive measure as an example but they pointed out that it uses a lot of extra space in the stack that the other methods didn't. In the future I'll avoid this solution. I am however happy I was able to do it ffrom memory.
#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next = NULL;
};
void clone_list(node *& old, node *& clone)
{

	clone->data = old->data;
	if(old->next)
	{
		clone->next = new node;
		clone_list(old->next, clone->next);
	}
}	

int main()
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	node *head = new node;
	node * current = head;

	head->data = arr[0]; 
	for(int i = 1; i < n; i++)
	{
		current->next = new node;
		current = current->next;
		current->data = arr[i];
	}
	node * clone = new node;
	clone_list(head, clone);
	current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
	current = clone;	
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	return 0;
}


