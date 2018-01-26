//PROBLEM: Given tow sorted arrays X[] and Y[] of size m and n each where m >= n and X[] has exactly n vacant cells, merge elements of Y[] in their correct position in array X[] i.e. merge (X,Y) by keeping the sorted order.
//
//EARLY NOTES: Very similar to the last problem. This time instead of sorting the smaller array after every swap sort the larger array.
//
//PLANNING: Move all zeros to the front of X. Swap the first not vacant cell in X with the first non vacant cell in Y. Compare the new element with the next non vacant cell in X. Whatever element is smaller that goes in the first non vacant spot. If the new element isn't the smallest sort it into the back of X.
//
//FINAL NOTES: I cobbled together my solution from previous problems. I believe the worse case scinerio it runs in nm time and best case is n time. Techie's solution runs in n + m time with I believe a best case solution of n. It took a bit to understand their compact code but now that I see how it works. I'll keep this solution in mind in the future for merges
#include <iostream>

using namespace std;

void merge_con(int X[], int m, int Y[], int n)
{
	int k = m-1;
	int t, temp;
	//move zeros to front
	for(int i = m-1; i > 0; i--)
	{
		if(X[i]) //if X[i] is non zero swap with the first zero element avaliable
		{
			swap(X[i], X[k]);
			k--;
		}
	}
	for(int i = 0; i < n; i++)
	{
		swap(X[i], Y[i]); //move next Y element into X
		if(X[i] > X[n]) //if new element is larger than swap with next smallest and sort
		{
			temp = X[i];
			swap(X[i], X[n]); //new smallest element
			for(t = n + 1; t < m && temp > X[t]; t++)
			{
				X[t -1] = X[t];
			}
			X[t-1] = temp;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
}

int main()
{
	int X[] = {0,2,0,3,0,5,6,0,0};
	int m = sizeof(X)/sizeof(X[0]);
	int Y[] = {1,8,9,10,15};
	int n = sizeof(Y)/sizeof(Y[0]);

	merge_con(X,m,Y,n);
	return 0;

}
