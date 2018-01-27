//PROBLEM: Given a linked list, reverse every adjacent group of k nodes in it where k is a given positive integer.
//
//EARLY NOTES: I will use iteration to reverse the sections and use a dummy node to keep track of the list. 
//
//PLANNING: Two while loops, the first to traverse and the second to reverse. Even with both loops we should only traverse each node once. Exchange the nodes by configuring their pointers. Reverse using the iterative method. 
//
//FINAL NOTES: Reversing was a pain because I had to juggle all the pointers. I threw it all in a function so that I could more easily keep track of the pointers. Techie's solution is similar but they moved a few things around namely their loop to reverse sections is one function while mine is built into my reverse_k function. 
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

void reverse(node *& head, node *& tail)
{
	//Reverse moves the tail->next node to after head
	node * move = tail->next;
	node * h_next = head->next;
	node * m_next = move->next;

	move->next = head->next;
	head->next = move;
	tail->next = m_next;

	move = NULL;
	h_next = NULL;
	m_next = NULL;
}
void reverse_k(node *& head, int k)
{
	//function reverses sections of the list in linear time and constant space.
	int i;
	node * tail;
	//This dummy node is needed to properly reverse the first element it is latter deleted
	node * dummy_head = new node; 
	dummy_head->next = head;
	node * current = dummy_head;

	while(current)
	{
		i = 1; //reset counter on each loop
		tail = current->next;
		while(tail && tail->next && i < k)
		{
			reverse(current, tail);
			i++;
		}
		current = tail; //move current forward to the previous next value and start again
	}

	head = dummy_head->next;
	dummy_head = NULL;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head,arr,n);
	reverse_k(head,3);
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
