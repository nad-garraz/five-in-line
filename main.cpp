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
  Player CurrentPlayer;

  Board Tablero;
  Gameplay Game;

  int rows = Tablero.getRows();
  int cols = Tablero.getColumns();
  int winningNumber = Tablero.getWinningNumber();

  // Max size of board
  char plays[15][15];
  // Initialize plays
  for (int i{1}; i <= rows; ++i) {
    for (int j{1}; j <= cols; ++j) {
      plays[i][j] = ' ';
    }
  }

  bool isDone = false;
  CurrentPlayer = Player1;
  // Initialize token;
  char token = CurrentPlayer.getToken();
  int playedCol{};
  int validRow{};

  Tablero.printBoard(plays, rows, cols);

  while (!isDone) {
    // Shows the play in board

    while (true) {
      // Ask which columns
      playedCol = Game.playCol(CurrentPlayer);

      // Assign the value of the columns to plays
      validRow = Game.validRow(playedCol, plays, rows);
      if (validRow <= rows) {
        break;
      } else {
        cout << "Full column! Choose another " << endl;
      }
    }
    token = CurrentPlayer.getToken();
    plays[validRow][playedCol] = token;
    Tablero.printBoard(plays, rows, cols);
    isDone =
    Game.isWinner(plays, validRow, playedCol, rows, cols, winningNumber);
    Game.turns(Player1, Player2, CurrentPlayer, token, isDone);

  }
  cout << "\n***The Winner is " << CurrentPlayer.getName() << "*** " << endl;

  return 0;
}
