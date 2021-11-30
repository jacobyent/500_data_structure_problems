//PROBLEM: Create insertion sort 
//
//FINAL NOTES: It seems I was taught that gnome sort and insertion sort were the same algorithm. They are minorally different but I think it is useful to know there difference. Also I wrote bubble sort, selection sort, and gnome sort before just looking up techie's implmentation. I thought I knew insertion sort by heart but I guess I didn't.

using namespace std;

#include <iostream>
void insertion(int arr[], int n)
{
	int value;
	int j;
	for(int i = 1; i < n; i++)
	{
		value = arr[i];
		j = i;

		while(j > 0 && arr[j-1] > value)
		{
			arr[j] = arr[j-1];
			j--;
		}

		arr[j] = value;
	}
}
int main()
{
	int arr[] = {3,5,8,4,1,9,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertion(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
