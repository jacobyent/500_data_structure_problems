//PROBLEM: Given an binary array, sort it in linear time and constant space. Output should print contain all zeroes followed by all ones. 
//
//PLANNING: This is another problem I've seen before. The method I learned it to pass through the array and either count the zeroes or the ones. Then fill in the array from the beginning with n zeroes and the rest with ones. Or subtract the ones from the length of the array to get the number of zeroes. The first doesn't need the subtraction but the second you don't need an conditional
//
//FINAL NOTES: Their solution is about the same as the first one I mentioned. I'm pretty sure my method is marginally faster because I lack conditionals but this is a trivial problem anyways. Their partition solution is also very cool
#include <iostream>

using namespace std;

void count_ones(int arr[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	for(int i = 0; i < n - sum; i++)
	{
		arr[i] = 0;
	}
	for(int i = n - sum; i < n; i++)
	{
		arr[i] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[] = {1,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	count_ones(arr,n);
	return 0;
}
