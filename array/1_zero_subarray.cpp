//PROBLEM: Given an array, check if array contains sub-array having 0 sum;
//NOTE: This is another problem I know the solution to from reading ahead. 
//PLANNING: Sub-array here means a continous sequence not every permutation like I initally assumed. This makes our solution much easier to implement. We can simply add the values into a single integer checking each time if the integer equals a value it has been before. We can use a set here for fast add, and look up times.

#include <iostream>
#include <unordered_set>

using namespace std;

void zero(int arr[], int n)
{
	bool test = false;
	int sum = 0;
	unordered_set<int> set;
	set.insert(0); //need this for cases where the first subarray equals zero, or zero is in the subarray
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
		if(set.find(sum) != set.end())
		{
			cout << "Subarray with 0 sum exists" << endl;
			test = true;
		}
		set.insert(sum);
	}
	if(!test)
	{
		cout << "Subarray with 0 sum does not exist" << endl;
	}


}

int main()
{
	int arr[] = {3,4,-7,3,1,3,1,-4,-2,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	zero(arr,n);
	return 0;
}
