/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

#include "Player.h"
#include <string>

using namespace std;

/*
 Player(string name, string symbol) | Constructor |
    @param name -> The name of the player
    @param symbol -> The player's symbol
    This function creates a player with the specified name and symbol
*/
Player::Player(string name, string symbol) {
	m_symbol = symbol;
	m_name = name;
}

/*
 GetSymbol() | Accessor Function |
    This function returns the player's symbol
*/
string Player::GetSymbol() { 
	return m_symbol; 
}

/*
 SetSymbol() | Mutator Function |
    This function sets the player's symbol to the specified parameter's value
*/
void Player::SetSymbol(string symbol) { 
	m_symbol = symbol; 
}

/*
 GetName() | Accessor Function |
    This function gets the player's name
*/
string Player::GetName() { 
	return m_name; 
}

/*
 SetName() | Mutator Function |
    This function sets the player's name to the specified parameter's value
*/
void Player::SetName(string name) { 
	m_name = name; 
}

/*
 SetChoice() | Mutator Function |
    This function sets the player's choice up to the specific parameters' values
*/
void Player::SetChoice(int row, int col) {
    m_choice_r = row;
    m_choice_c = col;
}

/*
 GetChoiceCol() | Accessor Function |
    This function returns the player's choice (column)
*/
int Player::GetChoiceRow() {
    return m_choice_r;
}

/*
 GetChoiceRow() | Accessor Function |
    This function returns the player's choice (row)
*/
int Player::GetChoiceCol() {
    return m_choice_c;
}

/*
 IsWinner() | Accessor Function |
    This function returns if the player won the game or not
*/
bool Player::IsWinner() {
    return m_winner;
}

/*
 SetWinner() | Mutator Function |
    This function marks the player as the winner of the game
*/
void Player::SetWinner() {
    m_winner = true;
}
