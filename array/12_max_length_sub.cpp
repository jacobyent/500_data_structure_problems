//PROBLEM: Given an array of integers, find maximum length sub-array having given sum.
//
//Sum = 0: 5, 11, 6, 11, 14, 19, 22, 20, 20
//Sum + 8; 13, 19, 14, 19, 22, 27, 30, 28, 28
//Map = {13:0}, {19:1}, {14:2}, {19:3}, {22:4}!, {27:5}!, {30:6}!,{28,7},{28,8}
//EARLY NOTES: Seems very similar to the find the zero problem just with a few modifications. I think it can be done in linear time with the use of a multimap where the keys are a sum and the values are the index location. 
//
//PLANNING: Initalize a pair, and length value set to 0. Initalize an ordered multimap with value {8,-1}. Then create sum with value 0. Add the first element to the sum. Ask the map if it's seen this sum before, if it has take the current index and subtract it from the value in the map. Compare with the length value, if our new value is greater update length to this value and change our pair to the current index and the value in sum. Finally either way add the current sum + 8 as a key with the value being the current index to the map. Then the value in pair will contain the indecie of the longest array and the length of it.
//
//FINAL NOTES: Got it working. Looking at techie's solution they also used a map and their solution is slightly less complicated. Overall though both solutions run in linear time and require n extra space
#include <iostream>
#include <utility>
#include <map>

using namespace std;

void max_sub(int arr[],int n, int k)
{
	multimap<int, int> mymap;
	pair<int,int> index;
	int length = 0, sum = 0, test;
	mymap.insert(pair<int,int>(k,-1));
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
		if(mymap.find(sum) != mymap.end())
		{
			test = mymap.find(sum)->second;
			if(i - test > length)
			{
				length = i - test;
				index.first = test;
				index.second = i;
			}
		}
		mymap.insert(pair<int,int>(sum + k, i));
	}
	if(length > 0)
	{
		cout << "The longest subarray is { ";
		for(int i = index.first + 1; i < index.second; i++)
		{
			cout << arr[i] << ", ";
		}
		cout << arr[index.second] << " } having length " << length << endl; 
	}
	else
	{
		cout << "Sub-arrray doesn't exist\n";
	}
}

int main()
{
	int arr[] = {5,6,-5,5,3,5,3,-2,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 8;
	max_sub(arr,n,k);
	return 0;
}
