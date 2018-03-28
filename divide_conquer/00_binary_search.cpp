//PROBLEM: Give a sorted array of integers find out if the target integer exists or not, if it does return its index
//

using namespace std;

#include <iostream>
#include <climits>
int binary_search(int arr[],int n, int target)
{
	int low = 0;
	int high = n - 1;
	int mid = n/2;
	int index = -1;

	while(low < high)
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
int main()
{
	int arr[] = {2,3,5,7,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 2;
	int index = binary_search(arr,n,target);
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
