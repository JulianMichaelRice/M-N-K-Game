#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include <iostream>
#include <string>

using namespace std;

Grid::Grid(int r, int c, int k) {
	m_rows = r;
	m_cols = c;
    m_k = k;
	m_grid = new Cell*[m_rows];

	for (int i = 0; i < m_rows; i++) {
		m_grid[i] = new Cell[m_cols];
	}
}

bool Grid::CheckRow(Player player, int row) {
    int score = 0;
    for (int i = 0; i < m_rows; i++) {
        if (player.GetSymbol() == m_grid[row][i].GetOwner().GetSymbol()) {
            score++;
        }
    }
    if (score >= m_k) {
        return true;
    }
    return false;
}

bool Grid::CheckCol(Player player, int col) {
    int score = 0;
    for (int i = 0; i < m_rows; i++) {
        if (player.GetSymbol() == m_grid[i][col].GetOwner().GetSymbol()) {
            score++;
        }
    }
    if (score >= m_k) {
        return true;
    }
    return false;
}

bool Grid::CheckDia(Player player) {
    int score = 0;
    for (int i = 0; i < m_rows; i++) {
        if (player.GetSymbol() == m_grid[i][i].GetOwner().GetSymbol()) {
            score++;
        }
    }
    if (score >= m_k) {
        return true;
    }
    return false;
}

string Grid::GetCell(int row, int col) {
    return m_grid[row][col].GetSymbol();
}

void Grid::MarkCell(Player p) {
    m_grid[p.GetChoiceRow()][p.GetChoiceCol()].SetOwner(p);
}

int Grid::RowCount() {
    return m_rows;
}

int Grid::ColCount() {
    return m_cols;
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
