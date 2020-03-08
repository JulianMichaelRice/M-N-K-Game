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
    string p1name, p2name, p1sym, p2sym, answer;
    int row, col, score;
    
    while (true) {
        //Did not feel like implementing input validation here, but it can be done.
        //I did do it for when a player is marking a cell, so check that out!
        cout << "Enter Player 1's Name: ";
        cin >> p1name;
        
        cout << "Enter Player 1's Symbol: ";
        cin >> p1sym;
        
        cout << "Enter Player 2's Name: ";
        cin >> p2name;
        
        cout << "Enter Player 2's Symbol: ";
        cin >> p2sym;
        
        cout << "Enter Row, Col, and Score: ";
        cin >> row >> col >> score;
        
        if (score >= ((row * col)/2)) {
            cout << "[Error] Score should be less than 50% of the total # of cells" << endl;
            cout << "        Your SCORE value is " << score << " cells and the max for this grid is " << (row*col)/2 << " cells (" << (((float)score/(float)row*col))*100 << "% of cells" << ")" << endl;
            continue;
        }
        
        //Initialize the players
        Player player1(p1name, p1sym);
        Player player2(p2name, p2sym);
        
        //Initialize the grid
        Grid grid(row, col, score);
        
        //Initialize the game
        Game game(player1, player2, grid);
        game.Play();
        
        grid.PrintGrid();
        
        //Future TODO: Score tracking for players
        //Future TODO: Save and load previous win/loss data for players with specific names
        //Future TODO: Password system for 'logging' in with the above save/load features
        cout << "Play again (Y/N)? ";
        cin >> answer;
        
        if (answer != "Y" && answer != "y") {
            break;
        }
    }
    cout << "Thanks for playing! Hope you enjoyed it." << endl;
}
