//PROBLEM: Create gnome sort
//
//FINAL NOTES: In the process of creating insertion sort I realized I created gnmoe sort. So I saved this code and moved it to it's own file

using namespace std;

#include <iostream>

void gnome_sort(int arr[],int n)
{
	//gnome sort for a fixed array
	
	for(int i = 1; i < n; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(arr[j] < arr[j-1])
			{
				swap(arr[j],arr[j-1]);
			}
			else
			{
				break;
			}
		}
	}
}
int main()
{
	int arr[] = {3,8,5,4,1,9,-2};
	//int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	gnome_sort(arr,n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
