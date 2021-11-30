//PROBLEM: Given a chess board, find the shortest distancce (minimum number of steps) taken by a Knight to reach given destination from given source.
//
//EARLY NOTES: I needed a lot of help on this one because it is my first queue problem. So my code is mainly just a copy of techie's code. However I will explain in my own words what is happening.
//
//PLANNING: Breadth first search using a queue. Build a struct called node to store each move. Use a map to keep track of visited nodes. Run the queue until we reach the destination or until it is empty. 
//
//FINAL NOTES: I think this was a good introduction to queues. I needed a lot of hand holding and hopefully in the next problem I'll need less

#include <iostream>
#include <queue>
#include <map>
#include <climits>

#define N 8

using namespace std;

//these are for a our moves around the board
const int row[] = {-2,-2,-1,-1,1,1,2,2};
const int col[] = {-1,1,-2,2,-2,2,-1,1};

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
	if(x < 0 || y < 0 || x >= N || y >= N)
	{
		return false;
	}
	return true;
}
int BFS(Node src, Node des)
{
	//map to track locations visited
	map<Node, bool> visited;

	//queue to check moves and continue the path
	queue<Node> q;
	
	//move source into stack
	q.push(src);
	
	//while the q has entries run the loop
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

			//check all 8 moves and add valid ones to the queue
			for(int i = 0; i < 8; i++)
			{
				int x_1 = x + row[i];
				int y_1 = y + col[i];

				if(valid(x_1,y_1))
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
	Node src = {0,7};
	Node des = {5,7};
	cout << "number of moves to end: " << BFS(src,des) << endl;
	return 0;
}
