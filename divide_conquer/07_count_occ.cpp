//PROBLEM: Given a sorted array of integers containing duplicatres, count the number of occurrences of a number provided. If the element is not found in the array, report that as well.
//
//EARLY NOTES: I believe we can just straight up copy the code from the previous quetsion and modify the output. 
//
//PLANNING: Find the first and last occurrences of the element. When we're finished take the difference between the first and last and that will be the number of occurrences. 
//
//FINAL: Not much to say here. Techie implemented a single function with a clever modifier to find first and last. I sticked to one function each but in the future I'll look for ways to do something similar.

using namespace std;

#include <iostream>

int first_occ(int arr[], int n, int T)
{
	int low = 0, high = n - 1;
	int mid;
	int first = -1;
	while(low <= high)
	{
		mid = (low + high)/2;

		if(arr[mid] == T)
		{
			first = mid;
			high = mid -1;
		}
		else if(arr[mid] > T)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return first;
}
int last_occ(int arr[], int n, int T)
{
	int low = 0, high = n - 1;
	int mid;
	int last = -1;
	while(low <= high)
	{
		mid = (low + high)/2;

		if(arr[mid] == T)
		{
			last = mid;
			low = mid + 1;
		}
		else if(arr[mid] > T)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return last;
}

int main()
{ 
	int arr[] = {2,5,5,5,6,6,8,9,9,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int T = 10;	
	
	int first = first_occ(arr,n,T);
	int last = last_occ(arr,n,T);
	
	if(first == -1)
	{
		cout << "Element not found in array\n";
	}
	else
	{
		cout << "Element " << T << " occurs ";
		if(first == last)
		{
			cout << 1 << " time\n";
		}
		else
		{
			cout << last - first + 1 << " times\n";
		}
	}
	return 0;
}
