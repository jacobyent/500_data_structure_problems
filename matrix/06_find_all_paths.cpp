//PROBLEM: Given a Mx N matrix, find all paths from first cell to last cell. We can only move down or to the right from the current cell.
//
//EARLY NOTES: This seems like an easier problem than the find the shortest path problem. I'm guessing most of these problems aren't sorted by difficulty
//
//PLANNING: I believe there is some kind of queue implementation to solve this problem but I don't know how to do that. Instead I will use a recursive approach to explore all possible leafs on this search tree.
//
//FINAL NOTES: Simple enough but my original solution I was merely passing in an array by value. After reading techie's solution I realized that I haven't been using an array pointer but just an array in a number of my solutions. I changed this solution to a pointer to an array to save a significant amount of space that I didn't need to use. 

#include <iostream>
#define N 3
#define M 3
#define n 5
using namespace std;

const int MATRIX[N][M] = {
	{1,2,3},
	{4,5,6},
	{7,8,9}
};

void print_matrix();
void out_put_path(int *path)
{
	for(int i = 0; i < n - 1; i++)
	{
		cout << path[i] << " - ";
	}
	cout << path[n-1] << endl;
}
void recursive_path(int *path,int row, int col,int move)
{
	if(move >= n || row >= M || col >= N)
	{
		return;	
	}
	path[move] = MATRIX[row][col];
	if(row == M - 1 && col == N - 1)
	{
		out_put_path(path);
		return;
	}
	recursive_path(path,row+1,col,move+1);
	recursive_path(path,row,col+1,move+1);
}

int main()
{
	cout << "\nMatrix input:\n";
	print_matrix();
	cout << endl;
	int *path;
	path = new int[n];
	recursive_path(path,0,0,0);
	delete path;
	return 0;
}

void print_matrix()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << MATRIX[i][j] << " ";
		}
		cout << endl;
	}
}
