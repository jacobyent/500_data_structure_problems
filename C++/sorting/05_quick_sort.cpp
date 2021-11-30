//PROBLEM: Implement quick sort
//
//PLANNING: Recursively divide the array in two sorting with the use a of pivot. Stop recursion when we've reached zero, one or two elements. 
//
//FINAL NOTES: I don't think I've ever actually coded quicksort. I think I understand it a lot better now that I've actually programmed it. I also see the value of picking better pivots, considering the first two sorts on this data is worse case (-2 is the smallest, and then 9 is the greatest)

using namespace std;

#include <iostream>
void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
void quick_sort(int arr[], int left, int right)
{
	//base case for our subarray being equal to 0 or 1
	if(left >= right)
	{
		return;
	}
	//case for 2 elements, swap them if needed, return either way
	if(right - left == 1)
	{
		if(arr[left] > arr[right])
		{
			swap(arr[left],arr[right]);
		}
		return;
	}
	
	//simple pivot selection for the moment
	int pivot = arr[right];
	int loc; //pivot location value
	
	//declare two arrays for the less/greater than elements
	int less[right - left];
	int greater[right - left];
	int k = 0;
	int j = 0;
	
	//sort the elements into their proper arrays
	for(int i = left; i < right; i++)
	{
		if(arr[i] <= pivot)
		{
			less[k++] = arr[i];
		}
		else
		{
			greater[j++] = arr[i];
		}
	}

	//fill the master array with the less than array
	for(int i = 0; i < k; i++)
	{
		arr[i+left] = less[i];
	}
	
	//place the pivot
	loc = k + left;
	arr[loc] = pivot;

	//fill master with greater 
	for(int i = 0; i < j; i++)
	{
		//pretty crazy index value but it does work
		arr[i + loc + 1] = greater[i];
	}

	//recurse using our new location values
	quick_sort(arr,left, loc - 1);
	quick_sort(arr,loc + 1, right);
}
int main()
{
	int arr[] = {3,5,8,4,1,9,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,n - 1);
	print(arr,n);
	return 0;
}
