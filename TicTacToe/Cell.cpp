/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

#include "Player.h"
#include "Cell.h"
#include <string>

/*
 Cell() | Constructor |
    This function constructs a cell with a default symbol "-"
*/
Cell::Cell() : m_owner(Player("", "-")) {}

/*
 GetOwner() | Accessor Function |
    This function returns the owner (Class: Player) of the cell
*/
Player Cell::GetOwner() { 
	return m_owner; 
}

/*
 SetOwner() | Mutator Function |
    This function sets the owner (Class: Player) of the cell
*/
void Cell::SetOwner(Player owner) { 
	m_owner = owner; 
}

/*
 GetSymbol() | Accessor Function |
    This function is a higher level function that simply returns
    the cell owner's symbol. Made to reduce clutter when attempting to
    obtain the symbol data.
*/
string Cell::GetSymbol() {
	return m_owner.GetSymbol();
}
