//PROBLEM: Given a list that is sorted in increasing order, and a single node, insert the node into the correct sorted position in the given list. The function should take an existing node, and just rearrange pointers to insert it into the list.
//
//EARLY NOTES: Should be simple enough. Traverse the list until the node finds a value that it is less than then place the node there. We'll need to keep track of the previous node so we can modify it's next value.

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next = NULL;
};

void insert(node*& head, int value)
{
	node * previous = head; //need to know previous node
	node * current = head; //for traversal

	node * new_node = new node;
	new_node->data = value;

	if(head) //make sure list exists
	{
		//if value is less than what's in head then we need to move the value in head to the next node and replace head with the new value
		if(value < head->data)
		{
			int temp = head->data;

			current = head->next; //use current to keep track of the next node
			head->next = new_node;
			new_node->next = current;

			head->data = value; //swap values in head and new node
			new_node->data = temp;
			return; // we're done after this point
		}	
		else
		{
			//traverse through the list until we find a node with data > value or end of list
			while(current && current->data < value)
			{
				previous = current;
				current = current->next;
			}	
		}

		previous->next = new_node;
		new_node->next = current;
	}
	else
	{
		//create list if it doesn't exist
		head = new_node;
	}

}
int main()
{
	int arr[] = {1,2,3,4,6,7,8}; //values to build the list
	int n = sizeof(arr)/sizeof(arr[0]);
	int value = 5; //value to be inserted
	node * head = new node; //create list
	head->data = arr[0];
	node * current = head;
	//fill list with values
	for(int i = 1; i < n; i++)
	{
		current->next = new node;
		current = current->next;
		current->data = arr[i];
	}
	insert(head, value); 
	//print to screen
	current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
}
