#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <stack>

class Grid;

class Game {
public:
    Game(Player p1, Player p2, Grid g);
    void GenerateBoard(int m, int n, int k);
    void Play();
    void PlayerChoice(Player p);
    void GetInput(Player& p);
	void Title();
	void PlayerSetup();
	void Instructions();
    void CalculateVictory(Player& player);
private: 
    Grid m_grid;
    Player m_p1;
    Player m_p2;
    stack<Grid> m_history;
};

#endif GAME_INCLUDED
