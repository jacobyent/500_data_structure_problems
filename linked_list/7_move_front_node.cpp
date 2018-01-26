//PROBLEM: Given a linked list, move front node of it to the front of the other given list.
//
//PLANNING: Grab the first node, set the list's head to the next element. Set the first node's next value to the front of the second list, then set the second list's head value to our new first node.
//
//FINAL NOTE: Very simple problem showing the value of linked lists v arrays
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

void transfer_head(node *& first, node *& second)
{
	//pointer juggling the hot new craze
	node * temp = first;
	first = first->next;
	temp->next = second;
	second = temp;
}

int main()
{
	int arr[] = {1,2,3};
	int other[] = {6,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = sizeof(other)/sizeof(other[0]);
	node * first = new node;
	build(first, arr, n);
	node * second = new node;
	build(second,other,m);
	transfer_head(first, second);
	out_put(first);
	out_put(second);
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
