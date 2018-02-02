//PROBLEM: Given a M x N matrix which is row wise and column wise sorted, count number of negative elements present in it in linear time.
//
//EARLY NOTES: Accidently looked up the solution elsewhere while trying to look up what row and col wise sorted meant 
//
//PLANNING: Start at the bottom left element. If the element is negative, add to count the remainder of the col. Then move to the right. If it is not negative move up one element and repeat.
//
//FINAL NOTES: Cool introduction to matrix sorting.

#include <iostream>
#define N 4
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void count_negative(int matrix[N][M])
{
	int left = 0, bottom = N - 1;
	int count = 0;
	while(left < M && bottom > -1)
	{
		if(matrix[bottom][left] < 0)
		{
			count += bottom + 1;
			left++;
		}	
		else
		{
			bottom--;
		}
	}
	cout << "Number of negative elements: " << count << endl;
}

int main()
{
	int matrix[N][M] = {
		{-7,-3,-1,3,5},
		{-3,-2,2,4,6},
		{-1,1,3,5,8},
		{3,4,7,8,9}
	};
	print_matrix(matrix);
	count_negative(matrix);
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
