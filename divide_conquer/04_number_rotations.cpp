//PROBLEM: Given a circularly sorted arrray of integers, find the number of times the array is rotated. Assume there are no duplicates in the array and the rotation is in anti-clockwise direction.
//
//EARLY NOTES: We're looking for the minimum element of the whole array. When we find that element the index will be the number of rotations. We can use a modified binary search.
//
//PLANNING: Check first and last. If first < last return first index. Else generate midpoint. Check midpoint for minimum. If yes return minimum, exit loop. If mid and first are sorted set low to mid + 1. If mid and high are sorted set high to mid - 1. Repeat loop until minimum is found or high is less than low. 
//
//FINAL NOTES: Had to get a lot of help with this one from techie. I came up with a scheme that was way over complicated that wouldn't actually work. When I realized that I checked their code.

using namespace std;

#include <iostream>
int find_rotation(int arr[], int n)
{
	int low = 0, high = n -1;
	
	int mid = (high + low)/2;
	int prev, next;
	while(low <= high)
	{
		if(arr[low] <= arr[high])
		{
			return low;
		}

		mid = (high + low)/2;
		
		//these mod n's only matter at the ends of the array
		//otherwise next and prev reduce to mid + 1 and mid -1 
		next = (mid + 1) % n;
		prev = (mid - 1 + n) % n;

		//check if mid is mimimum element
		if(arr[prev] >= arr[mid] && arr[next] >= arr[mid])
		{
			return mid;
		}	

		//check if low and mid are sorted
		else if(arr[low] <= arr[mid])
		{
			low = mid + 1;
		}

		//check if high and mid are sorted
		else if(arr[high] >= arr[mid])
		{
			high = mid - 1;
		}
	}

	//if we exit the loop the data was not sorted properly
	return -1;
}


int main()
{
	int arr[] = {6,9,10,1,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	int num = find_rotation(arr,n);

	if(num == -1)
	{
		cerr << "Error: Invalid input" << endl;
	}
	else
	{
		cout << "Number of rotations: " << num << endl;
	}
	return 0;
}
