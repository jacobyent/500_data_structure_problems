//PROBLEM: Implement bubble sort
//

using namespace std;

#include <iostream>
void bubble(int arr[], int n)
{
	bool swapped = true;
	int j = n;
	while(swapped)
	{
		swapped = false;
		for(int i = 1; i < j; i++)
		{
			if(arr[i] < arr[i-1])
			{
				swap(arr[i],arr[i-1]);
				swapped = true;
			}
		}
	}
}
void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[] = {3,5,8,4,1,9,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble(arr,n);
	print(arr,n);
	return 0;
}
