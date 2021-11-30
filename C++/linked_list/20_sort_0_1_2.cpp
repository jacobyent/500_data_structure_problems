//PROBLEM: Given a linked list containing 0's, 1's, and 2's, sort linked list by doing a single traversal of it.
//
//EARLY NOTE: My first thought would be to count the number of each and then fill in the list. However, this would require two traversals. My next thought is to use pointers to save insert locations for each number. However, I think that might be a little too complicated rearranging the list in place. Finally, I think removing the elements and creating three new lists and then reattaching them in the end will work best.
//
//PLANNING: Create 5 pointers: one head and tail for zero and one and a head pointer for 2. Then pass through the list. Pop each node and sort them into their relevant list. Once through the list attach the tail of the zero list to the head of the one's list and the tail of that list to the head of the 2's list. 
//
//FINALE NOTE: Solution worked well. Techie used roughly the same solution as I. However, theirs is a bit leaner and I didn't account for if any of the numbers were missing. Other than that mine runs in one go and uses constant space. 
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
void sort_0_1_2(node *& head)
{
	node * zeroh = NULL;
	node * zerot = NULL;
	node * oneh = NULL;
	node * onet = NULL;
	node * twoh = NULL;
	node * temp;
	node * current = head;
	while(current)
	{
		temp = current->next;
		if(current->data == 0)
		{
			if(zeroh)
			{
				current->next = zeroh;
				zeroh = current;
			}
			else
			{
				zeroh = current;
				zerot = current;
			}
		}
		else if(current->data == 1)
		{
			if(oneh)
			{
				current->next = oneh;
				oneh = current;
			}
			else
			{
				oneh = current;
				onet = current;
			}
		}
		else
		{
			if(twoh)
			{
				current->next = twoh;
				twoh = current;
			}
			else
			{
				twoh = current;
				twoh->next = NULL;
			}
		}
		current = temp;
	}
	head = zeroh;
	zerot->next = oneh;
	onet->next = twoh;
}

int main()
{
	int arr[] = {0,1,2,2,1,0,0,2,0,1,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head,arr,n);
	sort_0_1_2(head);
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
