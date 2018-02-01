//PROBLEM: GIven a N x N matrix of positive integers, find shortest path from the first cell of the matrix to its last cell that satisfies given constraints.
//
//EARLY NOTES: I'm not sure but I think the best approach is backtracking. At each node we have four possible moves. Many of those moves are going to go off the board and can be ignored. To keep track of the best solution I think I can create a function that will register each solution and keep the best one based on number of moves.
//
//PLANNING: Backtracking. Standard reject, accept, evolve, and recurse model. 
//
//FINAL NOTES:

#include <iostream>
#include <vector>
#define N 3
#define M 3
using namespace std;

//global vector that will be modified in the register function
vector<pair<int,int>> MASTER;
int BOARD[N][N] = {
	{1,1,1},
	{1,1,1},
	{1,1,1}
};
/*
int BOARD[N][N] = {
	{7,1,3,5,3,6,1,1,7,5},
	{2,3,6,1,1,6,6,6,1,2},
	{6,1,7,2,1,4,7,6,6,2},
	{6,6,7,1,3,3,5,1,3,4},
	{5,5,6,1,5,4,6,1,7,4},
	{3,5,5,2,7,5,3,4,3,6},
	{4,1,4,3,6,4,5,3,2,6},
	{4,4,1,7,4,3,3,1,4,2},
	{4,4,5,1,5,2,3,5,3,5},
	{3,6,3,5,2,2,6,4,2,1}
}; */
int SIZE = 10000;
void print_matrix(int matrix[N][M]);

void register_path(vector<pair<int,int>> path)
{
	//if master is empty or path has fewer moves then overwrite
	cout << "Found a solution\n";
	if(MASTER.size() == 0 || MASTER.size() > path.size())
	{
		MASTER = path; //copying vectors is super easy
		SIZE = MASTER.size();
	}
}

bool reject(vector<pair<int,int>> path,int row, int col)
{
	//if move is off the board reject
	if(row >= N || row < 0 || col >= N || col < 0)
	{
		return true;		
	}
	//if we've seen a shorter path reject
	if(path.size() + 1 > SIZE)
	{
		return true;
	}
	//if we've been to this location before reject
	bool test = false;
	for(int i = 0; i < path.size() && !test; i++)
	{
		if(path[i].first == row && path[i].second == col)
		{
			test = true;
		}
	}
	return test;

}
void bt(vector<pair<int,int>> path,int row, int col)
{
	if(reject(path,row,col))
	{
		return;
	}

	//if not reject, add new location	
	path.push_back(make_pair(row,col));

	//accept if we're at the end
	if(row == N && col == N)
	{
		register_path(path);
		return;
	}

	//grab the value of the current coordinates
	int value = BOARD[row][col];
	
	//move down a col
	bt(path,row+value,col);
	//move up a col
	bt(path,row-value,col);
	//move right in a row
	bt(path,row,col+value);
	//move left in a row
	bt(path,row,col-value);
}

int main()
{
	vector<pair<int,int>> path;
	bt(path,0,0);
	cout << "Shortest path length is " << MASTER.size() << endl;
	cout << "Shortest path is: ";
	for(int i = 0; i < MASTER.size(); i++)
	{
		cout << "(" << MASTER[i].first << "," << MASTER[i].second << ") ";	
	}
	cout << endl;
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
