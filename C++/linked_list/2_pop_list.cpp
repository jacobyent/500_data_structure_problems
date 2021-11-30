//PROBLEM: Write a Pop() function taht is the inverse of Push(). Pop() takes a non-empty list, deletes the head node, and returns the head node's data.

//PLANNING: I will use a temporary pointer to hold onto the list while head is deleted and then replace head with the next node in the list.

//EARLY NOTES: This problem answers my last question in regards to writing a destructor that deletes everything. Without paying attention the destructor could delete our whole list accidently. I'm still not sure about the relavtive merits in terms of performance between the three methods.

//NOTES: Learned the difference between free and delete from cplusplus.com. My method differed from techie's a bit because my function returns a new head pointer rather than the data. By returning the new head pointer I can skip writing their push function. I would need to rewrite this if the data needed to be returned to the block rather than the io but this works well enough for me. 
#include <iostream>

using namespace std;

struct node
{
	int data;
	node * next = NULL;
	~node()
	{
		data = 0;
		next = NULL;
		cout << "Node deleted!" << endl;
	}
};

node * Pop(node *& head);
node * Pop(node *& head)
{
	if(head)
	{
		node * new_head = head->next;
		cout << "Pop!: " << head->data << endl;
		delete head;
		return new_head;
	}
	return head;
}

int main()
{
	int arr[] = {1,2,3,4,5};
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
	while(head)
	{
		head = Pop(head);
	}
	return 0;
}

