#include <iostream>
#include <string>
#include "Grid.h"
#include "Player.h"
#include "Cell.h"

using namespace std;

int main() {
  Player player1("Julian", "O");
  Player player2("Quinlan", "X");
  Grid grid(3, 3, player1);
  grid.PrintGrid();
}

