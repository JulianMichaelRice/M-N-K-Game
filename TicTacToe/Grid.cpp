/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include <iostream>
#include <string>

using namespace std;

/*
 Grid(int r, int c, int k) | Constructor |
    @param r -> Number of rows for the game
    @param c -> Number of columns for the game
    @param k -> Win condition for the game
    This function creates a grid with sizing and the win
    condition determined by the function's parameters.
*/
Grid::Grid(int r, int c, int k) {
	m_rows = r;
	m_cols = c;
    m_k = k;
	m_grid = new Cell*[m_rows];

	for (int i = 0; i < m_rows; i++) {
		m_grid[i] = new Cell[m_cols];
	}
}

/*
 Grid(Grid* &g) | Constructor |
    @param g -> Grid that we are making a copy of
    This function modifies the cells for the grid in question
    so that it can be added to m_history in Game, which can be
    used to track moves made throughout the game.
*/
Grid::Grid(Grid* &g) {
    m_rows = g->RowCount();
    m_cols = g->ColCount();
    m_k = g->GetK();
    m_grid = new Cell*[m_rows];

    for (int i = 0; i < m_rows; i++) {
        m_grid[i] = new Cell[m_cols];
    }
    
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_grid[i][j].SetOwner(g->GetOwner(i, j));
        }
    }
}

/*
 GetK() | Type: bool |
    @param player -> The player / symbol we are checking for
    This function checks a row to see if the player has won the game or not.
    Returns true if the player has won.
*/
bool Grid::CheckRow(Player player, int row) {
    int score = 0;
    bool in_a_row = false;
    for (int i = 0; i < m_rows; i++) {
        if (ConsecutiveCheck(player, row, i, score, in_a_row))
            return true;
    }
    return false;
}

/*
 CheckCol() | Type: bool |
    @param player -> The player / symbol we are checking for
    This function checks a column to see if the player has won the game or not.
    Returns true if the player has won.
*/
bool Grid::CheckCol(Player player, int col) {
    int score = 0;
    bool in_a_row = false;
    for (int i = 0; i < m_cols; i++) {
        if (ConsecutiveCheck(player, i, col, score, in_a_row))
            return true;
    }
    return false;
}

/*
 CheckDia(Player player) | Type: bool |
    @param player -> The player / symbol we are checking for
    This function checks top-left/bottom-right and top-right/bottom-left
    diagonals to see if the player has won the game or not. Returns true
    if the player has won. Winning counts as having a consecutive number of
    symbols greater than the K value.
*/
bool Grid::CheckDia(Player player) {
    /* Create variables
       score -> The number of consecutive symbols a player has
       in_a_row -> Are the symbols being checked consecutively placed? */
    int score = 0;
    bool in_a_row = false;
    
    //Check Top-Left -> Bottom-Right styled Diagonals
    for (int i = 0; i < m_rows; i++) {
        if (ConsecutiveCheck(player, i, i, score, in_a_row))
            return true;
    }
    
    //Reset variables
    in_a_row = false;
    score = 0;
    
    //Check Top-Right -> Bottom-Left styled Diagonals
    for (int r = 0, c = m_cols-1; r < m_rows || c >= 0; r++, c--) {
        if (ConsecutiveCheck(player, r, c, score, in_a_row))
            return true;
    }
    return false;
}

/*
 ConsecutiveCheck() | Type: bool |
    @param player -> The player (and respective symbol) we are checking
    @param r -> The row we want to check
    @param c -> The column we want to check
    @param score -> pass by reference so we can modify the score as we check
    @param in_row -> pass by reference so we can check if the symbols are consecutive
    This function checks a singular cell to see if it has been marked by
    the player. The last two parameters work in tandem with for loops to check
    if the player has achieved the minimum score (K) to win the game.
*/
bool Grid::ConsecutiveCheck(Player player, int r, int c, int& score, bool& in_row) {
    
    if (player.GetSymbol() == m_grid[r][c].GetOwner().GetSymbol() && !in_row) {
        //If we run into player's symbol and the count is at 0,
        //start the consecutive count and add to their score
        score++;
        in_row = true;
    } else if (player.GetSymbol() == m_grid[r][c].GetOwner().GetSymbol() && in_row) {
        //If we run into the player's symbol and we are counting,
        //simply add to the score
        score++;
    } else if (player.GetSymbol() != m_grid[r][c].GetOwner().GetSymbol() && in_row) {
        //If we run into some other symbol and we are counting,
        //kill the combo or return true if the score is > k.
        if (score >= m_k) {
            return true;
        }
        r -= score-1;
        if (r <= 0) {
            r++;
        }
        score = 0;
        in_row = false;
    }
    
    //Return true if the score meets the win condition
    if (score >= m_k) {
        return true;
    }
    return false;
}


/*
 MarkCell(Player player) | Mutator Function |
    @param player -> The player that is marking the cell
    This function sets the owner of the cell the player has
    chosen as that player.
*/
void Grid::MarkCell(Player player) {
    m_grid[player.GetChoiceRow()][player.GetChoiceCol()].SetOwner(player);
}

/*
 GetK() | Accessor Function |
    This function returns the win condition value
*/
const int Grid::GetK() {
    return m_k;
}

/*
 RowCount() | Accessor Function |
    This function returns the number of rows in the grid
    
    *Note: I didn't name this GetRow() at first because I had
    made a Cell* type GetRow() function that I ended not needing
    for this project. Same applies for GetCol() and ColCount()...!
*/
const int Grid::RowCount() {
    return m_rows;
}

/*
 ColCount() | Accessor Function |
    This function returns the number of columns in the grid
*/
const int Grid::ColCount() {
    return m_cols;
}

/*
 GetGrid() | Accessor Function |
    This function returns the raw grid, a 2D cell array
*/
Cell** Grid::GetGrid() { 
	return m_grid; 
}

/*
 GetSymbol() | Accessor Function |
    This function returns the symbol that is
    present at the specified position (parameters)
*/
string Grid::GetSymbol(int r, int c) {
	return m_grid[r][c].GetOwner().GetSymbol();
}

/*
 GetOwner() | Accessor Function |
    This function returns the player that owns
    the cell at the specified position (parameters)
*/
Player Grid::GetOwner(int r, int c) {
    return m_grid[r][c].GetOwner();
}

/*
 PrintGrid() | Type: void |
    This function prints out the grid.
*/
void Grid::PrintGrid() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			cout << m_grid[i][j].GetSymbol() << "    ";
		}
		cout << endl;
	}
}
