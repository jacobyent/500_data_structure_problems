//PROBLEM: Given an array containing only 0's, 1's, and 2's, sort the array in linear time and using constant space.
//
//PLANNING: I think I can use the same logic as the binary sort problem. I will have 2 variables, the first to count the number of 0's and the second to count the number of 1's. Then I will fill the array with 0's until reaching their sum, start from there and fill with ones, and then the rest of the array will be 2's. 
//EARLY NOTES: I imagine they will use my plan for their first and maybe a clever partition problem. 
//
//FINAL NOTES: Had to remember to add zero and one count together to get the right index. Looking at techie's solution they used a pivot. My solution implicitlyused pigeon hole principle but in practice is very similar to their's. 
#include <iostream>

using namespace std;

int count_twos(int arr[], int n)
{
	int zero = 0, one = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == 0)
		{
			zero++;
		}
		else if(arr[i] == 1)
		{
			one++;
		}
	}
	for(int i = 0; i < zero; i++)
	{
		arr[i] = 0;
	}
	for(int i = zero; i < one + zero; i++)
	{
		arr[i] = 1;
	}
	for(int i = one + zero; i < n; i++)
	{
		arr[i] = 2;
	}
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {1,2,0,1,2,2,2,1,0,1,1,0,0,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	count_twos(arr,n);

	return 0;
}
	
