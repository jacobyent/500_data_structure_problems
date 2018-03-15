//PROBLEM: Implement iterative quick sort
//
//EARLY NOTES: To not use recursion we will use a stack. This stack will contain our location pointers for each partition.
//
//FINAL NOTES: Pretty cool to use a stack. I'm always a fan of not using recursion when possible

using namespace std;

#include <iostream>
#include <stack>
#include <utility>
void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
int partition(int arr[], int left, int right)
{
	//select our pivot
	int pivot = arr[right];
	int loc;

	//create our subarrays
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
		arr[i + loc + 1] = greater[i];
	}
	
	//return the pivot location
	return loc;
}
void quick_sort(int arr[], int n)
{
	//stack based implementation for quicksort
	stack<pair<int,int>> stk;
	int start = 0;
	int end = n - 1;
	int pivot;

	stk.push(make_pair(start,end));

	while(!stk.empty())
	{
		//grab our current partition values and pop
		start = stk.top().first;
		end = stk.top().second;
		stk.pop();

		//start our parition
		pivot = partition(arr,start,end);

		//create our new partition values
		if(pivot  - 1 > start)
		{
			stk.push(make_pair(start,pivot - 1));
		}
		if(pivot + 1 < end)
		{
			stk.push(make_pair(pivot + 1, end));
		}
	}
}
int main()
{
	int arr[] = {3,5,8,4,1,9,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,n);
	print(arr,n);
	return 0;
}
