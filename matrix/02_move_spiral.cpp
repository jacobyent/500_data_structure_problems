//PROBLEM: Given a MxN matrix, shift all its elements by 1 in spiral order.
//
//EARLY NOTES: I believe we can pass through the matrix as before but store each element in an extra integer and swap it.
//
//PLANNING: Traverse through the matrix as before but store an extra int that will be swapped at each index. Once finished do one final swap on the original element
//
//FINAL NOTES: Techie's solution is identical to mine and I'm quite proud of that fact.

#include <iostream>
#define N 5
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void shift_spiral(int matrix[N][M])
{
	int max_count = N*M;
	int count = 0;
	int top = 0, bottom = M-1;
	int left = 0, right = N-1;
	int storage = 0;
	while(count < max_count)
	{
		//left to right  in a row
		for(int i = left; i <= right && count < max_count; i++)
		{
			swap(matrix[top][i],storage);
			count++;
		}
		top++; //move top up one row
		//top to down in a col
		for(int i = top; i <=bottom && count < max_count; i++)
		{
			swap(matrix[i][right],storage);
			count++;
		}
		right--; //move right back a col
		//right to left down a row
		for(int i = right; i >= left && count < max_count; i--)
		{
			swap(matrix[bottom][i],storage);
			count++;
		}
		bottom--; // move bottom up one row
		//bottom up in a col
		for(int i = bottom; i >= top && count < max_count; i--)
		{
			swap(matrix[i][left],storage);
			count++;
		}
		left++; //move the left col over one
	}
	swap(matrix[0][0],storage);
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
	shift_spiral(matrix);
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
