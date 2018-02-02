//PROBLEM: Given a M x N matrix which is row wise and column wise sorted, count number of negative elements present in it in linear time.
//
//EARLY NOTES: 
//
//PLANNING:
//
//FINAL NOTES:

#include <iostream>
#define N 5
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);

int main()
{
	int matrix[N][M] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
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
