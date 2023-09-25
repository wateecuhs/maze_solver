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