//implementation file for my queue class

#include "My_Queue.h" 

My_Queue::My_Queue()
{
	length = 0;
	head = NULL;
	tail = NULL;
}
void My_Queue::enqueue(int n)
{
	if(length == 0)
	{
		head = new Node;
		tail = head;
		head->data = n;
		length++;
	}
	else
	{
		tail->next = new Node;
		tail = tail->next;
		tail->data = n;
		length++;
	}
}
void My_Queue::dequeue()
{
	if(head)
	{
		Node * temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		length--;
		if(length == 0)
		{
			tail = NULL;
		}
	}
}
int My_Queue::peak()
{
	if(head)
	{
		return head->data;
	}
	return 0;
}
bool My_Queue::empty()
{
	if(length == 0)
	{
		return true;
	}
	return false;
}
