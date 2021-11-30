//PROBLEM: Given an array of integers, in-place shuffle it. The algorithm should produce an unbiased permutation i.e. every permutation is equally likely.
//
//PLANNING: Single for loop with the counter initalized to n - 1, count down by 1, use rand() % i, swap arr[i] and arr[j]. 
//
//FINAL NOTES: Learned more about the rand and time libraries, solution meets requirments. 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fisher_yates(int arr[], int n)
{
	srand(time(NULL));
	int j;
	for(int i = n -1; i > 0; i--)
	{
		j = rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	fisher_yates(arr,n);

	return 0;
}
