//PROBLEM: Given a M x N matrix and two coordinates (p,q) and (r,s) which represents top-left and bottom-right coordinates of a sub-matrix of the given matrix calculate the sum of all elements present in the sub-matrix in O(1) time.
//
//EARLY NOTES: I have no idea how to do this in constant time. The matrix isn't sorted and I don't see how we could add together a row in O(1) time let alone a sub-matrix.
//
//MID NOTES: Looked up techie's explanation. The problem I had was thinking that the whole application would have to run in constant. Of course if we preprocess everything the summation function will run in constant time. 
//
//PLANNING: Create another matrix where we will store the sums of the sub-matricies. Later we will grab from this matrix to get our sums.
//
//FINAL NOTES: Solution works like a charm. Changing main to get the coordinates from the user would demonstrate how useful this approach is rather than directly calculating the summation each time.

#include <iostream>
#define N 5
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void preprocess(int matrix[N][M], int aux[N][M])
{
	//initalize the origin
	aux[0][0] = matrix[0][0];
	
	//sum the first row	
	for(int i = 1; i < M; i++)
	{
		aux[0][i] = matrix[0][i] + aux[0][i-1];
	}

	//sum the first col
	for(int i = 1; i < N; i++)
	{
		aux[i][0] = matrix[i][0] + aux[i-1][0];
	}
	
	//sum the rest
	for(int i = 1; i < N; i++)
	{
		
		for(int j = 1; j < M; j++)
		{
			aux[i][j] = matrix[i][j] + aux[i-1][j] + aux[i][j-1] - aux[i-1][j-1];
		}
	}
}
void sum_out_put(int aux[N][M],int top, int left, int bottom, int right)
{
	int sum = aux[bottom][right];
	if(left - 1 >= 0)
	{
		sum -= aux[bottom][left - 1];
	}
	if(top - 1 >= 0)
	{
		sum -= aux[top - 1][right];
	}
	if(top - 1 >= 0 && left - 1 >= 0)
	{
		sum += aux[top-1][left-1];
	}
	cout << "Sub-matrix sum is: " << sum << endl;
}

int main()
{
	int matrix[N][M] = {
		{0,2,5,4,1},
		{4,8,2,3,7},
		{6,3,4,6,2},
		{7,3,1,8,3},
		{1,5,7,9,4}
	};
	int aux[N][M] = {0};
	int top = 1;
	int left = 1;
	int bottom = 3;
	int right = 3;
	preprocess(matrix,aux);
	sum_out_put(aux,top,left,bottom,right);
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
