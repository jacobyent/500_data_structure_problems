//PROBLEM: Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. The new list should be made with its own memory--the original lists should not be changed.
//
//EARLY NOTES: I think this can be done in m + n time and constant space. Constant space except for the new list that is. We'll need two traversal pointers, a head pointer, and a tail pointer. A while loop that checks if either list is exhausted. 
//
//PLANNING: Compare values. If they are equal create a new node and add it to the tail of the new list. Then traverse both lists to the next nodes. If they are not traverse the list with the smaller canidate to the next value.
//
//FINAL NOTES: Got a little tripped up with creating the new list. Normally I could just append whatever element would come first to the head of the new list but here there is no guarentee that the new list would have anything. To get around this I used a dummy node at the start then built off of it. Then deleted the dmmy node at the end.
#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
};

void split(node *& head, node *& front, node *& back, int n);
node * sorted_merge(node *& front, node *& back);
void merge(node *& head,int n);
void build(node *& head,int arr[],int n);
void out_put(node *& head);

void intersection(node *& head, node *& first, node *& second)
{
	node * one = first;
	node * two = second;
	head = new node;
	node * tail = head;
	while(one && two)
	{
		if(one->data == two->data)
		{
			tail->next = new node;
			tail = tail->next;
			tail->data = one->data;
			one = one->next;
			two = two->next;
		}
		else if(one->data > two->data)
		{
			two = two->next;
		}
		else
		{
			one = one->next;
		}
	}
	node * dummy = head;
	head = head->next;	
	delete dummy;
}
int main()
{
	int arr[] = {1,4,7,10};
	int arr_0[] = {2,4,6,8,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = sizeof(arr_0)/sizeof(arr_0[0]);
	node * head = NULL;
	node * first = new node;
	node * second = new node;
	build(first,arr,n);
	build(second,arr_0,m);
	intersection(head,first,second);
	out_put(head);
	return 0;
}

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
void build(node *& head,int arr[], int n)
{
	node * current = head;
	current->data = arr[0];
	for(int i = 1; i < n; i++)
	{
		current->next = new node;
		current = current->next;
		current->data = arr[i];
	}
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
