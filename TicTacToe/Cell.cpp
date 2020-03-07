#include "Player.h"
#include "Cell.h"
#include <string>

Cell::Cell() : m_owner(Player("", "-")) {}

Player Cell::GetOwner() { 
	return m_owner; 
}

void Cell::SetOwner(Player owner) { 
	m_owner = owner; 
}

string Cell::GetSymbol() {
	return m_owner.GetSymbol();
}