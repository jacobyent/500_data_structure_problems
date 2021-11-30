//PROBLEM: Given two linked lists, merge their nodes together to make one list, taking nodes alternately between the two lists. If either list runs out, all the nodes should be taken from the other list.
//
//EARLY NOTES: I thought this was going to be the merge function I wrote earlier for the sort problem. It's a bit easier than that so I'm just going build it form the ground up.
//
//PLANNING: A tail pointer, and three while loops should be everything we need. Initally the tail and head pointer will be the same but as the list grows the tail will point to the last element. Current pointer for traversal. This will just be a straight up merge so no need to copy or delete nodes so we can just use the old head pointers for traversal. The first while loop will build the list until either list is exhausted. Then the other two while loops will add the remaining elements

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

void alt_merge(node *& head, node *& first, node *& second)
{
	int counter = 1;
	head = first;
	node * tail = head;
	first = first->next;
	while(first && second)
	{
		if(counter == 0)
		{
			tail->next = first;
			tail = tail->next;
			first = first->next;
			counter++;
		}
		else
		{
			tail->next = second;
			tail = tail->next;
			second = second->next;
			counter--;
		}
	}	
	while(first)
	{
		tail->next = first;
		tail = tail->next;
		first = first->next;
	}

	while(second)
	{
		tail->next = second;
		tail = tail->next;
		second = second->next;
	}
	tail = NULL;
}

int main()
{
	int arr_0[] = {1,2,3,4};
	int n = sizeof(arr_0)/sizeof(arr_0[0]);
	node * first = new node;
	build(first, arr_0, n);
	int arr_1[] = {5,6,7,8,9};
	int m = sizeof(arr_1)/sizeof(arr_1[0]);
	node * second = new node;
	build(second, arr_1, m);
	node * head = NULL;
	alt_merge(head,first,second);
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
