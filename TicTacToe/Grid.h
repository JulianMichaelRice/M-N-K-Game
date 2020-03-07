#ifndef GRID_INCLUDED
#define GRID_INCLUDED

class Player;
class Cell;
#include <string>
#include <iostream>

using namespace std;

class Grid {
public:
	Grid(int r, int c, int k);
    Grid(Grid* &g);
    bool CheckRow(Player player, int row);
    bool CheckCol(Player player, int col);
    bool CheckDia(Player player);
    string GetCell(int row, int col);
    void MarkCell(Player p);
    const int RowCount();
    const int ColCount();
    const int WinCondition();
	Cell** GetGrid();
    Player GetOwner(int i, int j);
	string GetSymbol(int i, int j);
	void PrintGrid();
private:
	int m_rows;
	int m_cols;
    int m_k;
	Cell** m_grid;
};
#endif //GRID_INCLUDED
