function removeSolutionDisplay() {
	stopDisplay = true;
    const cells = document.querySelectorAll('.table td');
    cells.forEach(cell => {
        cell.classList.remove('tmp');
        cell.classList.remove('tmp2');
		cell.textContent = null;
    });
}
let stopDisplay = false;

function addClickEventListeners() {
    const cells = document.querySelectorAll('.table td');
    cells.forEach(cell => {
        cell.addEventListener('click', removeSolutionDisplay);
    });
}

function toggleCell(row, col) {
	fetch
	fetch(`/toggle_cell?row=${row}&col=${col}`)
		.then(response => response.json())
		.then(data => {
			const cell = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
			if (data.value === 1) {
				cell.classList.remove('cell');
				cell.classList.remove('cel1');
				cell.classList.add('wall');
			}
			else if (data.value === 0 && (row + col) % 2 === 0) {
				cell.classList.remove('wall');
				cell.classList.add('cell1');
			}
			else {
				cell.classList.remove('wall');
				cell.classList.add('cell');
			}
		})
		.catch(error => console.error('Error:', error));
}

function solveMaze() {
	fetch('/solve_maze')
		.then(response => response.json())
		.then(data => {
			// console.log(data[0]);
			function processSolutionPath2() {
				console.log(index);
				if (index < data[1].length && stopDisplay === false) {
					const solution_path = data[1][index];
					const row = solution_path[0];
					const col = solution_path[1];
					const cell = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
					if (cell.classList.contains('start') === false && cell.classList.contains('goal') === false) {
						cell.classList.remove('tmp');
						cell.classList.add('tmp2');
					}
					index++;
					setTimeout(processSolutionPath2, data[1].length > 30 ? 4000 /  data[1].length : 50);
				}
			}
			let index = 0;
			function processSolutionPath() {
				if (index < data[0][0].length && stopDisplay === false) {
					console.log(data[0][0].length);
					const solution_path = data[0][0][index];
					const row = solution_path[0];
					const col = solution_path[1];
					const cell = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
					if (showValues) {
						cell.textContent = data[0][1][index];
					}
					if (cell.classList.contains('start') === false && cell.classList.contains('goal') === false) {
						console.log(`${row} ${col} is not start or goal`);
						cell.classList.add('tmp');
					}
					let timeout = 3000 / data[0][0].length;
					console.log(timeout);
					index++;
					setTimeout(processSolutionPath, timeout);
				}
				else {
					index = 0;
					processSolutionPath2();
				}
			}
			stopDisplay = false;
			addClickEventListeners();
			processSolutionPath();
		})
		.catch(error => console.error('Error:', error));
}

let draggedElement;
let isStart;

function dragStart(event) {
	isStart = 0;
	draggedElement = event.target;
	const transparentImage = new Image();
	transparentImage.src = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAACV0lEQVR42tWVsW4TQBCG73a3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W';
	event.dataTransfer.setDragImage(transparentImage, 0, 0);
	event.dataTransfer.setData('text/plain', '');
}

function dragStartIsStart(event) {
	console.log("here1");
	isStart = 1;
	draggedElement = event.target;
	const transparentImage = new Image();
	transparentImage.src = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAACV0lEQVR42tWVsW4TQBCG73a3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W';
	event.dataTransfer.setDragImage(transparentImage, 0, 0);
	event.dataTransfer.setData('text/plain', '');
}

function dragStartIsGoal(event) {
	console.log("here2");
	isStart = 2;
	draggedElement = event.target;
	const transparentImage = new Image();
	transparentImage.src = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAACV0lEQVR42tWVsW4TQBCG73a3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W';
	event.dataTransfer.setDragImage(transparentImage, 0, 0);
	event.dataTransfer.setData('text/plain', '');
}

function allowDrop(event) {
  event.preventDefault();
}

let dropTarget = null;

