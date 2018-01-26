//PROBLEM: Rearrange the given linked list such that every even node will be moved to the end of the list in reverse order.
//
//PLANNING: Traverse the list to the end (or use a tail pointer). Then traverse again setting each even number's next pointer to the value of the tail's next pointer and switching the previous next pointer's value to the next element.

#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
};

//helper functions will be placed after main
void out_put(node *& head);
void build(node *& head, int arr[], int n);

void move_even(node *& head)
{
	node * current = head;
	node * tail;
	node * previous = head;
	node * dummy;
	//creating our tail pointer
	while(current->next)
	{
		current = current->next;	
	}
	tail = current; 

	current = head;
	while(current != tail) //once we've reached our tail we stop
	{
		if(current->data % 2 == 0) //check for evenness 
		{
			//move our node out of the list
			dummy = current->next;
			previous->next = dummy; 
			//transfer it to the end
			current->next = tail->next;
			tail->next = current;
			//reset current
			current = dummy;
		}
		else
		{
			//if it's not even simply traverse
			previous = current;
			current = current->next;
		}
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head, arr, n);
	move_even(head);
	out_put(head);
	return 0;
}

void out_put(node *& head)
{
	node * current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void build(node *& head, int arr[], int n)
{
	node * current = head;
	head->data = arr[0];
	for(int i = 1; i < n; i++)
	{
		current->next = new node;
		current = current->next;
		current->data = arr[i];
	}
}
