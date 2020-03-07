#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>

using namespace std;

Game::Game(Player p1, Player p2, Grid g) : m_p1(p1), m_p2(p2), m_grid(g) {}

void Game::Play() {
    Grid* g = new Grid(m_grid);
    m_history.push(g);
    while (true) {
        PlayerChoice(m_p1);
        PlayerChoice(m_p2);
    }
}

void Game::PlayerChoice(Player p) {
    m_grid.PrintGrid();
    GetInput(p);
    //Process
    //Check Winner
    //Reset
}

void Game::GetInput(Player& p) {
    int choice_r;
    int choice_c;
    while (true) {
        cout << "[Note] To Go Back a State, Type 0 0" << endl;
        cout << "[" + p.GetSymbol() + "] " + p.GetName() + ", please select your tile's row followed by its column: ";
        cin >> choice_r >> choice_c;
        
        if (choice_r == 0 && choice_c == 0) {
            m_history.pop();
            m_grid = Grid(m_history.top());
            return;
        }
        
        if (!isdigit(choice_r) || !isdigit(choice_c)) {
            if (choice_r <= m_grid.RowCount() && choice_r > 0 &&
                choice_c <= m_grid.ColCount() && choice_c > 0) {
                if (m_grid.GetCell(choice_r-1, choice_c-1) == "-")
                    break;
                else
                    cout << "[Error] Has already been marked" << endl;
            } else {
                cout << "[Error] Not in bounds. (Row Range: 1~" << m_grid.RowCount() << " | Col Range: 1~" << m_grid.ColCount() << ")" << endl;
            }
        } else {
            cout << "[Error] One of the numbers wasn't a digit." << endl;
        }
        choice_r = 0;
        choice_c = 0;
    }
    p.SetChoice(choice_r-1, choice_c-1);
    m_grid.MarkCell(p);
    Grid* g = new Grid(m_grid);
    m_history.push(g);
    
//    cout << "BEFORE" << endl;
//    m_history.top().PrintGrid();
//    cout << "--------------" << endl;
//
//    cout << "JUST PUSHED..." << endl;
//    g->PrintGrid();
//    cout << "--------------" << endl;
}

void Game::GenerateBoard(int m, int n, int k) {
    m_grid = Grid(m, n, k);
}

void Game::CalculateVictory(Player& player) {
    //Check All Rows
    for (int i = 0; i < m_grid.RowCount(); i++) {
        if (m_grid.CheckRow(player, i)) {
            player.SetWinner();
        }
    }
    
    if (player.IsWinner())
        cout << "Winner is " + player.GetName() << endl;
    else
        cout << "No Winner Yet" << endl;;
}
