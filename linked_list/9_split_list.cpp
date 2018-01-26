//PROBLEM: Given a linked list, spplit its contents into two lists wherer each list contains alternating elements from the original list. THe elemnts in the new lists may be in any order.
//
//PLANNING: Traverse the list with a counter. If the counter is zero copy the contents of the current node into a new node and add that node to the first list. If the counter is one do the same but for the second list. Change the counter to the opposite of whatever was in there before. 
//
//FINAL NOTE: Pretty simple to implement. Just need to move the first and second nodes into main and modify the function if we want to use the lists for anything else. Also preserving the order in the lists would just require two tail pointers, one for each list to build off of. 

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

void alter_split(node *& head)
{
	node * current = head;
	node * first = NULL;
	node * second = NULL;
	int counter = 0;
	while(current)
	{
		if(counter == 0)
		{
			node * new_node = new node;
			new_node->data = current->data;
			new_node->next = first;
			first = new_node;
			counter++;
		}	
		else
		{
			node * new_node = new node;
			new_node->data = current->data;
			new_node->next = second;
			second = new_node;
			counter--;
		}
		current = current->next;
	}
	out_put(head);
	out_put(first);
	out_put(second);
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head, arr, n);
	alter_split(head);
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
