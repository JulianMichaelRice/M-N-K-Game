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
