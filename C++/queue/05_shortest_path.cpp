//PROBLEM: Given a N x N matrix of positive integers, find shortest path from the first cell of the matrix to its last cell that satisfies given constraints.
//
//EARLY NOTES: In the matrix section I solved this problem using a backtracking approach that worked well. Here I will use a queue with a bfs approach. I copied over the code from that solution becuase I didn't want to type out the whole matrix again.
//
//PLANNING: Implement bfs approach. Add valid nodes each iteration. When we reach our destination we will have found a/the shortest path
//
//FINAL NOTES: It was fun to do this problem two different ways. I imagine there are faster and more space efficent solutions than both the solutions I have implemented. Nothing comes to mind immeditately but I'll keep thinking about possible ones. 

#include <iostream>
#include <queue>
#include <map>
#include <climits>

#define N 10
#define M 10
using namespace std;

//our movment options
const int row[] = {-1,0,0,1};
const int col[] = {0,-1,1,0};

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
struct Node {
	//x & y are row & col value, dist is distance from the start
	int x,y,dist;

	//compact constructor
	Node(int x, int y, int dist = 0): x(x),y(y),dist(dist) {}

	//after using this and the matrix approach I feel comfortable using
	//this approach from now on now that I understand the difference

	//write out comparison operator for our map
	bool operator<(const Node & o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

bool valid(int x, int y)
{
	if(x < 0 || x >= N || y < 0 || y >= M)
	{
		return false;
	}
	return true;
}
int bfs(Node src, Node des)
{
	//create our visited map
	map<Node,bool> visited;

	//create our queue
	queue<Node> q;

	//enqueue our starting node
	q.push(src);

	//begin queue
	while(!q.empty())
	{
		//grab the next node
		Node node = q.front();

		//pop the node
		q.pop();

		//grab the node values
		int x = node.x; //row
		int y = node.y; //col
		int dist = node.dist; //distance

		//check if this is the destination
		if(x == des.x && y == des.y)
		{
			return dist;
		}
		
		//if we've seen this node before ignore
		if(!visited.count(node))
		{
			//mark this node as visited
			visited[node] = true;	

			//grab the current value of the node
			int value = BOARD[x][y];

			//add valid nodes to the queue
			for(int i = 0; i < 4; i++)
			{
				//create our new moves
				int r = x + value * row[i];
				int c = y + value * col[i];
				
				//if the moves are on the board
				if(valid(r,c))
				{
					//create the new entry
					q.push({r,c,dist + 1});
				}
			}
		}
	}
	return INT_MAX;
}

int main()
{
	//our starting and ending node
	Node src = {0,0};
	Node des = {N-1,M-1};

	cout << "Shortest path is: " << bfs(src,des) << endl;

	return 0;
}

