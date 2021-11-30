//PROBLEM: Given a binary matrix where 0 represents water and 1 represents land, count the number of islands in it. A island is formed by connected one's.
//
//EARLY NOTES: This is the problem that lead me down the queue problem path. Beefore I solved it using a recursive algorithm. This time I am going to try to solve it using a queue and bfs.
//
//PLANNING: Create a visited matrix the same size as the board. Start an island count at zero. Then pass through the matrix looking for unvisited island tiles. When we find one increment the island count and begin a bfs search for other island tiles. Run the queue until it is empty, marking each valid island tile as we go. At the end return the count.
//
//FINAL NOTES: Completed without much fuss. I think I now know the difference between bfs and dfs search after some external reading. 
#include <iostream>
#include <queue>
#include <map>
#include <climits>

#define N 10
#define M 10

using namespace std;

//these are for a our moves around the board
const int row[] = {-1,-1,-1,0,0,1,1,1};
const int col[] = {-1,0,1,-1,1,-1,0,1};

bool valid(int x, int y)
{
	//function to check if a move is off the map
	if(x < 0 || y < 0 || x >= M || y >= N)
	{
		return false;
	}
	return true;
}
int BFS(int mat[N][M],int visited[N][M], pair<int,int> src)
{
	//initalize our queue
	queue<pair<int,int>> q;
	
	//enqueue first pair
	q.push(src);

	//while q has entries run the loop
	while(!q.empty())
	{
		//grab the leading element
		pair<int,int> node = q.front();

		//remove the element from the queue
		q.pop();

		//grab the data from the nod 
		int x = node.first;
		int y = node.second;

		//mark the current element as visited
		visited[x][y] = 1;

		//check all 8 moves and add valid ones to the queue
		for(int i = 0; i < 8; i++)
		{
			//new row value
			int r = x + row[i];

			//new col value
			int c = y + col[i];

			//if the move is on the board 
			//if the next value is still on the island
			//and we haven't been there before add to the queue
			if(valid(r,c) && mat[r][c] && !visited[r][c])
			{
				q.push(make_pair(r,c));
			}
		}

	}
}
int count_islands(int mat[N][M],int visited[N][M])
{
	int islands = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(mat[i][j] && !visited[i][j])
			{
				islands++;
				pair<int,int> src = {i,j};
				BFS(mat,visited,src);
			}
		}
	}
	return islands;
}
int main()
{
	//our island map
	int mat[N][M] = {
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
	int visited[N][M] = {0};
	cout << "Number of islands: " << count_islands(mat,visited) << endl;
	return 0;
}
