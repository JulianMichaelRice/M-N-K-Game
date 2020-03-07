#include "Grid.h"
#include "Player.h"
#include "Cell.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

Game::Game(Player p1, Player p2, Grid g) : m_p1(p1), m_p2(p2), m_grid(g) {}

void Game::Play() {
    while (true) {
        m_grid.PrintGrid();
        GetInput(m_p1);
        m_grid.MarkCell(m_p1);
        //Process
        //Check Winner
        //Reset
    }
}

void Game::GetInput(Player& p) {
    int choice_r;
    int choice_c;
    while (true) {
        cout << "[" + p.GetSymbol() + "] " + p.GetName() + ", please select your tile's row followed by its column: ";
        cin >> choice_r >> choice_c;
        
        if (true) {
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
    cout << "Row: " << choice_r << " | Col: " << choice_c << endl;
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
