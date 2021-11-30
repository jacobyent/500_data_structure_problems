//PROBLEM: GIven a linked list of integers, rearrange it such that every second node of the linked list is greater than its left and right nodes. In other words, rearrange the linked list in alternating high-low.
//
//EARLY NOTES: I believe this can be done in linear time and constant space. While it would be tempting to simply transfer the data values between the nodes I think it would be better to fully change the nodes in case the nodes have more values than just what we are comparing.
//
//PLANNING: First check if the head is greater than the next element. If it is switch and set head to the new value. Create two pointers current, and previous. Set previous equal to head and current equal to head->next. Also create a boolean value dictating if current is at a second node or not (to start with this value will be true). Then create a while loop that tests for current and current->next. Inside the loop test the boolean value. If we are at a second node test if the next value is greater than it's value. If it is swap, preserving the list with the previous pointer. If it isn't incremenet current, and previous. Either way swap the boolean value. Do the opposite if we aren't at a second node.
//
//FINAL NOTES: Techie's solution works  by just changing the data values in the nodes which I wanted to avoid. My solution takes a bit more work but overall still runs as efficent as predicted.
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
node * pop(node *& head);
void insert(node *& head, node *& to_insert);
void rearrange_high_low(node *& head)
{
	node * temp;
	if(head && head->next && head->data > head->next->data)
	{
		temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
	}
	bool second = true;
	node * current = head->next;
	node * previous = head;
	while(current && current->next)
	{
		if(second)
		{
			if(current->data < current->next->data)
			{
				temp = current->next;
				current->next = temp->next;
				temp->next = current;
				previous->next = temp;
				previous = previous->next;
				current = previous->next;
			}
			else
			{
				previous = current;
				current = current->next;
			}
			second = false;
		}
		else
		{
			if(current->data > current->next->data)
			{
				temp = current->next;
				current->next = temp->next;
				temp->next = current;
				previous->next = temp;
				previous = previous->next;
				current = previous->next;
			}
			else
			{
				previous = current;
				current = current->next;
			}
			second = true;
		}	
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head,arr,n);
	rearrange_high_low(head);
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

node * pop(node *& head)
{
	//Removes the first node and returns it
	if(head)
	{
		node * temp = head;
		head = head->next;
		return temp;
	}
	return NULL;
}

void insert(node *& head, node *& to_insert)
{
	//inserts the to_insert node next after the head
	if(head && to_insert)
	{
		node * temp = head->next;
		head->next = to_insert;
		to_insert->next = temp;
	}
}
