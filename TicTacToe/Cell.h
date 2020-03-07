#ifndef CELL_INCLUDED
#define CELL_INCLUDED

class Player;
#include <string>

using namespace std;

class Cell {
public:
	Cell();
	Player GetOwner();
	void SetOwner(Player owner);
	string GetSymbol();
private:
	Player m_owner;
};

#endif //CELL_INCLUDED