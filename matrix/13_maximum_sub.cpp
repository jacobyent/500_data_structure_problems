//PLANNING: Given a M x M matrix, find maximum sum submatrix present in it
//
//EARLY NOTES: We can build off our code from the previous problem. This time though we need to test every possible subarray. I believe this will take n4 time
//
//PLANNING: Use 4 location markers: top, left, bottom, right and loop through every possible combination. 
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
int sub_sum(int aux[N][M],int top, int left, int bottom, int right)
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
	return sum;
}
void find_max_sub(int mat[N][M],int aux[N][M])
{
	//integer and array to keep track of the best array
	int max_sum = 0;
	int best[4];

	//temporary variable to store the result of sum_out_put
	int temp;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = i; k < N; k++)
			{
				for(int l = j; l < N; l++)
				{
					temp = sub_sum(aux,i,j,k,l);
					if(max_sum < temp)
					{
						max_sum = temp;
						best[0] = i;
						best[1] = j;
						best[2] = k;
						best[3] = l;
					}
				}
			}
		}
	}	
	//output
	cout << "Max sum found: " << max_sum << endl;
	for(int i = best[0]; i < best[2] + 1; i++)
	{
		cout << "[ ";
		for(int j = best[1]; j < best[3] + 1; j++)
		{
			cout << mat[i][j] << " ";
		}	
		cout << " ]\n";
	}
}

int main()
{
	int matrix[N][M] = {
		{-5,-5,3,1,0},
		{9,7,8,3,7},
		{-6,-2,-1,2,-4},
		{-7,5,5,2,-6},
		{3,2,-9,-5,1}
	};
	int aux[N][M] = {0};
	preprocess(matrix,aux);
	find_max_sub(matrix,aux);
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
