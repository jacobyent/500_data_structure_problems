//PROBLEM: Given two sorted arrays X[] and Y[] of size m and n each, merge elements of X[] with elements of array Y[] by maintaining the sorted order. i.e. fill X[] with first m smallest elements and fill Y[] with remaining elements.
//
//EARLY NOTES: I think this can be done in n*m time and obviously in constant space
//
//PLANNNING: Compare an element X with the first element in Y. If X > Y swap. Then sort Y so they're in order again. This sort ensures the smallest element in Y will always be the first element. 
//
//FINAL NOTES: I've written merge sort algorithms before but I couldn't remember how to exactly perform in place merge. I looked up merge sort on wikipedia to get a reminder. Techie's solution is very similar but their sorting of the smaller array is more efficent. They take better advanatge of the sorted nature of the smaller array.

#include <iostream>

using namespace std;

void merge(int X[], int n, int Y[], int m)
{
	for(int i = 0; i < n; i++)
	{
		if(X[i] > Y[0])
		{
			swap(X[i], Y[0]);
			for(int j = 0; j < m - 1; j++)
			{
				if(Y[j] > Y[j+1])
				{
					swap(Y[j],Y[j+1]);
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < m; i++)
	{
		cout << Y[i] << " ";
	}
}

int main()
{
	int X[] = {1,4,7,8,10};
	int n = sizeof(X)/sizeof(X[0]);
	int Y[] = {2,3,9};
	int m = sizeof(Y)/sizeof(Y[0]);

	merge(X,n,Y,m);

	return 0;
}
