#include <iostream>
#include <string>

#include "Board.h"
#include "Gameplay.h"
#include "Player.h"

using namespace std;

int main() {

  // Players
  Player Player1(1);
  Player Player2(2);

  Board Tablero;
  Gameplay Game;

  int rows = Tablero.getRows();
  int cols = Tablero.getColumns();
  int winningNumber = Tablero.getWinningNumber();

  // Max size of board
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

  Tablero.printBoard(plays, rows, cols);

  while ( ! isDone ) {
    // Shows the play in board

    while (true) {
      // Ask which columns
      playedCol = Game.playCol();

      // Assign the value of the columns to plays
      validRow = Game.validRow(playedCol, plays, rows);
      if (validRow >= 0) {
        break;
      } else {
        cout << "Columna llena! " << endl;
        ;
      }
    }

    plays[validRow][playedCol] = token;

    // Changes the player token for next turn
    token =
        (Player1.getToken() == token) ? Player2.getToken() : Player1.getToken();
    isDone = Game.isWinner(plays, validRow, playedCol, rows, cols, winningNumber);
    Tablero.printBoard(plays, rows, cols);
  }
  cout << "Salió"<< endl;

  return 0;
}
