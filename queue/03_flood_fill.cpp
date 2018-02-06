//PROBLEM: Flood fill (also known as seed fill) is an algorithm that determines the area connected to a given node in a multi-dimensional array.
//
//EARLY NOTES: Copied over code from problem 01. Will use bfs. Won't need to return a value. Won't need an extra function. Will use numbers instead of colors or strings. Won't need a destination. Will run until the queue is empty. Won't need a visited portion.
//
//PLANNNING: From insdie the queue change the current node's color to the new value. Then check surronding valid nodes for their color. If they are the right color add them to the queue.
//
//FINAL NOTES: Worked well enough. Can be modified for strings or hex values. 

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

struct Node
{
	//x and y mean row and col
	int x,y;

	//compact constructor that needs row and col values
	Node(int x,int y):x(x),y(y) {}

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
int BFS(int mat[N][M], Node src,int replace)
{
	//queue to check moves and continue the path
	queue<Node> q;

	//grab the starting color/int
	int start = mat[src.x][src.y];

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

		//change the current color to 
		mat[x][y] = replace;

		//check all 8 moves and add valid ones to the queue
		for(int i = 0; i < 8; i++)
		{
			int x_1 = x + row[i];
			int y_1 = y + col[i];

			if(valid(x_1,y_1) && mat[x_1][y_1] == start)
			{
				q.push({x_1,y_1});
			}
		}

	}
}
int main()
{
	//our color map
	int mat[N][M] = {
		{1,1,1,2,2,2,2,2,2,2},
		{1,1,1,1,1,1,2,3,3,3},
		{2,2,2,2,2,2,2,3,3,3},
		{0,0,0,0,0,2,2,2,2,3},
		{0,4,4,4,4,4,2,3,3,3},
		{0,0,0,4,4,2,2,3,3,3},
		{0,5,0,4,4,4,4,4,4,3},
		{0,5,5,5,5,4,4,3,3,3},
		{0,5,5,3,5,5,5,5,3,3},
		{0,5,5,3,3,3,3,3,3,3}
	};
	//source node
	Node src = {3,9};

	//initial output
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	//breadth first search
	BFS(mat,src,6);

	//output again	
	cout << endl;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
