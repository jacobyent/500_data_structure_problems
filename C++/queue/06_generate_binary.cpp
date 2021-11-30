//PROBLEM: Given a positive number N, efficienty generate binary numbers between 1 to N using queue data structure and in linear time.
//
//EARLY NOTES: A different problem than the ones so far. My first instinct is to use strings and bulid them until we've reach the given limit. I'll do that and check techie's approach after  
//
//PLANNING: Create a count down variable. When it reaches zero stop adding strings and empty the queue. Build the digits by adding 0 and 1 to the end each iteration, and enqueueing these values
//
//FINAL NOTES: Arghghg, I wrote code that worked very quickly. The only issue is that their example solution is/was wrong. They have n = 10 with the output ending in 10000 which is actually 16. I was confused for awhile until I realized it was typo and my code was working fine.

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
void binary_queue(int n)
{
	//make our queue
	queue<string> q;

	//enqueue 1
	q.push("1");
	
	//start a count
	int count = 1;

	//while n is greater than 0 continue building and outputting digits
	while(count < n)
	{
		//grab the next digit
		string cur = q.front();
		
		//pop the front element
		q.pop();

		//output the element
		cout << cur << " ";

		//build the next digit
		q.push(cur + "0");
		
		//increment our count
		count++;

		//build the next digit if we haven't reached the limit
		if(count++ < n)
		{
			q.push(cur + "1");
		}
	}

	//empty the queue of remaining elements
	while(!q.empty())
	{
		//grab the digit
		string cur = q.front();

		//pop it
		q.pop();

		//output digit
		cout << cur << " ";
	}
	cout << endl;
}
int main()
{
	int n = 16;
	binary_queue(n);
	return 0;
}
