//PROBLEM: Given an unsorted array of integers, find a pair with given sum in it. 
//NOTE: I've already looked at the solution for this problem so I know the best time complexity is to use hashing. My solution here is practicing implementing the solution.
//PLANNING: Create a map to store the values in the array using the integers as keys and their values as their positin within the array. With every new integer check if its difference with the given sum exisits in the map. If it does exist output the position values to the user.   
#include <iostream>
#include <unordered_map>

using namespace std;
void findPair(int arr[], int n, int sum)
{
	bool test = false;
	unordered_map<int,int> map;
	for(int i = 0; i < n; i++)
	{
		if(map.find(sum - arr[i]) != map.end())
		{
			cout << "Pair found at index " << map[sum - arr[i]] << " and " << i << endl;
			test = true;
			//I was taught not to break for loops and also this program doesn't find all pairs, only one of them. I changed the logic a tiny bit from the provided code.
		}
		map[arr[i]] = i;
	}
	if(!test)
	{
	cout << "Pair not found";
	}
}
int main()
{
	int arr[] = {8,7,2,5,3,1};
	int sum = 10;

	int n = sizeof(arr)/sizeof(arr[0]);

	findPair(arr, n, sum);

	return 0;
}
