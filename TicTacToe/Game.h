/* -----------------------------
| Julian M. Rice
| TicTacToe (MNK Version, C++)
| March 2020
----------------------------- */

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <stack>

class Grid;

class Game {
public:
    Game(Player& p1, Player& p2, Grid& g);
    void Play();
    bool TieGame();
    void PlayerChoice(Player p);
    bool PlayerWon(Player p);
	void Instructions();
    Player GetPlayer(int n);
private: 
    Grid m_grid;
    Player m_p1;
    Player m_p2;
    stack<Grid> m_history;
};

#endif //GAME_INCLUDED
