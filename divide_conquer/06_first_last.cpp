//PROBLEM: Given a sorted array of integers, find index of first or last occurrence of a given number. If the element is not found in the array, report that as well
//
//EARLY NOTES && PLANNING: I believe we can binary search for an occurance. When we find one we check if low and high are also at a target. If they are (and we haven't already found first and last) set the respective values to first and last and set their values to mid. Then check if low and high are equal to mid. If they both are exit the loop. Otherwise continue binary searching.
//
//FINAL NOTES: I tried to find both first and last in one method. I'm sure there is a way to do it but splitting it up into two functions is much simplier. 

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
	
	int T = 5;	
	
	int first = first_occ(arr,n,T);
	int last = last_occ(arr,n,T);
	
	if(first == -1)
	{
		cout << "Element not found in array\n";
	}
	else
	{
		cout << "First occurrence of element " << T << " is found at index " << first << endl;
		cout << "Second occurence of element " << T << " is found at index " << last << endl;
	}
	return 0;
}
