//PROBLEM: Given two linked lists, merge their nodes together into first list by taking nodes alternately between the two lists. If first list uns out, remaining nodes of second list should not be moved.
//
//PLANNING: One while loop, and two traversing nodes.
//
//FINAL NOTES: Finally built a pop and insert function. Other than that the problem was fairly straight forward 
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
node * pop(node *& head)
{
	//removes the first node form the list, increments the list, and then returns the former head
	if(head)
	{
		node * temp = head;
		head = head->next;
		return temp;
	}
}
void insert(node *& head, node *& to_insert)
{
	//function to insert node directly after head
	if(head && to_insert)
	{
		node * temp = head->next;
		head->next = to_insert;
		to_insert->next = temp;
	}
}

void alt_merge(node *& first, node *& second)
{
	node * current = first;
	node * temp;
	while(current && second)
	{
		temp = pop(second);
		insert(current, temp);
		current = current->next->next;
	}
}
int main()
{
	int arr[] = {1,2,3,4,5};
	int arr_0[] = {6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = sizeof(arr_0)/sizeof(arr_0[0]);
	node * first = new node;
	node * second = new node;
	build(first,arr,n);
	build(second,arr_0, m);
	alt_merge(first,second);
	out_put(first);
	out_put(second);
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
