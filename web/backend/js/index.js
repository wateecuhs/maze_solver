function toggleCell(row, col) {
	fetch(`/toggle_cell?row=${row}&col=${col}`)
		.then(response => response.json())
		.then(data => {
			const cell = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
			if (data.value === 1) {
				cell.className = 'wall';
			}
			else if (data.value === 0 && (row + col) % 2 === 0) {
				cell.className = 'cell1';
			}
			else {
				cell.className = 'cell';
			}
		})
		.catch(error => console.error('Error:', error));
}

function sleep(ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}
function solveMaze() {
	fetch('/solve_maze')
		.then(response => response.json())
		.then(data => {
			console.log(data);
			let index = 0;

			function processSolutionPath() {
				if (index < data.length) {
					const solution_path = data[index];
					console.log(solution_path);
					const row = solution_path[0];
					const col = solution_path[1];
					const cell = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
					cell.className = 'path';
					index++;
					setTimeout(processSolutionPath, data.length > 30 ? 5000 / data.length : 50); // Adjust the delay (in milliseconds) as needed
				}
			}
			processSolutionPath();
		})
		.catch(error => console.error('Error:', error));
}

let draggedElement;

function dragStart(event) {
	draggedElement = event.target;
	event.dataTransfer.setData('text/plain', '');
	draggedElement.classList.add('dragging');
}

function allowDrop(event) {
  event.preventDefault();
}

function drop(event, row, col) {
	event.preventDefault();
	if (draggedElement) {
		const dropTarget = event.target;
		if ((dropTarget.classList.contains('cell') || dropTarget.classList.contains('cell1'))
			&& draggedElement.classList.contains('start')) {
			fetch(`/change_start?row=${row}&col=${col}`)
			draggedElement.classList.remove('start');
			dropTarget.classList.add('start');
			dropTarget.classList.remove('dragging');
			draggedElement.draggable = 'false';
			dropTarget.draggable = 'true';
	}
	draggedElement.classList.remove('dragging');
	draggedElement = null;
	}
}
function sendWindowSize() {
	const windowWidth = window.innerWidth;
	const windowHeight = window.innerHeight;
	console.log(windowHeight);

	fetch('/updateWindowSize', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
		},
		body: JSON.stringify({
			width: windowWidth,
			height: windowHeight,
		}),
		})
		.then(response => response.json())
		.then(updatedMaze => {
			renderMaze(updatedMaze);
		})
		.then(data => console.log(data))
		.catch(error => console.error('Error:', error));
}

window.addEventListener('resize', sendWindowSize);
window.onload = sendWindowSize();

function generateMaze() {
	const windowWidth = window.innerWidth;
	const windowHeight = window.innerHeight;
	fetch('/generate', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
		},
		body: JSON.stringify({
			width: windowWidth,
			height: windowHeight,
		}),
		})
		.then(response => response.json())
		.then(updatedMaze => {
			renderMaze(updatedMaze);
		})
		.then(data => console.log(data))
		.catch(error => console.error('Error:', error));
}

function renderMaze(updatedMaze) {
const table = document.getElementById('mazeTable');
	table.innerHTML = '';
	updatedMaze.forEach((row, outer_index) => {
		const tr = document.createElement('tr');
		row.forEach((cellValue, index) => {
			const td = document.createElement('td');
			if (cellValue === 1) {
				td.className = 'wall';
				td.onclick = function () {
					toggleCell(tr.rowIndex, td.cellIndex);
				};
				td.ondragstart = function (event) {
					dragStart(event);
				};
				td.ondrop = function (event) {
					drop(event, tr.rowIndex, td.cellIndex);
				};
				td.ondragover = function (event) {
					allowDrop(event);
				};
			}
			else if ((outer_index + index) % 2 === 0) {
				
				td.className = cellValue === 2 ?'cell1 start' : 'cell1';
				td.onclick = function () {
					toggleCell(tr.rowIndex, td.cellIndex);
				};
				if (cellValue === 2)
					td.draggable = true;
				td.ondragstart = function (event) {
					dragStart(event);
				};
				td.ondrop = function (event) {
					drop(event, tr.rowIndex, td.cellIndex);
				};
				td.ondragover = function (event) {
					allowDrop(event);
				};
			}
			else {
				td.className = cellValue === 2 ?'cell start' : 'cell';
				td.onclick = function () {
					toggleCell(tr.rowIndex, td.cellIndex);
				};
				if (cellValue === 2)
					td.draggable = true;
				td.ondragstart = function (event) {
					dragStart(event);
				};
				td.ondrop = function (event) {
					drop(event, tr.rowIndex, td.cellIndex);
				};
				td.ondragover = function (event) {
					allowDrop(event);
				};
			}
			tr.appendChild(td);
		});
	table.appendChild(tr);
});
}