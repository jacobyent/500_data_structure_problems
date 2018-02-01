//PROBLEM: Given a M x N matrix, print all its diagonal elements ahving positive slope.
//
//EARLY NOTES: I'm a little confused by this problem. If one of the elements is zero or negative we don't print, correct? Also will all the elements in the diagonals always be the same number or different? I'm going to solve the problem in the way I interpret the problem
//
//PLANNING: Pass through first row checking all the left diagonal elements for positive slope. Then pass down the last col also checking the left diagonal elements. This solution should be m*n time and constant space
//
//FINAL NOTES: I'm still not sure what the question means but I did get the right io. Techie's solution doesn't check for any positive slopness. Unless they mean the postively sloped diagonals in the matrix. That's probably what they meant.

#include <iostream>
#define N 5
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void diagonal_slope(int matrix[N][M])
{
	//pass through first row
	for(int i = 0; i < M; i++)
	{
		if(matrix[0][i])
		{
			cout << matrix[0][i] << " ";
		}
		for(int j = 0; j < i; j++)
		{
			if(matrix[j][i-j])
			{
				cout << matrix[j][i-j] << " ";
			}
		}
		cout << endl;
	}
	//pass down last col
	for(int i = 1; i < N; i++)
	{
		if(matrix[i][M-1])
		{
			cout << matrix[i][M-1] << " ";
		}
		for(int j = 1; j < M-i; j++)
		{
			if(matrix[j+i][M-j])
			{
				cout << matrix[j+i][M-j-1] << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	int matrix[N][M] = {
		{1,2,3,4,5},
		{2,3,4,5,6},
		{3,4,5,6,7},
		{4,5,6,7,8},
		{5,6,7,8,9}
	};
	cout << "\nInput matrix:\n";
	print_matrix(matrix);
	cout << "\nPositive slopes:\n";
	diagonal_slope(matrix);
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
