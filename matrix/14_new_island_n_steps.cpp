//NOTE: This is my implementation of techie's solution to the island problem
//
//FINAL NOTE: My original implementation calculated the probabilities incorrectly because I weighted every possible path as equally likely. As we can see on the (0,0) n = 3 moves problem half of the first moves leads to immediate death. It then doesn't make sense that I was getting probabilities above 50%
#include <iostream>
#include <map>
#include <string>
#define N 3

using namespace std;

float explore(int row, int col, int n,map<string,float> &dp)
{
	if(n == 0)
	{
		//we made it woooo!
		return 1;
	}

	//build our key
	string key = to_string(row) + "|" + to_string(col) + "|" +to_string(n);

	//if we've seen the key before we can skip this step
	if(dp.find(key) == dp.end())
	{
		float p = 0.0;
		n--;
		//move up
		if(row > 0)
		{
			p += 0.25 * explore(row - 1,col,n,dp);
		}
		//move down
		if(row < N - 1)
		{
			p += 0.25 * explore(row + 1,col,n,dp);
		}
		//move left
		if(col > 0)
		{
			p += 0.25 * explore(row,col-1,n,dp);
		}
		//move right
		if(col < N - 1)
		{
			p += 0.25 * explore(row,col+1,n,dp);
		}
		dp[key] = p;
	}
	return dp[key];
}	
int main()
{
	//starting position
	int row = 0, col = 0;
	//number of moves
	int n = 3;
	//map to keep track of previous solutions
	map<string,float> dp;
	cout << "Alive Probability is: " << explore(row,col,n,dp) << endl;
	return 0;
}
