#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <string>

using namespace std;

class Player {
public:
	Player(string name, string symbol);
	string GetSymbol();
	void SetSymbol(string symbol);
	string GetName();
	void SetName(string name);
private:
	string m_symbol;
	string m_name;
};

#endif //PLAYER_INCLUDED
