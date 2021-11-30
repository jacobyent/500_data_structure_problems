//PROBLEM: Given an array of integers, find equilibrium index in it.
//
//EARLY NOTES: I think this can be solved in a similar way to the zero subarray problem. We could use a multimap to track all the different sums of the subarrays. We might then need another pass where we remove individual elements from the sums to their right... 
//MID NOTES: After thinking about my approach for awhile I realized it wouldn't work because it would basically be calculating all the subarrays which would take n2 time while using n2 space. So I looked at techie's solution. As usual my approach is over complicated.
//PLANNING: Sum the whole array then starting from the back create a right sub array sum. Then subtract the right array sum and the current element from the total to get the left sum. If the left and right are equal the pivot element is our equilbrium point

#include <iostream>

using namespace std;

void equalibrium(int arr[], int n)
{
	int total = 0, right = 0;
	for(int i = 0; i < n; i++)
	{
		total += arr[i];
	}
	for(int i = n; i > 0; i--)
	{
		if(right == total - (arr[i-1] + right))
		{
			cout << "Equilbrium at index: " << i - 1 << endl;
		}
		right += arr[i-1];
	}
}

int main()
{
	int arr[] = {0,-3,5,-4,-2,3,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	equalibrium(arr,n);
	return 0;
}

