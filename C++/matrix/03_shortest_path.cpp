//PROBLEM: GIven a N x N matrix of positive integers, find shortest path from the first cell of the matrix to its last cell that satisfies given constraints.
//
//EARLY NOTES: I'm not sure but I think the best approach is backtracking. At each node we have four possible moves. Many of those moves are going to go off the board and can be ignored. To keep track of the best solution I think I can create a function that will register each solution and keep the best one based on number of moves.
//
//PLANNING: Backtracking. Standard reject, accept, evolve, and recurse model. 
//
//FINAL NOTES: I used a vector to great success. Neither of techie's solutions are very satisfying to me. Their use of space in the first one is way overboard and their second solution is more lean but it doesn't store their path.

#include <iostream>
#include <vector>
#define N 10
#define M 10
using namespace std;

//global vector that will be modified in the register function
vector<pair<int,int>> MASTER;
//we never modifiy this board so it can be a global constant
const int BOARD[N][N] = {
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
};
//start off with SIZE being something very large
int SIZE = 100;

//function to keep track of the shortest path and update SIZE
void register_path(vector<pair<int,int>> path)
{
	//if master is empty or path has fewer moves then overwrite
	if(MASTER.size() == 0 || MASTER.size() > path.size())
	{
		MASTER = path; //copying vectors is super easy
		SIZE = MASTER.size();
	}
}
//function to check for all the stop conditions 
bool reject(vector<pair<int,int>> path,int row, int col)
{
	//if move is off the board reject
	if(row >= N || row < 0 || col >= N || col < 0)
	{
		return true;		
	}
	//if we've seen a shorter path reject
	if(path.size() >= SIZE)
	{
		//the execution time without this check is terrible
		return true;
	}
	//special case where we immediately return to the origin after the first move
	if(row == 0 && col == 0 && path.size() > 1)
	{
		return true;
	}
	//if we've been to this location before reject
	bool test = false;
	for(int i = 0; i < path.size() - 1 && !test; i++)
	{
		if(path[i].first == row && path[i].second == col)
		{
			test = true;
		}
	}
	return test;

}
//backtracking function
void bt(vector<pair<int,int>> path,int row, int col)
{
	//add new location
	path.push_back(make_pair(row,col));
	//check if location is valid
	if(reject(path,row,col))
	{
		//remove the bad move
		path.pop_back();
		return;
	}

	//accept if we're at the end
	if(row == N -1 && col == N-1)
	{
		register_path(path);
		//remove the ending move
		path.pop_back();
		return;
	}

	//grab the value of the current coordinates
	int value = BOARD[row][col];

	//move down a col
	bt(path,row+value,col);

	//move right in a row
	bt(path,row,col+value);

	//move up a col
	bt(path,row-value,col);

	//move left in a row
	bt(path,row,col-value);
}

int main()
{
	//vector to store the path we take 
	vector<pair<int,int>> path;
	bt(path,0,0);
	cout << "Shortest path length is " << MASTER.size() - 1 << endl;
	cout << "Shortest path is: ";
	for(int i = 0; i < MASTER.size(); i++)
	{
		cout << "(" << MASTER[i].first << "," << MASTER[i].second << ") ";	
	}
	cout << endl;
	return 0;
}

