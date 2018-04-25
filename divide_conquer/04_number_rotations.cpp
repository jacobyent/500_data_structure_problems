//PROBLEM: Given a circularly sorted arrray of integers, find the number of times the array is rotated. Assume there are no duplicates in the array and the rotation is in anti-clockwise direction.
//
//EARLY NOTES: We can adept binary search to consider rotations. What we are looking for is the minimum element. The index of this element will be the number of rotations. We can narrow our search space each iteration by checking the low and high point. If the low point is the smallest element then that is our rotation point. If not, find the midpoint. Compare the midpoint against its neighbors. If its less both its neighbors than that is our rotation point. If it is only greater than the left neighbor our new 
//
//FINAL NOTES: 

using namespace std;

#include <iostream>

int main()
{
	return 0;
}
