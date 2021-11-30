//header file for my queue class. This queue is implemented as a linked list
#include <iostream>

struct Node
{
	int data;
	Node * next = NULL;
};
class My_Queue
{
	private:
		int length;
		Node * head;
		Node * tail;
	public:
		My_Queue();
		void enqueue(int n); //place new node at end
		void dequeue(); //remove front node 
		int peak(); //look at first element
		bool empty(); //checks whether the queue is empty or not
};

