//PROBLEM: Given a M x N matrix which is row wise and column wise sorted (with all strickly increasing elements in any row or column), report all occurrences of a given element in it in linear time.
//
//EARLY NOTES: I think we can use a similar traversal approach as the last problem.
//
//PROBLEM: Start at the bottom left element. If it is greater than our value move up a row. If it is the same output the value and move to the right. If it is less than move to the right. Stop when we've hit a boundary
//
//FINAL NOTES: As predicted the solution was pretty close to the last problem. Techie points out there are even faster techniques, will check out later.

#include <iostream>
#define N 4
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void number_search(int matrix[N][M],int search)
{
	int left = 0, bottom = N - 1;
	int count = 0;
	while(left < M && bottom > -1)
	{
		if(matrix[bottom][left] == search)
		{
			cout << "Element " << search << " found at position (";
			cout << bottom << ", " << left << ")\n";
			left++;
		}	
		else if(matrix[bottom][left] < search)
		{
			left++;
		}
		else
		{
			bottom--;
		}
	}
}

int main()
{
	int search = 3;
	int matrix[N][M] = {
		{-4,-3,-1,3,5},
		{-3,-2,2,4,6},
		{-1,1,3,5,8},
		{3,4,7,8,9}
	};
	print_matrix(matrix);
	number_search(matrix,search);
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
