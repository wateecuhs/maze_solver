from flask import Flask, render_template
import random

app = Flask(__name__)

class Grid:
    def __init__(self):
        self.north = 0
        self.south = 0
        self.east = 0
        self.west = 0
        self.visited = 0

def in_bounds(grid, i, j):
    len_row = len(grid)
    len_cols = len(grid[0]) if len_row > 0 else 0
    return 0 <= i < len_row and 0 <= j < len_cols

def generate_maze(grid, i, j):
    grid[i][j].visited = 1

    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    random.shuffle(directions)

    for direction in directions:
        new_i, new_j = i + direction[0], j + direction[1]

        if in_bounds(grid, new_i, new_j) and grid[new_i][new_j].visited == 0:
            if direction == (0, 1):  # Move to the right
                grid[i][j].east = 1
                grid[new_i][new_j].west = 1
            elif direction == (1, 0):  # Move down
                grid[i][j].south = 1
                grid[new_i][new_j].north = 1
            elif direction == (0, -1):  # Move to the left
                grid[i][j].west = 1
                grid[new_i][new_j].east = 1
            elif direction == (-1, 0):  # Move up
                grid[i][j].north = 1
                grid[new_i][new_j].south = 1

            generate_maze(grid, new_i, new_j)



@app.route('/')
def visualize_maze():
	grid = [[Grid() for _ in range(10)] for _ in range(10)]
	generate_maze(grid, 0, 0)
	return render_template('maze.html', grid=grid)

if __name__ == '__main__':
    app.run(debug=True)
