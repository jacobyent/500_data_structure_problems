//PROBLEM: Given an array of integers, move all zeros present in the array to the end. The solution should maintain the relative order of items in the array.
//
//EARLY NOTES: My first instinct was a counting technique but that wouldn't work becuase we need to preserve order. Next I thought of using two pivots starting from the end but that wouldn't be guarenteed to preserve order, at least I don't think it would be. Now I'm thinking of some kind of bubble sort technique. I think I can do it in linear time and constant space using in place swap and backign up when a zero is first. The more I thought about it this approach would take n2 time.
//
//PLANNING: Looked up the solution. Very simple using a pivot. Start a counter at 0. Every time we encounter a non-zero element swap with the element located at the counter value, then increment the counter. This works because the counter will preserve the location of the last known zero and will lag behind the for loop by the number of zeros. 
//
//FINAL NOTES: During my early thoughts I thought the problem required a stable sort when it said maintain the relative order. I was trying to keep the zeros in order when I didn't need to. 

#include <iostream>

using namespace std;

void zero_end(int arr[], int n)
{
	int j = 0;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] != 0)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
	int n = sizeof(arr)/sizeof(arr[0]);

	zero_end(arr, n);

	return 0;
}
