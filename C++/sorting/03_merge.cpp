//PROBLEM: Implement merge sort
//
//FINAL NOTES: 

using namespace std;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

void merge(int arr[], int l, int m, int r)
{
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
	if(l >= r)
	{
		return;
	}

	int m = (l+r)/2;
	merge_sort(arr,l,m);

	merge_sort(arr,m+1,r);

	merge(arr,l,m,r);
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
