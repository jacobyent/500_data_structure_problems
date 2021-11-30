//PROBLEM: Write a function that takes a linked list, deallocates all of its memory and sets its head pointer to nullptr(the empty list).
//PLANNING: I plan to use a destructor which should cause a cascade of deleted nodes
//NOTES: Techie used two methods I am familar with namely a loop and recursion. They did not use my method so I'm unsure how it compares. Are they comparable in efficeny? Are there differences when the list is large? 
#include <iostream>

using namespace std;

struct node
{
	int data;
	node * next = NULL;
	~node()
	{
		data = 0;
		delete next;
		next = NULL;
		cout << "Node deleted!" << endl;
	}
};

int main()
{
	int arr[] = {0,1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	node * current = head;
	head->data = arr[0];
	for(int i = 1; i < n; i++)
	{
		current->next = new node;
		current = current->next;
		current->data = arr[i];
	}
	current = head;
	while(current)
	{
		cout << current->data;
		current = current->next;
	}
	cout << endl;
	delete head;
	return 0;
}






