//PROBLEM: Write a function that takes two lists, each of which is sorted in increasing order, and merges the two together into one list which is in decreasing order and return it. In other words, merge two sorted linked lists from their end.
//
//EALRY NOTES: The worst way to do this would be by repeatly tracing through each list to get to the end. That would take n2+m2 time. The best way to do it would just be to merge the two lists using sorted_merge and then reverse the list.
//
//PLANNING: Start by merging the two lists with sorted_merge (linear time and constant space). Then reverse the list via dummy node, which should also take linear time and constant space.
//
//FINAL NOTES: While my solution certianly works I believe theirs is more efficent. I make two passes through the list. The first to merge it, the second to reverse it. They manged to make one pass by properly modifiying the merge something that clearly didn't occur to me. 
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

void reverse(node *& head)
{
	node * fake = new node;
	node * temp;
	while(head)
	{
		temp = pop(head);
		insert(fake,temp);
	}
	head = fake->next;
	fake->next = NULL;
	delete fake;
}

int main()
{
	int arr[] = {1,3,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int arr_0[] = {2,6,7,10};
	int m = sizeof(arr_0)/sizeof(arr_0[0]);
	node * first = new node;
	node * second = new node;
	build(first,arr,n);
	build(second,arr_0,m);
	cout << "First list: ";
	out_put(first);
	cout << "Second list: ";
	out_put(second);
	node * head = sorted_merge(first,second);
	reverse(head);
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
