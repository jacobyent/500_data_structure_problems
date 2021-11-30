//PROBLEM: Given an island in the form of a square matrix and a point inside the matrix where a person is standing. The person is allowed to move on step in any direction (right,left,top,down) on the matrix. If he steps outside the matrix, he dies. Calculate the probability that he is alive after he walks n steps on the island.
//
//EARLY NOTES: My first thought is to test all possible paths of length n from the given point. Then for every path that ends in death subtract that from the total number of paths. Then divide that number from the total number of possible paths. That is our alive probability. 
//
//MID NOTES: It occured to me that I don't think we need to create or use a matrix. We just need to test if our move, moves out of the given boundary.
//
//PLANNING: Explore all paths of length n from the given point. Count every death. Subtract the number of deaths from the total number of paths, then divide by the total number of paths. This number will be our probability
//
//FINAL NOTES: I got my code working but after looking at techie's solution I realized I wasn't weighting the probabilities properly in my code. I'm going to leave this function as is and create a revised version implementing techie's solution.

#include <iostream>
#define N 3
using namespace std;
int paths = 0;
int explore(int row, int col, int moves)
{
	if(row < 0 || col < 0 || row >= N || col >= N)
	{
		paths++;
		return 1;
	}
	if(moves == 0)
	{
		paths++;
		return 0;
	}
	moves--;
	return explore(row - 1,col,moves) + explore(row + 1, col, moves) + explore(row, col - 1, moves) + explore(row, col + 1, moves);
}	
int main()
{
	//starting position
	int row = 0, col = 0;
	//number of moves
	int moves = 5;
	//return the number of deaths 
	int deaths = explore(row,col,moves);
	//calculate probability
	float prob = (float)(paths-deaths)/(float)paths;
	cout << "Alive Probability is: " << prob << endl;
	return 0;
}
