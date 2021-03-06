//PROBLEM: Given a rectangular field with few sensors present on it, cross it by takng the shortest safe route without activating the sensors.
//
//EARLY NOTES: Another problem that we can adapt from the previous one. I copied the code over and of course will need to modify it
//
//PLANNING: Pass through the field searching for 0s. When one is found mark the adjacent cells as zero. Then enqueue all the first col cells in the queue, then procced as if it was a usual shortest path queue.
//
//FINAL NOTES: Fairly straight forward. Took me awhile to figure out to enqueue the first col but after that it was just small mistakes I was making. Had to modify the visited map to a matrix so it was easier to work with between functions.
//
#include <iostream>
#include <queue>
#include <map>
#include <climits>

#define N 10
#define M 10

using namespace std;

//these are for a our moves around the board
const int row[] = {-1,0,0,1};
const int col[] = {0,-1,1,0};

struct Node
{
	//x and y mean row and col, and dist is the distance from source 
	int x,y,dist;
	
	//compact constructor that needs row and col values
	Node(int x,int y, int dist = 0):x(x),y(y),dist(dist) {}
	
	//define comparison operator for sorting keys	
	bool operator<(const Node &o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

bool valid(int x, int y)
{
	//function to check if a move is off the map
	if(x < 0 || y < 0 || x >= N || y >= M)
	{
		return false;
	}
	return true;
}
int BFS(int mat[N][M],int visited[N][M])
{
	//queue to check moves and continue the path
	queue<Node> q;

	//move first col into queue	
	for(int i = 0; i < N; i++)
	{
		if(mat[i][0])
		{
			Node node = {i,0};
			q.push(node);
		}
	}	
	//while q has entries run the loop
	while(!q.empty())
	{
		//front returns a refernce to the first item in the queue
		Node node = q.front();

		//remove the element from the queue
		q.pop();

		//grab the data from the nod 
		int x = node.x;
		int y = node.y;
		int dist = node.dist;
	
		//if we've reached the end
		if(y == M - 1)
		{
			return dist;
		}

		//skip this node if we've been here before
		if(!visited[x][y])
		{
			//update visited
			visited[x][y] = 1;

			//check all 4 moves and add valid ones to the queue
			for(int i = 0; i < 4; i++)
			{
				int x_1 = x + row[i];
				int y_1 = y + col[i];
				
				//
				if(valid(x_1,y_1) && mat[x_1][y_1])
				{
					q.push({x_1,y_1, dist + 1});
				}
			}
		}

	}

	//if the loop exits there is no path to the destination
	//return the max value if that occurs
	return INT_MAX;
}
void sensor(int mat[N][M],int visited[N][M])
{
	int zr[] = {0,0,-1,-1,-1,1,1,1};
	int zc[] = {-1,1,-1,0,1,-1,0,1};

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			//if either one is a one we ignore
			if(!mat[i][j] && !visited[i][j])
			{
				visited[i][j] = 1;
				for(int y = 0; y < 8; y++)
				{
					int x = i + zr[y];
					int z = j + zc[y];
					if(valid(x,z))
					{
						mat[x][z] = 0; 
						visited[x][z] = 1;
					}
				}
			}
		}
	}
}
int main()
{
	//our maze
	int mat[N][M] = {
		{0,1,1,1,0,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,0},
		{1,1,1,1,1,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	int visited[N][M] = {0};
	sensor(mat,visited);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "number of moves to end: " << BFS(mat,visited) << endl;
	return 0;
}
