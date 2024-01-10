#include <iostream>
#include <vector>

#include "Board.h"

using namespace std;

void clrscr() { cout << "\033[2J\033[1;1H"; }

// Get info on size and rules
Board::Board() {
  cout << "How many rows on board?: ";
  cin >> _rows;
  cout << endl;
  cout << "How many columns?: ";
  cin >> _cols;
  cout << endl;
  cout << "Number in line to win? (>1): ";
  cin >> _winningNumber;
  cout << endl;

  cleanBoard(_rows, _cols);
}

void Board::cleanBoard(int rows, int cols) {
  for (int i{1}; i <= rows; ++i) {
    for (int j{1}; j <= cols; ++j) {
      _plays[i][j] = ' ';
    }
  }
}

/*
Drawn row by row. The placehold for the plays is
in the "column % 4 == 2"nth place.
 */
void Board::printBoard(int rows, int cols) {
  cout << "\x1B[35m|\\\033[0m"; // Left wall decoration
  for (int col{1}; col <= cols * 4 - 1; ++col) {
    if (col % 4 == 0) {
      cout << "\x1B[34m_\033[0m";
    } else {
      cout << " ";
    }
  }

  cout << "\x1B[35m/|\033[0m" << endl; // right wall decoration

  for (int row{rows}; row > 0; --row) {

    cout << "\x1B[35m||\033[0m"; // Borde izquierdo

    for (int col{1}; col <= cols * 4; ++col) {
      if (col % 4 == 0) {
        cout << "\x1B[35m|\033[0m"; // col separator
      } else if (col % 4 == 2) {
        int column =
            col * 0.25 + 0.5; // eg: (col % 4 == 2) * 0.25 + 0.5 = 1, 2, 3, 4
        cout << _plays[row]
                      [column]; // the info here should be from players plays
      } else {
        cout << " ";
      }
      if (col == cols * 4)
        cout
            << "\x1B[35m|\033[0m"; // completes de right wall just for esthetics
    }

    if (row > 0) {
      cout << "\n\x1B[35m||\033[0m"; // Left wall from dash line
      for (int col{1}; col < cols * 4; ++col) {
        cout << "\x1B[34m-\033[0m";
      }
      cout << "\x1B[35m||\033[0m" << endl; //  Right wall from dash line + <cr>
    }
  }
  cout << endl;
}

void Board::printSpaces() { cout << "        "; }

void Board::playGame() {
 // Board instance 
  int rows = getRows();
  int cols = getCols();
  
  Gameplay Game;
  vector<Player> players = Game.playerInstances();
  Player CurrentPlayer = players[0];
  int turn = 1;
  bool isDone = false;
  char token{'-'};
  int playedCol{};
  int validRow{};
  int winningNumber = getWinningNumber();
  clrscr();

  printBoard(rows, cols);

  while (!isDone) { // GameLoop

    while (true) { // input control

      // Ask which col to play
      playedCol = Game.playCol(CurrentPlayer);

      // Assign the value of the col to plays
      validRow = Game.validRow(_plays, playedCol, rows);
      if (validRow <= rows) {
        break;
      } else {
        cout << "Full column! Choose another " << endl;
      }
    }

    token = CurrentPlayer.getToken();

    _plays[validRow][playedCol] = token; // set the token in the plays array

    clrscr();

    printBoard(rows, cols);

    isDone = Game.isTie(turn, cols, rows) or
             Game.isWinner(_plays, validRow, playedCol, rows, cols, winningNumber); // isDone == true --> bye

    if (!isDone){
      Game.turns(turn, CurrentPlayer, players); // passing by reference all players changes CurrentPlayer
    }
    // If there is a wineer
  }
    gameOver(CurrentPlayer, rows, cols, turn);
}

/*
          |\   _   _   _   _   _   _   _   _   /|
          ||   | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
          ||-----------------------------------||
          || $ | $ | $ | $ | $ | $ | $ | $ | $ ||
         =========================================
        ===========================================
     ================================================
   ====================================================

*/
