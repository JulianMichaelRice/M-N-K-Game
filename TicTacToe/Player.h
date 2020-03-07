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
    void SetChoice(int row, int col);
    int GetChoiceRow();
    int GetChoiceCol();
    bool IsWinner();
    void SetWinner();
private:
	string m_symbol;
	string m_name;
    int m_choice_r;
    int m_choice_c;
    bool m_winner;
};

#endif //PLAYER_INCLUDED
