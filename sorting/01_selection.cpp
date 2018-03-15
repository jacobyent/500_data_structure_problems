//PROBLEM: Implement selction sort
//
//PLANNING: Two for loops, pass through the remaining unsorted array, find the smallest element and then swap that element into place.
//
//FINAL NOTES: 

using namespace std;

#include <iostream>

void selection(int arr[], int n)
{
	int min;

	for(int i = 0; i < n - 1; i++)
	{
		min = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(arr[i],arr[min]);
	}

}
int main()
{
	int arr[] = {3,5,8,4,1,9,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	selection(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
