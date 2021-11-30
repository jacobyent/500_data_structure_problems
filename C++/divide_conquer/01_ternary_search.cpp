//PROBLEM: Implement a ternary search 

using namespace std;

#include <iostream>
#include <climits>
int binary_search(int arr[],int n, int target)
{
	int low = 0;
	int high = n - 1;
	int mid = n/2;
	int index = -1;

	while(low <= high)
	{
		if(arr[mid] == target)
		{
			index = mid;
			low = INT_MAX;
		}
		else if(arr[mid] > target)
		{
			high = mid - 1;
			mid = (high + low)/2;
		}
		else
		{
			low = mid + 1;
			mid = (high + low)/2;
		}
	}
	return index;
}
int ternary_search(int arr[], int n, int target)
{
	int index = -1;
	int low = 0;
	int high = n - 1;
	int left_mid;
	int right_mid;

	while(low <= high)
	{
		left_mid = low + (high - low)/3;
		right_mid = high - (high - low)/3;

		if(arr[left_mid] == target)
		{
			index = left_mid;
			low = INT_MAX;
			high = INT_MIN;
		}
		else if(arr[right_mid] == target)
		{
			index = right_mid;
			low = INT_MAX;
			high = INT_MIN;
		}
		else if(arr[left_mid] > target)
		{
			high = left_mid - 1;
		}
		else if(arr[right_mid] < target)
		{
			low = right_mid + 1;
		}
		else
		{
			low = left_mid + 1;
			high = right_mid - 1;
		}
	}
	return index;
}
int main()
{
	int arr[] = {2,3,5,7,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 2;
	int index = ternary_search(arr,n,target);
	if(index == -1)
	{
		cout << target << " not in list";
	}
	else
	{
		cout << index << " is the index of " << target << endl;
	}
	return 0;
}
