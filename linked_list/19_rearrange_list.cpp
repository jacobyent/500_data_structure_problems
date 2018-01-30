//PROBLEM: Given a linked list, rearrange linked list nodes in specific way in linear time and constant space. The alternate positions in the output list should be filled with the nodes starting from the beginning and from the very end of the original list respectively.
//
//EARLY NOTES: I thought about this problem for a bit and the only way I could think to do it without using extra space was to split it in half, reverse the second half and then alt merge. I thought this would violate the linear time requirment because we'd traverse the second list twice but of course that is still linear time. Anyways I looked up techies solution and they use exactly this method so I think I'm getting better at this.
//
//PLANNING: Split the list in half, reverse the second half and then alt merge them together.
//
//FINAL NOTES: Solution worked well. I borrowed the reverse function from techie's iterative reverse guide. I've have trouble writing my own reverse function and fianlly follwed their guide more closely. Other than that the merge alt was the same as in problem 10
#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next = NULL;
};

void split(node *& head, node *& front, node *& back);
void build(node *& head,int arr[],int n);
void out_put(node *& head);
node * pop(node *& head);
void insert(node *& head, node *& to_insert);
void reverse(node *& head)
{
	node * fake = NULL;
	node * current = head;
	node * next;
	while(current)
	{
		next = current->next;
		current->next = fake;
		fake = current;
		current = next;
	}	
	head = fake;
}
void rearrange(node *& head)
{
	node * back = NULL;
	split(head, head, back);	
	reverse(back);
	node * current = head;
	node * temp;
	while(back && current)
	{
		temp = current->next; //store the rest of the list

		current->next = back; //insert a new element

		back = back->next; //increment the back list

		current = current->next; //increment to new element

		current->next = temp; //fix the next pointer to the reest of the list 

		current = current->next; //increment to the next element
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * head = new node;
	build(head,arr,n);
	rearrange(head);
	out_put(head);
	return 0;
}

void split(node *& head, node *& front, node *& back)
{
	node * slow = head;
	node * fast = head;
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	front = head;
	back = slow->next;
	slow->next = NULL;
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