function dragOver(event, row, col) {
    event.preventDefault();
	if (isStart === 1)
	{
		if (dropTarget != null) {
			dropTarget.classList.remove('start');
			let tmp_row = dropTarget.parentNode.rowIndex;
			let tmp_col = dropTarget.cellIndex;
			dropTarget.onclick = function () {
				toggleCell(tmp_row, tmp_col);
			};
			dropTarget.ondragover = function (event) {
				dragOver(event, tmp_row, tmp_col);
			};
			dropTarget.ondragstart = function (event) {
				dragStart(event);
			};
		}
		dropTarget = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
		if (dropTarget.classList.contains('wall')) {
			toggleCell(row, col);
		}
		dropTarget.classList.add('start');
		draggedElement.classList.remove('start');
		dropTarget.onclick = null;
		dropTarget.ondragover = function (event) {
			dragOverStart(event, row, col);
		};
		dropTarget.ondragstart = function (event) {
			dragStartIsStart(event);
		};
		let tmp_row = draggedElement.parentNode.rowIndex;
		let tmp_col = draggedElement.cellIndex;
		draggedElement.onclick = function () {
			toggleCell(tmp_row, tmp_col);
		};
		draggedElement.ondragover = function (event) {
			dragOver(event, tmp_row, tmp_col);
		};
		draggedElement.ondragstart = function (event) {
			dragStart(event);
		};
		dropTarget.classList.add('start');
		fetch(`/change_start?row=${row}&col=${col}`)
	}
	else if (isStart === 2)
	{
		if (dropTarget != null) {
			dropTarget.classList.remove('goal');
			let tmp_row = dropTarget.parentNode.rowIndex;
			let tmp_col = dropTarget.cellIndex;
			dropTarget.onclick = function () {
				toggleCell(tmp_row, tmp_col);
			};
			dropTarget.ondragover = function (event) {
				dragOver(event, tmp_row, tmp_col);
			};
			dropTarget.ondragstart = function (event) {
				dragStart(event);
			};
		}
		dropTarget = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
		if (dropTarget.classList.contains('wall')) {
			toggleCell(row, col);
		}
		dropTarget.classList.add('goal');
		draggedElement.classList.remove('goal');
		dropTarget.onclick = null;
		dropTarget.ondragover = function (event) {
			dragOverStart(event, row, col);
		};
		dropTarget.ondragstart = function (event) {
			dragStartIsGoal(event);
		};
		let tmp_row = draggedElement.parentNode.rowIndex;
		let tmp_col = draggedElement.cellIndex;
		draggedElement.onclick = function () {
			toggleCell(tmp_row, tmp_col);
		};
		draggedElement.ondragover = function (event) {
			dragOver(event, tmp_row, tmp_col);
		};
		draggedElement.ondragstart = function (event) {
			dragStart(event);
		};
		dropTarget.classList.add('goal');
		fetch(`/change_goal?row=${row}&col=${col}`)
	}
	else if (dropTarget === null || dropTarget != document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`))
	{
		dropTarget = document.querySelector(`.table tr:nth-child(${row + 1}) td:nth-child(${col + 1})`);
		toggleCell(row, col);
	}
}

function dragOverStart(event, row, col) {
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
	stopDisplay = true;
	table.innerHTML = '';
	updatedMaze.forEach((row, outer_index) => {
		const tr = document.createElement('tr');
		row.forEach((cellValue, index) => {
			const td = document.createElement('td');
			if (cellValue === 1) {
				td.className = 'wall';
			}
			else if ((outer_index + index) % 2 === 0) {
				
				if (cellValue === 3)
					td.className = 'cell1 goal';
				else if (cellValue === 2)
					td.className = 'cell1 start';
				else
					td.className = 'cell1';
			}
			else {
				if (cellValue === 3)
					td.className = 'cell goal';
				else if (cellValue === 2)
					td.className = 'cell start';
				else
					td.className = 'cell';
			}
			if (cellValue === 2 || cellValue === 3) {
				if (cellValue === 2) {
					td.ondragstart = function (event) {
						dragStartIsStart(event);
					};
				}
				else {
					td.ondragstart = function (event) {
						dragStartIsGoal(event);
					};
				}
				td.ondragover = function (event) {
					dragOverStart(event, outer_index, index);
				};
			}
			else {
				td.onclick = function () {
					toggleCell(outer_index, index);
				};
				td.ondragover = function (event) {
					dragOver(event, outer_index, index);
				};
				td.ondragstart = function (event) {
					dragStart(event);
				};
			}
			td.ondrop = function (event) {
				drop(event, outer_index, index);
			};
			td.draggable = true;
			tr.appendChild(td);
		});
	table.appendChild(tr);
});
}