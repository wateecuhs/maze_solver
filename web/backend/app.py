from flask import Flask, render_template, jsonify, request
import numpy as np
import random
import matplotlib.pyplot as plt
from solve import *
import queue

app = Flask(__name__)

def in_bounds_t(grid, new_coords):
	len_row = len(grid)
	len_cols = len(grid[0]) if len_row > 0 else 0
	return 0 <= new_coords[0] < len_row and 0 <= new_coords[1] < len_cols

def generate_maze(maze, start_coords):
	x, y = start_coords
	maze[2*x+1, 2*y+1] = 0
	stack = [(x, y)]
	while len(stack) > 0:
		print(f"{x} {y}")
		x, y = stack[-1]
		directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
		random.shuffle(directions)
		for dx, dy in directions:
			nx, ny = x + dx, y + dy
			if nx >= 0 and ny >= 0 and 2*nx+1 < maze.shape[0] and 2*ny+1 < maze.shape[1] and maze[2*nx+1, 2*ny+1] == 1:
				maze[2*nx+1, 2*ny+1] = 0
				maze[2*x+1+dx, 2*y+1+dy] = 0
				stack.append((nx, ny))
				break
		else:
			stack.pop()

@app.route('/solve_maze')
def solve_button():
	a_solve(maze, (0,0), (10, 10))
	return jsonify(maze.tolist())

@app.route('/toggle_cell')
def toggle_cell():
    row = int(request.args.get('row'))
    col = int(request.args.get('col'))
    maze[row, col] = 1 - maze[row, col]

    return jsonify({'value': maze[row, col]})

@app.route('/')
def visualize_maze():
	height = 15
	width = 15
	global maze
	maze = np.ones((height, width))
	generate_maze(maze, (0, 0))
	return render_template('maze.html', grid=maze)

if __name__ == '__main__':
	height = 15
	width = 15
	maze = np.ones((height, width))
	generate_maze(maze, (0, 0))
	app.run(debug=True)
