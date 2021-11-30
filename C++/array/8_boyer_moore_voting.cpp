//PROBLEM: Given an array of integers containing dupicate, return the majority element in an array if present. A majority element appears more  than n/2 times where n is the size of the array. 
//
//EARLY NOTES: Can probably be accomplished in linear time. Could sort the array but that would take nlog(n) time. I get the feeling this can be done in constant space as well. Counting sort type implementation would use n space. Maybe divide and conquer? 
//
//MID NOTES: I looked up the wikipedia page for this algorithm. The algorithm needs one pass to find the plurality candiate and needs another pass to determine if it is a majority. 
//
//PLANNING: Two for loops. The first contains an if statement with a counter and stores a single variable. If the counter is zero it grabs whatever integer is in the array at that location and increments the counter by one. If it's not zero and the current index matches the value in the variable then increment the counter. Else deincrement the counter. The final variable will be the plural canidate. A second pass is required to test if the plural canidate is the majority.

//FINAL NOTES: While writing the code I kept wondering how the algorithm would deal with an array where the majority candidate was spread out evenly along the whole of the array with no run of 2 or more. Of course if there is a majority candidate there has to be a run of 2 or more via the pigeonhole principle. Runs seem like a very important concept in arrays, I will try to keep them in mind in the future.

#include <iostream>

using namespace std;

void boyer_moore(int arr[], int n)
{
	int j = 0, x; //counter and candiate
	for(int i = 0; i < n; i++)
	{
		if(!j) //if counter is zero
		{
			x = arr[i];
			j++;
		}
		else if(x == arr[i])
		{
			j++;
		}
		else
		{
			j--;
		}
	}
	j = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == x)
		{
			j++;
		}
	}
	if(j > n/2)
	{
		cout << x << " is the majority element" << endl;
	}
	else 
	{
		cout << "No majority element" << endl;
	}
}

int main()
{
	int arr[] = {2,8,2,7,2,5,2,3,1,2,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	boyer_moore(arr,n);

	return 0;
}

