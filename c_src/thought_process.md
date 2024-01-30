Websites used for inspiration, research or anything related to this project:

https://angeluriot.com/maze_solver/ to visualize the algorithms
https://www.youtube.com/watch?v=sVcB8vUFlmU same as above
https://www.geeksforgeeks.org/a-search-algorithm/ to understand the A* algorithm
http://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html same as above

No code is looked up, if a website has a code example of an algorithm im trying to understand, i skip it.

18/09

maze will be formatted as such :
'.' is empty space
'#' is wall
generated with https://www.dcode.fr/maze-generator

the whole maze will be surrounded by #s to represent the surrounding walls.
ie:

...#############
...............#
####..####..####
#..#..#........#
#..####..#######
#.....#.....#..#
#..#######..#..#
#..............#
#..####..####..#
#.....#.....#...
#############...

this is a 5x5  (5 corridors)

23/09

Scratching this whole shit. im making my own maze generator

Making a 2d struct array that contains the data needed for each algo and the surrounding walls position

grid ex:

							grid[width][length]	  grid[i][j]
{	[1, 2, 3, 4]			grid[0][0] grid[0][1] grid[0][2] grid[0][3]
	[5, 6, 7, 8]			grid[1][0] grid[1][1] grid[1][2] grid[1][3]
	[9, 10, 11, 12]			grid[2][0] grid[2][1] grid[2][2] grid[2][3]
	[13, 14, 15, 16]}		grid[3][0] grid[3][1] grid[3][2] grid[3][3]

24/09

Generation of the maze using DFS algo done
Before doing other generation algorithms i want to do a solving algorithm that works
3 options : 
- bidirectional breadth first
- greedy best-first
- A*

BBF seems a bit too "easy"
GBF goes fast but wont always give shortest path which sucks
A* is hard but its the best one -> we go for A*

how it works :

you use an f variable that consists of h and q.
h being the distance from start to current position
q being estimated distance from current position to end
from the starting point you compare all of your possibles moves' f value and move to the lowest one
Finding a good heuristic for q is the hard part (see http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html)

25/09

I thought i could use the manhattan distance as the heuristic but it doesnt work as there are obstacles

i give up A* for now it is too much
I dont understand it very well yet i think and coding in C makes it harder

I think i will need to use 2 chained lists to keep track of the Open And Closed sets
im gonna do the breadth first then  bidirectional breadth first then idk

Didnt make anything work today.
i need to use chained lists more

27/09

Im gonna make a chained lists kind of like a heap/priority queue (never done/used them before, i might be wrong)
Instead of doing recursive fonction its a while loop that doesnt stop until either current node has no next node or current node data is end coords
the node will have next and prev values so i can check if we've already been to current coords

also had to add parent value to get the path that lead to solution and mark it as the solution
using the isVisited value from grid struct to check it and i use the parent value to find the real head of the list and free it so now i can remove the prev value

The print is fucking horrendous tho

30/09

Figured most of the A* algorithm
its a pain in the ass to implement in C but its almost done i think
my issue is when we are checking a potential path option and we are comparing to existing elements in the open/closed lists, i dont know how to handle if it already exists and how to implement it
multiple sites have different explanations for it
my understanding is
	if the current position already exists in the open list there is 2 options
		-if the existing one has lower f, you change the f and parent of current position to the existing position in open list (the path found in already existing one is better)
		-if the new one has lower f than the existing one, you replace the existing one by the new one
	same if it exists in closed list

generation of the maze isnt totally random
it generates a random number between 0 and 3 and does a full loop (ie: 2-3-0-1 or 3-0-1-2 or 1-2-3-0)
this means for the first wall we break it has 75% chance of being south (0) and 25% chance of being east(25%)
because it cant be north or west it will do the loop so 2-3-0-1 and 3-0-1-2 so 0 goes first in 3 out of 4 cases
this needs to be fixed somehow but its only an issue for 0:0 starts (i think)