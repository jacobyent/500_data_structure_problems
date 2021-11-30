//PROBLEM: Implement Hoare's partition scheme for quicksort
//
//EARLY NOTES: Two pointers that move towards one another. When they find values inverted - that is the left one is greater than the pivot and the right is less than - they swap the values. Repeat until the pointers meet
//
//FINAL NOTES: I initially wrote the partition scheme not accounting for duplicate values. In other words I used normal while loops for the left and right indecies. These wouldn't work with duplicate elements because the pointers would never advance but the loop would also not exit because the pointers were not overlapping. Changing the inital pointers to left - 1 and right + 1 and implementing a do while loop fixes this issue.
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
int hoare_partition(int arr[], int left, int right)
{
	//hoare's partition scheme
	
	//grab our pivot
	int pivot = arr[left];

	//our index for our two pointers
	int i = left - 1;
	int j = right + 1;
	
	//run the swaps until the pointers meet
	while(i < j)
	{	
		//run the left until it finds a value greater than the pivot
		do
		{
			i++;
		}while(arr[i] < pivot);

		//run the right until it finds a value less than the pivot
		do
		{
			j--;
		}while(arr[j] > pivot);

		//only swap if both pointers have found a valid canidate
		if(i < j)
		{
			swap(arr[i],arr[j]);
		}
	}
	return j;
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
		pivot = hoare_partition(arr,start,end);

		//create our new partition values
		if(pivot  > start)
		{
			stk.push(make_pair(start,pivot));
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
