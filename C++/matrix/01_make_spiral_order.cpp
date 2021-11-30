//PROBLEM: Given a MxN matrix, print matrix in spiral order
//
//EARLY NOTES: Should be similar to the last problem but in reverse
//
//PLANNING: Build a while loop that loops over a few for loops.
//
//FINAL NOTES: Having a single break condition (k < count) made the conditionals very nice for this problem. Techie's solution included input as an actual array instead of a simple count. They also keep the same break conditions they had for their print solution.

#include <iostream>
#define N 5
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void build_spiral(int matrix[N][M])
{
	//build a ceiling value for k to work up to
	int count = N*M + 1;
	int k = 1;
	//values used for navigating in a spiral
	int top = 0, bottom = M-1;
	int left = 0, right = N-1;
	//the end of the loop will be when k < count
	while(k < count)
	{
		//left to right  in a row
		for(int i = left; i <= right && k < count; i++)
		{
			matrix[top][i] = k;
			k++;
		}
		top++; //move top up one row
		//top to down in a col
		for(int i = top; i <=bottom && k < count; i++)
		{
			matrix[i][right] = k;
			k++;
		}
		right--; //move right back a col
		//right to left down a row
		for(int i = right; i >= left && k < count; i--)
		{
			matrix[bottom][i] = k;
			k++;
		}
		bottom--; // move bottom up one row
		//bottom up in a col
		for(int i = bottom; i >= top && k < count; i--)
		{
			matrix[i][left] = k;
			k++;
		}
		left++; //move the left col over one
	}
}

int main()
{
	int matrix[N][M];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			matrix[i][j] = 0;
		}
	}
	build_spiral(matrix);
	print_matrix(matrix);
	return 0;
}

void print_matrix(int matrix[N][M])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
