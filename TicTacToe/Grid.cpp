#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include <iostream>
#include <string>

using namespace std;

Grid::Grid(int r, int c, Player p1) {
	m_rows = r;
	m_cols = c;
	m_grid = new Cell*[m_rows];

	for (int i = 0; i < m_rows; i++) {
		m_grid[i] = new Cell[m_cols];
	}
}

Cell* Grid::GetRow(int num) { 
	return m_grid[num]; 
}
	
Cell* Grid::GetCol(int num) { 
	Cell* c = new Cell[m_cols];
	for (int i = 0; i < m_cols; i++) {
		c[i] = m_grid[i][num];
	}
	return c;
}

Cell** Grid::GetGrid() { 
	return m_grid; 
}

string Grid::GetSymbol(int i, int j) { 
	return m_grid[i][j].GetOwner().GetSymbol(); 
}

void Grid::PrintGrid() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			cout << m_grid[i][j].GetSymbol() << "    ";
		}
		cout << endl;
	}
}