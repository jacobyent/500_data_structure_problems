//PROBLEM: Given a circular sorted array of integers, search an element in it. Assume there are no duplicates in the array and the roation is in anti-clockwise direction.
//
//EARLY NOTES: This one actually seems more simple than the last one but I could be wrong.  
//
//MID NOTES: Took some time to really figure this one out. It seems to me the best way is to search for sorted sections using a midpoint. Then check if our search value is inclusivly in the search. If it is we narrow our serach to that area. If it isn't we exclude that area. 
//
//PLANNING: Check if mid point is equal to target. If yes return index. Else check if our lowest value is less than our midpoint. If it is check if target is within the search area. If yes set high to mid - 1. If no set low to mid + 1. If mid value is less than high (which is the opposite of the first quetsion) check if target is inclusively between high and mid. If yes move low to mid + 1. If not, move high to mid - 1.
//
//FINAL NOTES: Really spent a lot of time thinking on this one. I was able to finally figure it out. 

using namespace std;

#include <iostream>

int search_rotation(int arr[], int n, int T)
{
	int low = 0, high = n - 1;
	int mid;

	while(low <= high)
	{
		mid = (high + low)/2;

		//check if we're at the point
		if(arr[mid] == T)
		{
			return mid;
		}
		
		//check if low to mid is sorted
		if(arr[low] <= arr[mid])
		{
			//check if target is in the sorted section
			if(arr[low] <= T && arr[mid] > T)
			{
				high = mid - 1;	
			}
			else
			{
				low = mid + 1;
			}
		}
		
		else
		{
			//check if target is in the sorted section
			if(arr[mid] < T && arr[high] >= T)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;	
			}
		}
	}
	return -1;
}

int main()
{
	int arr[] = {8,9,10,2,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	int T = 11;
	int num = search_rotation(arr,n,T);
	if(num == -1)
	{
		cout << "Target not in array\n";
	}
	else
	{
		cout << "Element found at index " << num << endl;
	}
	return 0;
}
