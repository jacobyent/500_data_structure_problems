//PROBLEM: Given a MxN matrix, print matrix in spiral order
//
//EARLY NOTES: At first this seemed simple enough but now I'm not entirely sure. 
//
//PLANNING: I looked up techie's solution. I was taught to not do a while(1) and break conditions so I'm going to change the logic to avoid it.
//
//FINAL NOTES: I see the appeal of techie's solution now writing out the proper conditionals. However, I am glad I rewrote it this way to make sure I understood the problem and the logic within their solution
#include <iostream>
using namespace std;

#define N 5
#define M 5

void spiral(int matrix[N][M])
{
	bool go = true;
	int left = 0, right = N -1;
	int top = 0, bottom = M -1;
	while(go)
	{
		//-> row
		if(left > right)
		{
			go = false;
		}
		else if(go)
		{
			for(int i = left; i <= right; i++)
			{
				cout << matrix[top][i] << " ";
			}
			top++;
		}
		//|
		//V
		//col
		if(top > bottom)
		{
			go = false;	
		}
		else if(go)
		{
			for(int i = top; i <=bottom; i++)
			{
				cout << matrix[i][right] << " ";
			}
			right--;
		}
		//row <-
		if(left > right)
		{
			go = false;
		}else if(go)
		{
			for(int i = right; i >= left; i--)
			{
				cout << matrix[bottom][i] << " ";
			}
			bottom--;
		}
		// col
		// / \
		//  |
		if(top > bottom)
		{
			go = false;
		}else if(go)
		{
			for(int i = bottom; i >= top; i--)
			{
				cout << matrix[i][left] << " ";
			}
			left++;
		}
	}
}


int main()
{
	int matrix[N][M] = {
		{1,2,3,4,5},
		{16,17,18,19,6},
		{15,24,25,20,7},
		{14,23,22,21,8},
		{13,12,11,10,9}
	};
	spiral(matrix);
	return 0;
}
