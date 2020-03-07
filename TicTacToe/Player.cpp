#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, string symbol) {
	m_symbol = symbol;
	m_name = name;
}

string Player::GetSymbol() { 
	return m_symbol; 
}

void Player::SetSymbol(string symbol) { 
	m_symbol = symbol; 
}

string Player::GetName() { 
	return m_name; 
}

void Player::SetName(string name) { 
	m_name = name; 
}

void Player::SetChoice(int row, int col) {
    m_choice_r = row;
    m_choice_c = col;
}

int Player::GetChoiceRow() {
    return m_choice_r;
}

int Player::GetChoiceCol() {
    return m_choice_c;
}

bool Player::IsWinner() {
    return m_winner;
}

void Player::SetWinner() {
    m_winner = true;
}
