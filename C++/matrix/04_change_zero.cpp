//PROBLEM: Given a M x N matrix consisting of only 0 or 1, change all elements of row i an dcolumn j to 0 if cell (i,j) has value 0. Do this without using any extra space for every (i,j) having value 0
//
//EARLY NOTES: I was pretty stumped for this one so I looked at techie's solution
//
//PLANNING: Pass through the first row. If we encounter a zero mark a bool value as true. Do the same with a seperate bool for the first col. Then, pass through the rest of the matrix. If we encounter a zero mark the corresponding elements in the first row and col as zero. Once finished, pass through the first row and for every zero mark the rest of its col with zeros. Do the same for the first col but with the rows. Finally check the row bool value. If it is true mark all elements in the first row as zero. Do the same for the first col
//
//FINAL NOTES: Very elegant solution from techie. Will try to come up with similar solutions in the future.

#include <iostream>
#define N 5
#define M 5
using namespace std;

void print_matrix(int matrix[N][M]);
void zeros_everywhere(int matrix[N][M])
{
	//bool values for frist row and col zeros
	bool row_zero = false;
	bool col_zero = false;
	//pass through first row looking for zeros
	for(int i = 0; i < M && !row_zero; i++)
	{
		if(!matrix[0][i])
		{
			row_zero = true;
		}
	}
	//pass through first col looking for zeros
	for(int i = 0; i < N && !col_zero; i++)
	{
		if(!matrix[i][0])
		{
			col_zero = true;
		}
	}
	//pass through rest of the matrix looking for zeros
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < M; j++)
		{
			if(!matrix[i][j])
			{
				//mark first row and col 
				matrix[0][j] = matrix[i][0] = 0;
			}
		}
	}
	//pass through changing cols as needed
	for(int i = 0; i < M; i++)
	{
		if(!matrix[0][i])
		{
			for(int j = 0; j < N; j++)
			{
				matrix[j][i] = 0;
			}
		}
	}
	//pass through changing rows as needed
	for(int i = 0; i < N; i++)
	{
		if(!matrix[i][0])
		{
			for(int j = 0; j < M; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	//change the first row to zeros if there was one there
	if(row_zero)
	{
		for(int i = 0; i < N; i++)
		{
			matrix[0][i] = 0;
		}
	}
	//change the first col to zeros if there was one there 
	if(col_zero)
	{
		for(int i = 0; i < M; i++)
		{
			matrix[i][0] = 0;
		}
	}
}

int main()
{
	int matrix[N][M] = {
		{1,1,0,1,1},
		{1,1,1,1,1},
		{1,1,1,0,1},
		{1,1,1,1,1},
		{0,1,1,1,1}
	};
	cout << "Before:\n";
	print_matrix(matrix);
	zeros_everywhere(matrix);
	cout << "After:\n";
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
