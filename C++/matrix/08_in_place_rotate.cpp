//PROBLEM: Given a square matrix, rotate matrix by 90 degress in clock-wise direction. The transformation should be done in place and in quadratic time.
//
//EARLY NOTES: Mapped out the moves by hand to find the pattern.
//
//PLANNING: Three swaps per quad that need to be moved. This an be accomplished in a for loop that iterates per edge. Every while loop we move the coordinates inwards and continue swapping until finished. We can use left, right, top, bottom variables to initalize the loop as well as to know when we're done with the while loop. 
//
//FINAL NOTES: My solution runs in roughly quadratic time I did some experiements and developed the math. The forumla for number of swaps is 3[n-1+n-3+...+0] which can be generalized to 3[sigma(1,n) n-i] - 3[sigma(1,n/2)n-2i] where n/2 is integer divison. Which is all to say it runs in quadratic time but it has fewer swap operations than techie's solution. Although there's is way faster to program correctly.

#include <iostream>
#define N 4

using namespace std;

void print_matrix(int matrix[N][N]);
void rotate_90(int matrix[N][N])
{
	int left = 0, right = N - 1;
	int top = 0, bottom = N - 1;
	int k = 0;
	while(left < right)
	{
		for(int i = left; i < right; i++)
		{
			swap(matrix[top][left+i],matrix[bottom-i][left]);
			swap(matrix[bottom-i][left],matrix[bottom][right-i]);
			swap(matrix[bottom][right-i],matrix[top+i][right]);
			cout << "Loop number: " << k++ << endl;
		}
		left++;
		right--;
		top++;
		bottom--;
	}
}
int main()
{
	int matrix[N][N] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	}; /*
	int matrix[N][N] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};*/
	print_matrix(matrix);
	rotate_90(matrix);
	cout << endl;
	print_matrix(matrix);
	return 0;
}

void print_matrix(int matrix[N][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
