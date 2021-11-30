//PROBLEM: Given a maze in the form of the binary rectangular matrix, find length of the shortest path in a maze from given source to given destination.
//
//EARLY NOTES: Problem seems very similar to last problem. I copied over the code and will readjust the parts that are needed
//
//PLANNING: Build a queue that will breadth first search for the destination. When we first encounter the destination node that will be the shortest path.
//
//FINAL NOTES: Went as I expected. Their code is different but functionally the same. Learned what memset was. 
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
	if(x < 0 || y < 0 || x >= M || y >= N)
	{
		return false;
	}
	return true;
}
int BFS(int mat[N][M], Node src, Node des)
{
	//map to track locations visited
	map<Node, bool> visited;

	//queue to check moves and continue the path
	queue<Node> q;
	
	//move source into stack
	q.push(src);
	
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
	
		//if we've reached the destination
		if(x == des.x && y == des.y)
		{
			return dist;
		}

		//skip this node if we've been here before
		if(!visited.count(node))
		{
			//create entry for current node
			visited[node] = true;

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
int main()
{
	//our maze
	int mat[N][M] = {
		{1,1,1,1,1,0,0,1,1,1},
		{0,1,1,1,1,1,0,1,0,1},
		{0,0,1,0,1,1,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{0,0,0,1,0,0,0,1,1,0},
		{1,0,1,1,1,0,0,1,1,0},
		{0,0,0,0,1,0,0,1,0,1},
		{0,1,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,0,0,1,1,1},
		{0,0,1,0,0,1,1,0,0,1}
	};
	Node src = {0,0};
	Node des = {N-1,M-1};
	cout << "number of moves to end: " << BFS(mat,src,des) << endl;
	return 0;
}
