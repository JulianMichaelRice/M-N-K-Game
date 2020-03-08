/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

#include <iostream>
#include <string>
#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include "Game.h"

using namespace std;

int main() {
    Player player1("Julian", "O");
    Player player2("Quinlan", "X");
    
    int row;
    int col;
    int score;
    cout << "Enter Row, Col, and Score: ";
    cin >> row >> col >> score;
    
    Grid grid(row, col, score);
    Game game(player1, player2, grid);
    game.Play();
    
    grid.PrintGrid();
}

