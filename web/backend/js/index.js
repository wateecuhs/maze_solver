function toggleCell(row, col) {
	fetch(`/toggle_cell?row=${row}&col=${col}`)
		.then(response => response.json())
		.then(data => {
			const cell = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
			cell.className = data.value === 1 ? 'wall' : 'cell';
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
					setTimeout(processSolutionPath, 50); // Adjust the delay (in milliseconds) as needed
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

function drop(event) {
	event.preventDefault();

	if (draggedElement) {
		const dropTarget = event.target;
		if (dropTarget.classList.contains('cell')) {
		const tempClass = draggedElement.className;
			draggedElement.className = dropTarget.className;
			dropTarget.className = tempClass;
			dropTarget.classList.remove('dragging');
	}
	draggedElement.classList.remove('dragging');
	draggedElement = null;
	}
}