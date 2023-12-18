directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Node:
	def	__init__(self, f, g, parent, coords):
		self.f = f
		self.g = g
		self.parent = parent
		self.coords = coords
		self.next = None
		self.solution = None

def	smallest_f(list_open) -> Node:
	smallest = -1
	ret = None
	for elem in list_open:
		if elem.f < smallest or smallest == -1:
			smallest = elem.f
			ret = elem
	return ret

def generate_successors(grid, start):
	print(f"{grid[start.coords[0]][start.coords[1]].south}")
	if grid[start[0]][start[1]].south == 0:
		

def a_solve(grid, start, goal):
	open_list = []
	closed_list = []
	open_list.append(Node(0, 0, None, (0, 0)))
	while not len(open_list) == 0:
		q = smallest_f(open_list)
		print(q.coords)
		open_list.pop(open_list.index(q))
		closed_list.append(q)
		generate_successors(grid, q)

