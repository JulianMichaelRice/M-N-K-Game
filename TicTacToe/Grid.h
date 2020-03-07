#ifndef GRID_INCLUDED
#define GRID_INCLUDED

class Player;
class Cell;
#include <string>
#include <iostream>

using namespace std;

class Grid {
public:
	Grid(int r, int c, Player p1);
	Cell* GetRow(int num);
	Cell* GetCol(int num);
	Cell** GetGrid();
	string GetSymbol(int i, int j);
	void PrintGrid();
private:
	int m_rows;
	int m_cols;
	Cell** m_grid;
};
#endif //GRID_INCLUDED