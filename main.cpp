#include <iostream>
#include <string>
#include <vector>

#include "Board.h"
#include "Gameplay.h"
#include "Player.h"

using namespace std;

void clrscr() { cout << "\033[2J\033[1;1H"; }

int main() {

  char ans;
  char tokens[10]; // Array to store token. Up to 10 players
  vector<Player> players{};

  // Players
  for (int i{1}; i <= 10; ++i) {
    switch (i) {
    case (1): {
      players.push_back(Player(i, tokens));
    }; break;
    case (2): {
      players.push_back(Player(i, tokens));
    }; break;
    default: {
      players.push_back(Player(i, tokens));
    }; break;
    }
    if (i >= 2) {
      cout << "Add another player? [y/n]: ";
      cin >> ans;
      if (ans == 'n') {
        break;
      }
    }
  }

  int turn = 1;
  Player CurrentPlayer = players[0]; // jugador del turno, inicia el 1st player

  Board Tablero;
  Gameplay Game;

  int rows = Tablero.getRows();
  int cols = Tablero.getColumns();
  int winningNumber = Tablero.getWinningNumber();

  char plays[15][15]; // Max size of board
  for (int i{1}; i <= rows; ++i) {
    for (int j{1}; j <= cols; ++j) {
      plays[i][j] = ' ';
    }
  }

  bool isDone = false;

  // Initialize token;
  char token{' '};
  int playedCol{};
  int validRow{};
  clrscr();
  Tablero.printBoard(plays, rows, cols);

  while (!isDone) {
    // Shows the play in the board

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
    clrscr();
    Tablero.printBoard(plays, rows, cols);

    isDone = Game.isTie(turn, cols, rows) or Game.isWinner(plays, validRow, playedCol, rows, cols,
                           winningNumber); // isDone == true --> bye

    if (!isDone)
      Game.turns(
          turn, CurrentPlayer,
          players); // passing by reference all players changes CurrentPlayer
  }
  if (turn == rows * cols) {
    cout << "\n*** It is a tie game ***" << endl;
  } else {
    cout << "\n***The Winner is " << CurrentPlayer.getName() << "*** " << endl;
  }
  return 0;
}
