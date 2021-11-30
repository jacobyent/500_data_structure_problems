//PROBLEM: Given an array of integers, rearrange the array such that every second element of the array is greater than its left and right elements. Assume no duplicate elements are present in the array.
//
//PLANNING: I think this can be accomplished in a single pass through. Using the swap function and two comparrisons we can swap where needed. Also the elements don't appear to need to be sorted or need any special functions
//
//FINAL NOTES: Our solutions are nearly identical. I've seen this problem before in one of my cs classes so I'm not surprised.
#include <iostream>

using namespace std;

void high_low(int arr[],int n)
{
	int temp;
	for(int i = 1; i < n; i += 2)
	{
		temp = arr[i];
		if(arr[i-1] > arr[i])
		{
			swap(arr[i-1],arr[i]);
		}
		if(i+1 < n && arr[i+1] > arr[i])
		{
			swap(arr[i+1],arr[i]);
		}

	}
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	high_low(arr,n);
	return 0;
}
