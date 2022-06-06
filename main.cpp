#include <iostream>
#include <string>

#include "Board.h"
#include "Player.h"
#include "Gameplay.h"

using namespace std;

int main() {

//Players
  Player Player1;
  Player Player2;

  Board Tablero;
  Gameplay Game;

  int rows = Tablero.getRows();
  int cols = Tablero.getColumns();

  char plays[15][15];
  // Initialize plays
  for (int i{}; i < rows; ++i) {
    for (int j{}; j < cols; ++j) {
      plays[i][j] = ' ';
    }
  }
  bool isDone = false;
  char token = Player1.getToken();
  int playedCol{};
  int validRow{};
  while ( ! isDone ) {
    // Shows the play in board
    Tablero.printBoard(plays, rows, cols);

    // Ask which columns
    playedCol = Game.playCol();

    // Assign the value of the columns to plays
    validRow = Game.validRow(playedCol, plays);
    plays[validRow][playedCol] = token;

    //Changes the player token for next turn
    token = ( Player1.getToken() == token ) ? Player2.getToken() : Player1.getToken();
    // isDone = Gameplay.isWinner(plays);

  }


  return 0;
}
