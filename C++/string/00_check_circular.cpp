//PROBLEM: Check if given set of moves is circular or not.
//
//EARLY NOTES: I believe we can use one variable to keep track of orientation, and two more to keep track of current position.
//
//PLANNING: Create three ints. The first one will keep track of the orientation, and the second two will keep track of position. We'll start by pointing "north" any moves will increase the y value by 1. A right turn will point us to "east". Any moves in this direction will increase the x value by 1. Once we've finished with the string we'll check the x, and y values. If they are zero then our path is circular.
//
//FINAL NOTES: I was trying to think of a better way to do this problem than a bunch of if statments but nothing came to mind. 

using namespace std;

#include <iostream>
#include <cstring>
void check_circular(string input)
{
	char dir = 'N';
	int x = 0, y = 0;
	for(char& c:input)
	{
		if(c == 'M')
		{
			if(dir == 'N')
				y++;
			else if(dir == 'E')
				x++;
			else if(dir == 'S')
				y--;
			else
				x--;
		}
		else if(c == 'R')
		{
			if(dir == 'N')
				dir = 'E';
			else if(dir == 'E')
				dir = 'S';
			else if(dir == 'S')
				dir = 'W';
			else
				dir = 'N';
		}
		else
		{
			if(dir == 'N')
				dir = 'W';
			else if(dir == 'E')
				dir = 'N';
			else if(dir == 'S')
				dir = 'E';
			else
				dir = 'S';
		}
	}
	if(x == 0 && y == 0)
		cout << "Path is circular!\n";
	else
		cout << "Path is not circular\n";
}
int main()
{
	string input = "MRMRRRRRMRM";
	check_circular(input);
	return 0;
}
