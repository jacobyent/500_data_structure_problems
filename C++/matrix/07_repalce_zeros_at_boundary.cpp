//PROBLEM: Given a M X N binary matrix, replace all occurrences of 0 by 1 which are not completely surrounded by 1.
//
//EARLY NOTES: The wording in this problem was terrible. I looked farther into their solution to understand and what they want is any boundary zeros and neighboring zeros to be turned to one. This makes way more sense given their example io. 
//
//PLANNING: Traverse the edges of the graph. If we encounter a zero start a recursive depth-first search turning each zero into a 1 as it proceeds.
//
//FINAL NOTES: Nice problem to explore navigating a matrix and using recursion. Techie's solution is very similar to my own just moved around a bit
#include <iostream>
#define N 10
#define M 10
using namespace std;

void print_matrix(int matrix[N][M]);
void depth_replace(int matrix[N][M], int row, int col)
{
	//if we've jumped off the board return
	if(row >= N || row < 0 || col >= M || col < 0)
	{
		return;
	}	

	//if not a zero end recursion
	if(matrix[row][col])
	{
		return;
	}

	//if we pass the stop (ie we're at a zero) replace with 1
	matrix[row][col] = 1;

	//Move down a col
	depth_replace(matrix, row + 1, col);

	//Move up a col
	depth_replace(matrix, row - 1, col);

	//Move right in a row
	depth_replace(matrix, row, col + 1);

	//Move left in a row
	depth_replace(matrix, row, col - 1);
}
void replace_boundary_zeros(int matrix[N][M])
{
	//pass through first row
	for(int i = 0; i < M; i++)
	{
		if(!matrix[0][i])
		{
			depth_replace(matrix,0,i);
		}
	}
	//pass through last row
	for(int i = 0; i < M; i++)
	{
		if(!matrix[N-1][i])
		{
			depth_replace(matrix,N-1,i);
		}
	}
	//pass through first col
	for(int i = 1; i < N-1; i++)
	{
		if(!matrix[i][0])
		{
			depth_replace(matrix,i,0);
		}
	}
	//pass through last col
	for(int i = 1; i < N-1; i++)
	{
		if(!matrix[i][M-1])
		{
			depth_replace(matrix,i,M-1);
		}
	}
}

int main()
{
	int matrix[N][M] = {
		{1,1,1,1,0,0,1,1,0,1},
		{1,0,0,1,1,0,1,1,1,1},
		{1,0,0,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,1,1,0,1},
		{1,1,1,1,0,0,0,1,0,1},
		{1,1,0,1,1,0,1,1,0,0},
		{1,1,0,1,1,1,1,1,1,1},
		{1,1,0,1,1,0,0,1,0,1},
		{1,1,1,0,1,0,1,0,0,1},
		{1,1,1,0,1,1,1,1,1,1}
	};
	print_matrix(matrix);
	replace_boundary_zeros(matrix);
	cout << "\nNew matrix: \n";
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
