//PROBLEM: Given a linked list sorted in increasing order, write a function which removes any duplicate nodes from the list by traversing the list only once.
//
//PLANNING: Traverse through the list comparing the previous node's value to the current node. If they are equal delete the current node and set the previous node's next value to the current's next (not in that order lol). If they aren't equal traverse.
//
//FINAL NOTES: Worked like a charm. Techie's solution was nearly identical except they didn't sanitize their data when deleting a node. Not that it matters too much for these purposes but I think it's a good habit to get into.
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

void remove_dup(node *& head)
{
	node * current = head;
	//traverse looking for duplicates stopping at the last element
	while(current && current->next) //this checks for empty lists, and single lists
	{
		if(current->data == current->next->data)
		{
			node * dummy = current->next;
			current->next = current->next->next;
			dummy->data = 0;
			dummy->next = NULL;
			delete dummy;
		}
		else
		{
			current = current->next;
		}
	}

}
int main()
{
	int arr[] = {1,2,2,2,3,4,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head, arr, n);
	remove_dup(head);
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
