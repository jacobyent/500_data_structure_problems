//NOTE: This is just a basic template so I don't have to keep writing out the struct class, the include, etc every time.


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

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head, arr, n);
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
