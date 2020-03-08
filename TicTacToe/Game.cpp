/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>

using namespace std;

/*
 Game(Player& p1, Player& p2, Grid &g) | Constructor |
    @param p1 -> Player 1
    @param p2 -> Player 2
    @param g -> The grid
    This function creates the game with said parameters. Future feature
    could include creating a vector in main.cpp by asking for the # of players,
    getting their respective names and symbols, then using that as a parameter
    for this constructor rather than two Player classes.
*/
Game::Game(Player& p1, Player& p2, Grid& g) : m_p1(p1), m_p2(p2), m_grid(g) {}

/*
 Play() | Type: void |
    This function runs the game, which continues until someone wins
*/
void Game::Play() {
    //Initialize our grid with a copy
    Grid* g = new Grid(m_grid);
    
    //Push it to our history stack for the Undo-functionality
    m_history.push(g);
    
    //This is to keep things quick & simple for displaying the winner
    string winner = "";
    
    Instructions();
    
    //Game | Event Loop
    /*
     Works perfectly fine, but a future feature I would want to add to
     this is putting all the players in a Vector and allowing for more
     than 2 players to play. The grounds that I have built up for this
     should make 3+ players no problem whatsoever. Furthermore, I'm not
     a huge fan of copying and pasting code and simply changing the
     parameter (as seen below), but it's quick and works - It would be
     something that I change if I were to add the 3+ player functionality
     */
    while (true) {
        PlayerChoice(m_p1);
        
        if (PlayerWon(m_p1)) {
            m_p1.SetWinner();
            winner = m_p1.GetName();
            break;
        }
        
        if (TieGame()) {
            break;
        }
        
        PlayerChoice(m_p2);
        
        if (PlayerWon(m_p2)) {
            m_p2.SetWinner();
            winner = m_p2.GetName();
            break;
        }
        
        if (TieGame()) {
            break;
        }
    }
    
    //Congratulate the winner and end the game and program!
    /*
     Spec did not specific if it wanted me to allow undo-ing after
     the game was finished, so I decided against that particular option.
     */
    if (winner != "")
        cout << "Congratulations, " << winner << " won! " << endl;
    else
        cout << "Tie Game!" << endl;
    
    //Cleanup and delete everything in m_history
    while (!m_history.empty()) {
        m_history.pop();
    }
}

bool Game::TieGame() {
    for (int i = 0; i < m_grid.RowCount(); i++) {
        for (int j = 0; j < m_grid.ColCount(); j++) {
            if (m_grid.GetSymbol(i, j) == "-") {
                return false;
            }
        }
    }
    return true;
}

/*
 PlayerWon() | Type: void |
    @param p -> The player
    This function gets input from the player, checks edge cases, then
    marks the specified cell with the player's symbol. The core of the
    undo functionality is here with pushing grid states to the m_history stack.
*/
void Game::PlayerChoice(Player p) {
    //Print the grid out for the player to see
    m_grid.PrintGrid();
    
    int choice_r;   //Player's choice (row)
    int choice_c;   //Player's choice (col)
    
    //Get an input from the player
    while (true) {
        //If we have made at least a move, show this text
        if (m_history.size() > 1) {
            cout << "[Note] To Go Back a State, Type 0 0" << endl;
        }
        
        //Instructions for the player
        cout << "[" + p.GetSymbol() + "] " + p.GetName() + ", please select your tile's row followed by its column: ";
        
        //Player Input
        cin >> choice_r >> choice_c;
        
        if (cin.fail()) {
            //Invalid input
            cout << "[Error] Please enter a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
            
        } else if (choice_r == 0 && choice_c == 0 && m_history.size() > 1) {
            //If the player decides to undo and we are not at the start grid state
            //the game load the previous board
            
            //Delete the current grid
            m_history.pop();
            
            //Set the current grid to the most recent version
            m_grid = Grid(m_history.top());
            
            //Print it out and then send the player back to the beginning
            //of this while loop to input an answer
            m_grid.PrintGrid();
        } else if (choice_r <= m_grid.RowCount() && choice_r > 0 &&
                   choice_c <= m_grid.ColCount() && choice_c > 0) {
            //If the cell has yet to be marked and it's in bounds, mark it
            if (m_grid.GetSymbol(choice_r-1, choice_c-1) == "-")
                break;
            else
                cout << "[Error] Cell has already been marked" << endl;
        } else {
            //Cell is outside of grid bounds
            cout << "[Error] Not in bounds. (Row Range: 1 ~ " << m_grid.RowCount() << " | Col Range: 1 ~ " << m_grid.ColCount() << ")" << endl;
        }
        
        //Reset values if we have gotten to this point
        choice_r = 0;
        choice_c = 0;
    }
    
    //Set the player's choice and mark the cell
    p.SetChoice(choice_r-1, choice_c-1);
    m_grid.MarkCell(p);
    
    //Create a new grid with this current status and push it to m_history
    Grid* g = new Grid(m_grid);
    m_history.push(g);
}

/*
 PlayerWon() | Type: bool |
    @param p -> The player
    This function checks to see if a player has won the game
*/
bool Game::PlayerWon(Player p) {
    //Check all columns and return true if the player has won
    for (int i = 0; i < m_grid.ColCount(); i++) {
        if (m_grid.CheckCol(p, i)) {
            return true;
        }
    }
    //Check all rows and return true if the player has won
    for (int i = 0; i < m_grid.RowCount(); i++) {
        if (m_grid.CheckRow(p, i)) {
            return true;
        }
    }
    
    //Check all diagonals and return true if the player has won
    for (int i = 0; i < m_grid.RowCount(); i++) {
        if (m_grid.CheckDia(p)) {
            return true;
        }
    }
    //Nothing went through, so return false (no one has won yet)
    return false;
}

/*
 Instructions() | Type: void |
    This function prints out some instructions for the players to read
*/
void Game::Instructions() {
    cout << "|--------------------------------------------|" << endl;
    cout << "| Julian's Tic Tac Toe MNK Game: Instructions" << endl;
    cout << "| • Mark empty cells with your symbol!" << endl;
    cout << "| • Try to get " << m_grid.GetK() << " in a row!" << endl;
    cout << "| • Rows, Columns, Diagonals all count! GL!" << endl;
    cout << "|--------------------------------------------|" << endl;
}

/*
 GetPlayer() | Type: Player |
    @param n -> The player's number
    This function returns a player, but that player depends on
    the number used in the parameter.
*/
Player Game::GetPlayer(int n) {
    //Return the player depending on their number
    //Future TODO: Vectors to hold 3+ players & return based on index
    if (n == 1) {
        return m_p1;
    } else if (n == 2) {
        return m_p2;
    } else {
        cout << "[Error] Player does not exist" << endl;
        return m_p2;
    }
}
