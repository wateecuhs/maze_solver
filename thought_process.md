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

This is only temporary, to make an algorythm that works on a perfect maze.
After my code works i will make my own maze generator.


23/09

Scratching this whole shit. im making my own maze generator

Making a 2d struct array that contains the data needed for each algo and the surrounding walls position

grid ex:

							grid[width][length]	  grid[i][j]
{	[1, 2, 3, 4]			grid[0][0] grid[0][1] grid[0][2] grid[0][3]
	[5, 6, 7, 8]			grid[1][0] grid[1][1] grid[1][2] grid[1][3]
	[9, 10, 11, 12]			grid[2][0] grid[2][1] grid[2][2] grid[2][3]
	[13, 14, 15, 16]}		grid[3][0] grid[3][1] grid[3][2] grid[3][3]