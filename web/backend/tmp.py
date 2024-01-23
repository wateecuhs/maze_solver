from flask import Flask, render_template
import random
from solve import *
import queue

app = Flask(__name__)

class Grid:
    def __init__(self):
        self.north = 0
        self.south = 0
        self.east = 0
        self.west = 0
        self.visited = 0
        self.ispath = 0

def generate_maze(grid, i, j):
    grid[i][j].visited = 1
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    random.shuffle(directions)
    for direction in directions:
        new_i, new_j = i + direction[0], j + direction[1]
        if in_bounds(grid, new_i, new_j) and grid[new_i][new_j].visited == 0:
            if direction == (0, 1):
                grid[i][j].east = 1
                grid[new_i][new_j].west = 1
            elif direction == (1, 0):
                grid[i][j].south = 1
                grid[new_i][new_j].north = 1
            elif direction == (0, -1):
                grid[i][j].west = 1
                grid[new_i][new_j].east = 1
            elif direction == (-1, 0):
                grid[i][j].north = 1
                grid[new_i][new_j].south = 1

            generate_maze(grid, new_i, new_j) 

@app.route('/')
def visualize_maze():
	grid = [[Grid() for _ in range(10)] for _ in range(10)]
	generate_maze(grid, 0, 0)
	a_solve(grid, (0, 0), (9, 9))
	return render_template('maze.html', grid=grid)

if __name__ == '__main__':
    grid = [[Grid() for _ in range(10)] for _ in range(10)]
    generate_maze(grid, 0, 0)
    a_solve(grid, (0, 0), (9, 9))
    app.run(debug=True)
