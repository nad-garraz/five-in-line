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
  Player currentPlayer;

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
  currentPlayer = Player1;
  // Initialize token;
  char token = currentPlayer.getToken();
  int playedCol{};
  int validRow{};

  Tablero.printBoard(plays, rows, cols);

  while ( ! isDone ) {
    // Shows the play in board

    while (true) {
      // Ask which columns
      playedCol = Game.playCol(currentPlayer);

    // Changes the player token for next turn
    if ( Player1.getToken() == currentPlayer.getToken() ) {
        currentPlayer = Player2;
    } else{
      currentPlayer = Player1;
    }
      // Assign the value of the columns to plays
      validRow = Game.validRow(playedCol, plays, rows);
      if (validRow >= 0) {
        break;
      } else {
        cout << "Full column! Choose another " << endl;
        ;
      }
    }
    token = currentPlayer.getToken();
    plays[validRow][playedCol] = token;
    Tablero.printBoard(plays, rows, cols);
    isDone = Game.isWinner(plays, validRow, playedCol, rows, cols, winningNumber);

  }
  cout << "\n***The Winner is " << currentPlayer.getName() << "*** " << endl;

  return 0;
}
