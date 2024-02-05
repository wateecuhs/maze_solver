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

function dragStart(event) {
	isStart = 0;
	draggedElement = event.target;
	const transparentImage = new Image();
	transparentImage.src = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAACV0lEQVR42tWVsW4TQBCG73a3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W';
	event.dataTransfer.setDragImage(transparentImage, 0, 0);
	event.dataTransfer.setData('text/plain', '');
}

function dragStartIsStart(event) {
	isStart = 1;
	draggedElement = event.target;
	const transparentImage = new Image();
	transparentImage.src = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAACV0lEQVR42tWVsW4TQBCG73a3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W3a3W';
	event.dataTransfer.setDragImage(transparentImage, 0, 0);
	event.dataTransfer.setData('text/plain', '');
}

function dragStartIsGoal(event) {
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
