from flask import Flask, render_template, jsonify, request, send_from_directory
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
	maze[2*x+1, 2*y+1] = 2
	stack = [(x, y)]
	while len(stack) > 0:
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
	solution = a_solve(maze, get_start(maze))
	solution[1].reverse()
	return jsonify(solution)

@app.route('/change_start')
def change_start():
	row = int(request.args.get('row'))
	col = int(request.args.get('col'))
	try:
		coords_start = get_start(maze)
		maze[coords_start[0], coords_start[1]] = 0
		maze[row, col] = 2
	except Exception as err:
		print(err)
	return jsonify([(row, col), coords_start])

@app.route('/change_goal')
def change_goal():
	row = int(request.args.get('row'))
	col = int(request.args.get('col'))
	try:
		coords_start = get_goal(maze)
		maze[coords_start[0], coords_start[1]] = 0
		maze[row, col] = 3
	except Exception as err:
		print(err)
	return jsonify([(row, col), coords_start])

@app.route('/toggle_cell')
def toggle_cell():
	row = int(request.args.get('row'))
	col = int(request.args.get('col'))
	maze[row, col] = 1 - maze[row, col]

	return jsonify({'value': maze[row, col]})

@app.route('/generate', methods=['POST'])
def	generateMaze():
	data = request.json
	width = data.get('width')
	height = data.get('height')
	width = width * 0.65
	cols = int(width / 20)
	if cols % 2 == 0:
		cols = cols - 1
	height = height * 0.85
	rows = height / 20
	rows = int(rows)
	if rows % 2 == 0:
		rows = rows - 1
	global maze
	maze = np.ones((rows, cols))
	generate_maze(maze, (0, 0))
	maze[len(maze) - 2, len(maze[0]) - 2] = 3
	return jsonify(maze.tolist())

@app.route('/<path:filename>')
def serve_js(filename):
	return send_from_directory('js', filename)

@app.route('/updateWindowSize', methods=['POST'])
def update_window_size():
	data = request.json
	width = data.get('width')
	height = data.get('height')

	width = width * 0.65
	cols = int(width / 20)
	if cols % 2 == 0:
		cols = cols - 1
	height = height * 0.85
	rows = height / 20
	rows = int(rows)
	if rows % 2 == 0:
		rows = rows - 1
	global maze
	maze = np.zeros((rows, cols))
	maze[1, 1] = 2
	maze[len(maze) - 2, len(maze[0]) - 2] = 3
	return jsonify(maze.tolist())

@app.route('/')
def visualize_maze():
	global maze
	height = 21
	width = 21
	maze = np.zeros((height, width))
	maze[1, 1] = 2
	return render_template('maze.html', grid=maze)

if __name__ == '__main__':
	app.run(debug=True)
