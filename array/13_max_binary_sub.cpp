//PROBLEM Given a binary array containing 0 and 1, find maximum length sub-array having equal number of 0 and 1
//
//EARLY NOTES: Very similar to last problem. Thinking of using a sum with a map to create a key value pair with the sum being the key and the index being the value. When the sum reaches the same value again we will have an even number of 1s and 0s. 
//PLANNING: One pair to keep track of our index and one length int to keep track of our longest run. One accumulator that adds 1 to it's value when it meets a 1 and subtracts one from its value when it reaches a 0. Each step we input a key value pair in a multimap. With the key being a sum and the value being the index. When we reach a sum we've seen before generate a length value from the last time we've seen it. If this value is greater than length we substitue the pair and update length
//
//FINAL NOTES: Solution is linear time and linear space. Techie's is very similar just with a map instead of a multimap
#include <iostream>
#include <utility>
#include <map>

using namespace std;

void equal(int arr[], int n)
{
	int sum = 0, length = 0, prev;
	pair<int,int> index;
	multimap<int,int> mymap;
	mymap.insert(pair<int,int>(0,-1));
	for(int i = 0; i < n; i++)
	{
		if(arr[i])
		{
			sum++;
		}
		else
		{
			sum--;
		}
		if(mymap.find(sum) != mymap.end())
		{
			prev = mymap.find(sum)->second;
			if(i - prev > length)
			{
				length = i - prev;
				index.first = prev;
				index.second = i;
			}
		}
		mymap.insert(pair<int,int>(sum,i));
	}
	if(!index.first)
	{
		index.first = 0;
	}
	if(length)
	{
		cout << length << endl;
		cout << "Largest subarray is {";
		for(int i = index.first + 1; i < index.second; i++)
		{
			cout << arr[i] << ", ";
		}
		cout << arr[index.second] << " }\n";
	}
}

int main()
{
	int arr[] = {0,0,1,0,1,0,1,0,1,0,1,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	equal(arr,n);
	return 0;
}
