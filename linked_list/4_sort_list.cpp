//NOTE: I accidently overwrote this function when I got a bit overzealous copying it. Luckily I had already made a copy with minor revisions for the split list problem. For this problem I didn't realize I was supposed to use insertion sort so I created merge sort. I decided on merge sort after looking online for the best basic sort for linked lists. I followed a guide provided here: https://www.geeksforgeeks.org/merge-sort-for-linked-list/ I successfully followed their algorithm without having to look at their solution. 
#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
};
void split(node *& head, node *& front, node *& back, int n)
{
	node * current = head;
	for(int i = 0; i < n/2; i++)
	{
		current = current->next;
	}
	front = head;
	back = current->next;
	current->next = NULL;	
}
node * sorted_merge(node *& front, node *& back)
{
	node * head;
	node * current;
	if(!front)
	{
		head = back;
		return head;
	}
	if(!back)
	{
		head = front;
		return head;
	}	
	if(front->data > back->data)
	{
		head = back;
		back = back->next;
	}
	else
	{
		head = front;
		front = front->next;
	}
	current = head;
	while(front && back)
	{
		if(front->data > back->data)
		{
			current->next = back;
			back = back->next;
		}
		else
		{
			current->next = front;
			front = front->next;
		}
		current = current->next;
	}
	while(front)
	{
		current->next = front;
		front = front->next;
		current = current->next;
	}
	while(back)
	{
		current->next = back;
		back = back->next;
		current = current->next;
	}
	return head;

}
void merge(node *& head,int n)
{
	node * front;
	node * back;
	if(head == NULL || head->next == NULL)
	{
		return;
	}
	split(head, front, back,n);	

	merge(front, n/2);
	merge(back, n/2);
	head = sorted_merge(front,back);

	node * current = head;
}

int main()
{
	int arr[] = {8,1,4,2,3,6,5,7,9};
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
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
	merge(head,n);
	current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	return 0;
}
