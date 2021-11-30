//Given a linked list and two positive integers M and N, delete every N nodes in it after skipping M nodes.
//
//PLANNING: First a for loop to move current to it's starting position (minus one to accomodate the delete next function). One while loop to traverse and two for loops inside. The first for loop is to delete the next node in the list. I delete the next node to preserve the list between deletions. The second for loop skips over the nodes that will not be deleted
//
//FINAL NOTES: I built my solution iteratively compared to techie's recursion. Their solution is more elegant in some ways but recursion always has a cost. If I were to do this again I would lift their way of deleting the nodes. To properly delete my nodes I needed to engineer a solution that would delete the next node. Which made my code a little awkward. Simply deleting the nodes and then reattaching the list is better than trying to preserve the list while deleting everything.
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
void delete_next_node(node *& head)
{
	if(head && head->next)
	{
		node * temp = head->next;
		head->next = temp->next;
		temp->next = NULL;
		delete temp;
	}
}
void delete_m_n(node *& head, int M, int N)
{
	node * current = head;
	for(int i = 0; i < M -1 && current; i++)
	{
		current = current->next;
	} 
	while(current)
	{
		for(int i = 0; i < N; i++)
		{
			delete_next_node(current);
		}
		for(int i = 0; i < M && current; i++)
		{
			current = current->next;
		} 
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int M = 1;
	int N = 3;
	node * head = new node;
	build(head,arr,n);
	delete_m_n(head,M,N);
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
