//PROBLEM: Given a M x N matrix, calculate maximum sum submatrix of size k x k in a given M x N matrix in O(M*N) time. Here, 0 < k < M, N;
//
//EARLY NOTES: I've copied the previous problem over for this one. We can use both functions built last time. We'll preprocess the sums again and then input our square values into the sum function. We'll test all values and then output the submatrix that is greatest
//
//PLANNING: Test all possible square matrices using the functions from before, then output the answer.
//
//FINAL NOTES: Got a little tangled up in my loop logic but got it working. Very cool use of the previous problem.
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
int sum_out_put(int aux[N][M],int top, int left, int bottom, int right)
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
void find_max_sum(int mat[N][M],int aux[N][M], int k)
{
	//integer and array to keep track of the best array
	int max_sum = 0;
	int best[4];
	//temporary variable to store the result of sum_out_put
	int temp;
	//there are (N-k+1)^2 subarrays per k
	for(int i = 0; i < N-k+1; i++)
	{
		for(int j = 0; j < N-k+1; j++)
		{
			//sum for current sub
			temp = sum_out_put(aux,i,j,k + i - 1, k + j - 1);
			if(max_sum < temp)
			{
				//if sub sum is larger, replace values
				max_sum = temp;	
				best[0] = i;
				best[1] = j;
				best[2] = k + i - 1;
				best[3] = k + j - 1;
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
		{3,-4,6,-5,1},
		{1,-2,8,-4,-2},
		{3,-8,9,3,1},
		{-7,3,4,2,7},
		{-3,7,-5,7,-6}
	};
	int aux[N][M] = {0};
	int k = 3;
	preprocess(matrix,aux);
	find_max_sum(matrix,aux,k);
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
