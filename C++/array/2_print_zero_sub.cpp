//PROBLEM: Given an array of integers, print all sub-arrays with 0 sum
//
//EARLY NOTES: This was a practice one for me where I took Techie's code and commented in where I learned new things. Specifically with this one I learned a lot about iterators and unordered maps
//

#include <iostream>
#include <unordered_map>

using namespace std;

void printallSubarrays(int arr[], int n)
{
	unordered_multimap<int, int> map; 
	//multimap v map: map is unique keys v multi has duplicates

	map.insert(pair<int,int>(0,-1));
	//pair is a type of tuple where it can be accesed with first, second

	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
		if(map.find(sum) != map.end())
		{
			auto it = map.find(sum);
			//auto detects the type of iterator needed automatically	
			while(it != map.end() && it->first == sum)
			//first will contain the summuation second will contain the index
			{
				cout << "Subarray [" << (it->second + 1) << ".." << i << "]\n";
				it++; 
				
			}
		}
		map.insert(pair<int,int>(sum,i));
	}
}

int main()
{
	int arr[] = {3,4,-7,3,1,3,1,-4,-2,-2};
	int n = sizeof(arr)/sizeof(arr[0]);

	printallSubarrays(arr,n);

	return 0;
}
