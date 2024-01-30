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

def	get_goal(grid):
	rows = len(grid)
	cols = len(grid[0])
	ret = (-1, -1)
	i = 0
	while i < rows:
		j = 0
		while j < cols:
			if grid[i, j] == 3:
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
	for elem in reversed(list_open):
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
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    for dx, dy in directions:
        new_x, new_y = start.x + dx, start.y + dy
        if in_bounds(grid, new_x, new_y) and (grid[new_x, new_y] == 0 or grid[new_x, new_y] == 3):
            g = start.g + 1
            h = abs(new_x - goal[0]) + abs(new_y - goal[1])  # Manhattan distance heuristic
            f = g + h
            if valid_elem((new_x, new_y), open_list, g) and valid_elem((new_x, new_y), closed_list, g):
                open_list.append(Node(f, g, start, (new_x, new_y)))


def a_solve(grid, start):
	open_list = []
	solution = []
	closed_list = []
	goal = get_goal(grid)
	print(f"goal is {goal}")
	open_list.append(Node(0, 0, None, start))
	while not len(open_list) == 0:
		q = smallest_f(open_list)
		if q.x == goal[0] and q.y == goal[1]:
			print("FOUND GOAL")
			while q != None:
				solution.append((q.x, q.y))
				q = q.parent
			break
		open_list.pop(open_list.index(q))
		closed_list.append(q)
		generate_successors(grid, q, goal, open_list, closed_list)
	return [[[n.coords for n in closed_list], [n.f for n in closed_list]], solution]

