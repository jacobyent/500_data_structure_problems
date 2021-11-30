//PROBLEM: Given a chess board, print all sequences of moves a knight on a chessboard such that the knight visits every square only once.
//
//PLANNING: Will use backtracking method. Will use a NxN array to store move numbers and a set to keep track of moves. Will get N from user. Will also get starting position from user. Starting position will be any valid tile from 0 to N^2-1. Reject: If move goes off the board, and if the move goes into a tile that has already been visited. Accept: if this is move N^2-1. Evolving the board: select a possible move from the array.
//
//EARLY NOTES: I thought about this one for about a day before tackaling. I looked up the number of possible answers for an 8x8 board and decided to set a hard limit of 8 on the size allowed form user input
//
//FINAL NOTES: This took longer than I thought it would. I learned how to properly make and pass 2D arrays in functions. My inital plan was too complicated and I deviated a lot from it. I did get caught in a few dead ends and eventually checked techie's code. I borrowed a few things form them but they didn't actually sovle the problems I was having. Most of the problems were simple mistakes either in syntax or logic. I didn't approach this problem with test driven development in mind, in future problems I will. 
#include <iostream>

using namespace std;

#define N 5

const int pos_0[] = {-2,-2,-1,-1,1,1,2,2};
const int pos_1[] = {-1,1,-2,2,-2,2,-1,1};
int solution_number = 0;

void bt(int arr[][N],int row, int col, int count);

bool reject(int arr[][N], int row, int col);
void print_board(int arr[][N]);

int main()
{
	int arr[N][N];
	int count = 0;
	int start;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}
	cout << "Select starting position between 0 and " << N*N - 1 << ": ";
	cin >> start;
	bt(arr, start/N, start%N, count);	
	return 0;
}

void bt(int arr[][N],int row, int col, int count)
{
	arr[row][col] = ++count;
	if(count < N*N)
	{
		for(int i = 0; i < 8; i++)
		{
			row += pos_0[i];
			col += pos_1[i];
			if(reject(arr, row, col))
			{	
				bt(arr, row, col, count);
			}
			row -= pos_0[i];
			col -= pos_1[i];
		}
		arr[row][col] = 0;
	}
	else
	{
		cout << solution_number << endl;
		solution_number++;
		print_board(arr);
		arr[row][col] = 0;
	}
}
bool reject(int arr[][N], int row, int col)
{
	if(row < 0 || col < 0 || row >= N || col >= N)
	{
		return false;
	}
	else if(arr[row][col])
	{
		return false;
	}
	return true;
}

void print_board(int arr[][N])
{
	cout << endl;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

