directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Node:
	def	__init__(self, f, g, parent, coords):
		self.f = f
		self.g = g
		self.parent = parent
		self.coords = coords
		self.x = coords[0]
		self.y = coords[1]

def	get_start(grid):
	rows = len(grid)
	cols = len(grid[0])
	ret = (-1, -1)
	i = 0
	while i < rows:
		j = 0
		while j < cols:
			if grid[i, j] == 2:
				ret = (i, j)
			j += 1
		i += 1
	return ret

def in_bounds(grid, i, j):
    len_row = len(grid)
    len_cols = len(grid[0]) if len_row > 0 else 0
    return 0 <= i < len_row and 0 <= j < len_cols

def	smallest_f(list_open) -> Node:
	smallest = -1
	ret = None
	for elem in list_open:
		if elem.f < smallest or smallest == -1:
			smallest = elem.f
			ret = elem
	return ret

def	valid_elem(coords, list, g):
	node = [n for n in list if n.x == coords[0] and n.y == coords[1]]
	node = node[0] if node else None
	if (node):
		if g < node.g:
			return True
		else:
			return False
	return True

def generate_successors(grid, start, goal, open_list, closed_list):	
	print(f"currently on {start.x} {start.y}")
	if in_bounds(grid, start.x + 1, start.y) and grid[start.x + 1, start.y] == 0 :
		print(f"went south in {start.x + 1} {start.y} value {grid[start.x + 1, start.y]}")
		f = (start.g + 1) + abs(start.x + 1 - goal[0]) + abs(start.y - goal[1])
		if valid_elem((start.x + 1, start.y), open_list, start.g + 1) \
				and valid_elem((start.x + 1, start.y), closed_list, start.g + 1):
			open_list.append(Node(f, start.g + 1, start, (start.x + 1, start.y)))

	if in_bounds(grid, start.x - 1, start.y) and grid[start.x - 1, start.y] == 0 :
		print(f"went north in {start.x - 1} {start.y} value {grid[start.x - 1, start.y]}")
		f = (start.g + 1) + abs(start.x - 1 - goal[0]) + abs(start.y - goal[1])
		if valid_elem((start.x - 1, start.y), open_list, start.g + 1) \
				and valid_elem((start.x - 1, start.y), closed_list, start.g + 1):
			open_list.append(Node(f, start.g + 1, start, (start.x - 1, start.y)))

	if in_bounds(grid, start.x, start.y + 1) and grid[start.x, start.y + 1] == 0 :
		print(f"went east in {start.x} {start.y + 1} value {grid[start.x, start.y + 1]}")
		f = (start.g + 1) + abs(start.x - goal[0]) + abs(start.y + 1 - goal[1])
		if valid_elem((start.x, start.y + 1), open_list, start.g + 1) \
				and valid_elem((start.x, start.y + 1), closed_list, start.g + 1):
			open_list.append(Node(f, start.g + 1, start, (start.x, start.y + 1)))

	if in_bounds(grid, start.x, start.y - 1) and grid[start.x, start.y - 1] == 0:
		print(f"went west in {start.x} {start.y - 1} value {grid[start.x, start.y - 1]}")
		f = (start.g + 1) + abs(start.x - goal[0]) + abs(start.y - 1 - goal[1])
		if valid_elem((start.x, start.y - 1), open_list, start.g + 1) \
				and valid_elem((start.x, start.y - 1), closed_list, start.g + 1):
			open_list.append(Node(f, start.g + 1, start, (start.x, start.y - 1)))

def a_solve(grid, start):
	for x in grid:
		print([elem for elem in x])
	open_list = []
	solution = []
	closed_list = []
	goal = (len(grid) - 2, len(grid[0]) - 2)
	print(goal)
	open_list.append(Node(0, 0, None, start))
	while not len(open_list) == 0:
		print([elem.coords for elem in open_list])
		q = smallest_f(open_list)
		if q.x == goal[0] and q.y == goal[1]:
			print("FOUND GOAL")
			while q != None:
				print(f"{q.x} {q.y} {q}")
				solution.append((q.x, q.y))
				q = q.parent
			break
		open_list.pop(open_list.index(q))
		closed_list.append(q)
		generate_successors(grid, q, goal, open_list, closed_list)
	return solution

