/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

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
    bool ConsecutiveCheck(Player player, int r, int c, int& score, bool& in_row);
    void MarkCell(Player player);
    const int GetK();
    const int RowCount();
    const int ColCount();
	Cell** GetGrid();
    Player GetOwner(int r, int c);
	string GetSymbol(int r, int c);
	void PrintGrid();
private:
	int m_rows;
	int m_cols;
    int m_k;
	Cell** m_grid;
};
#endif //GRID_INCLUDED
