//PROBLEM: The N queens pule is the problem of placing N chess queens on an N x N chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

//EARLY NOTES: I've never done a problem like this before so I spent some time looking up back ground information about backtracking. I have not looked up the specific solution to this problem yet.

//PLANNING: I will represent each location using a struct I will call tile. Tile will hold four values: row, column, left diagonal, right diagonal. Row and column will have the values 0 to n - 1 and each diagonal will number from 0 to 2n - 1. The diagonals will be calculated once the row and column numbers are known. I know I'm supposed to use a tree type strucutre to iterate through all possible combinations and prune leafs that will not work. Each leaf will be one row down since the queens can't be in the same rows. From here I'll have to figure out certian specifics, I'll document those during my code and in my final thoughts.

//FINAL NOTES: I was able to finish the problem without looking up the solution. Once I worked through the logic the problem didn't seem nearly as difficult. I did get lost in the weeds here and there. Looking at Techie's solution they reserve N2 space in memory for their matrix. My solution used N space. In addition I believe the time complexity is comparable. My code is a bit more complicated but it uses less resources. Although I could probably clean up sections.
#include <iostream>
#include <set>
using namespace std;

struct tile 
{
	int row, col; //calculating the diagonals can be a seperate funtion
};
void print_line(int n, int row);

//I am following the basic backtracking strucutre form wikipedia
void bt(tile pos[], int n, int row);
bool reject(tile pos[], int n, int row);
bool accept(tile pos[], int n, int row); 

int main()
{
	int n;
	cout << "What is the value of N?: ";
	cin >> n;
	tile * pos = new tile[n];
	//row values will not need to be changed so intialize them now
	for(int i = 0; i < n; i++)
	{
		pos[i].row = i;
	}
	bt(pos, n, 0);

	return 0;
}
void print_line(int n, int col)
{
	//outputs the queens position to the user
	for(int i = 0; i < n; i++)
	{
		if(i == col)
		{
			cout << "N";
		}
		else
		{
			cout << ".";
		}
	}
	cout << endl;
}
void bt(tile pos[], int n, int row)
{
	//Reject will prune leafs that fail conditions outright (such as same column values)
	if(row > 1 && reject(pos, n, row)) //We don't need to check until the 2nd queen is palced
	{
		return;
	}
	//accept returns true if there is a solution and it handles the output internally.
	if(!accept(pos, n,row))
	{
		//accept will end recursion once we've reached the bottom row
		for(int i = 0; i < n; i++)
		{
			//test our leaves
			pos[row].col = i; 
			bt(pos, n, row + 1);
		}
	}

}
bool reject(tile pos[], int n, int row)
{
	//originally this was way more complicated before I realized I could simply iterate backwards and combine my loops
	//left and right are for tracking diagonals and center to avoid changing the value in place by accident
	int left = pos[row - 1].col;
	int right = pos[row - 1].col;
	int center = pos[row - 1].col;
	for(int i = row - 2; i > -1; i--)
	{
		if(--left == pos[i].col || ++right == pos[i].col || center == pos[i].col)
		{
			return true;
		}
	}
	
	return false;
}
bool accept(tile pos[], int n, int row)
{
	//If reject hasn't killed the leaf we only need to check if the last tile has been assigned a col value. If it has then it is a valid solution and we can output
	if(row == n) //
	{
		for(int i = 0; i < n; i++)
		{
			print_line(n, pos[i].col);
		}
		cout << endl;
		return true;
	}
	return false;
}








