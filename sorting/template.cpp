//PROBLEM:
//
//EARLY NOTES:
//
//PLANNING:
//
//FINAL NOTES: 

using namespace std;

#include <iostream>
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
	return 0;
}
