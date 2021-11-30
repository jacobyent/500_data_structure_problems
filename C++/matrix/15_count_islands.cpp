//PROBLEM: Given a binary matrix where 0 represents water and 1 represents land, count the number of islands in it. A island is formed by connected one's.
//
//EARLY NOTES: I think this can be done in quadratic time and constant space. Provided we don't need to preserve the matrix once we're done. 
//
//PLANNING: Pass through the matrix. If we encounter a 1 increment our island count and then trigger a bfs on that element. In the bfs mark the current element as the number islands + 1 and then spread to all neighboring elements. 
//
//FINAL NOTES: After reading techie's solution I realized I don't know the difference between bfs and dfs. At any rate techie's queue approach is almost certianly more time efficent than my recursive approach. I'm thinking it might be time to jump to queues and learn about them. Although my solution does work.

#include <iostream>
#define N 10
#define M 10
using namespace std;

//move arrays
const int row[] = {-1,-1,-1,0,0,1,1,1};
const int col[] = {-1,0,1,-1,1,-1,0,1};

void print_matrix(int matrix[N][M]);
void bfs(int mat[N][M], int r, int c, int count)
{
	//if we jump off the map return
	if(r < 0 || r >= N || c < 0 || c >= M)
	{
		return;
	}

	//if we are off the island or back at a previous element, return 
	if(mat[r][c] == 0 || mat[r][c] == count + 1)
	{
		return;
	}

	//set the current island to the current island number 
	mat[r][c] = count + 1;

	//the row and col arrays contain the 8 move combinations
	for(int i = 0; i < 8; i++)
	{
		bfs(mat, r + row[i],c + col[i],count);
	}

}
int count_islands(int mat[N][M])
{
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(mat[i][j] == 1)
			{
				count++;
				bfs(mat,i,j,count);
			}
		}
	}
	return count;
}
int main()
{
	int matrix[N][M] = {
		{1,0,1,0,0,0,1,1,1,1},
		{0,0,1,0,1,0,1,0,0,0},
		{1,1,1,1,0,0,1,0,0,0},
		{1,0,0,1,0,1,0,0,0,0},
		{1,1,1,1,0,0,0,1,1,1},
		{0,1,0,1,0,0,1,1,1,1},
		{0,0,0,0,0,1,1,1,0,0},
		{0,0,0,1,0,0,1,1,1,0},
		{1,0,1,0,1,0,0,1,0,0},
		{1,1,1,1,0,0,0,1,1,1}
	};
	int islands = count_islands(matrix);
	cout << "Number of islands: " << islands << endl;
	cout << "\nIslands marked: \n";
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
