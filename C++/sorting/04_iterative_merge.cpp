//PROBLEM: Implement iterative merge sort
//
//EARLY NOTES: Instead of recursing to create our subarrays we can start by sorting each subarray then merging each pair as we go up
//FINAL NOTES: 

using namespace std;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

void merge(int arr[], int l, int m, int r)
{
	//function to merge two subarrays together
	int k = 0, i = l, j = m + 1;
	int aux[r-l];
	while(i <= m && j <= r)
	{
		if(arr[i] < arr[j])
		{
			aux[k++] = arr[i++];
		}
		else
		{
			aux[k++] = arr[j++];
		}
	}
	while(i <= m)
	{
		aux[k++] = arr[i++];
	}
	while(j <= r)
	{
		aux[k++] = arr[j++];
	}
	k = 0;
	for(int i = l; i <= r; i++)
	{
		arr[i] = aux[k++];
	}
}
void merge_sort(int arr[], int l, int r)
{
	//iterative approach to merge sort
	
	//create our sub array limits with the upper bound being half the array
	for(int m = 1; m < r - l; m = 2*m)
	{
		for(int i = l; i < r; i += 2*m)
		{
			int from = i;
			int mid = i + m - 1;
			//this min statment is needed so we don't access array
			//elements beyond our bounds
			int to = min(i + 2*m - 1,r);

			merge(arr,from,mid,to);
		}
	}
	
}
void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {8,5,9,1,2,3,10};
	int n = sizeof(arr)/sizeof(arr[0]);

	merge_sort(arr,0, n-1);
	print(arr,n);
	return 0;
}
