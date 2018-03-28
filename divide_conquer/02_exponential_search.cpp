//PROBLEM: Implement exponential search
//
//EARLY NOTES: Will modify my binary search function from eariler. 

using namespace std;

#include <iostream>
#include <climits>
int binary_search(int arr[],int start, int end, int target)
{
	int low = start;
	int high = end;
	int mid;
	int index = -1;

	while(low <= high)
	{
		mid = high - (high - low)/2;
		if(arr[mid] == target)
		{
			index = mid;
			low = INT_MAX;
			high = INT_MIN;
		}
		else if(arr[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return index;
}
int exponential_search(int arr[],int n, int target)
{
	//note: for exponential search n is the upper bound of our search
	int search = 1;

	while(arr[search] < target && search <= n)
	{
		search = 2*search;
	}
	if(arr[search] == target)
	{
		return search;
	}
	else if(search >= n)
	{
		return -1;
	}
	return binary_search(arr,search/2,search,target);
}
int main()
{
	int arr[] = {2,3,5,7,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 2;
	int index = exponential_search(arr,n,target);
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
