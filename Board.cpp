#include <iostream>

#include "Board.h"

using namespace std;

Board::Board() {
  cout << "First we set the size of the board: " << endl;
  cout << "How many rows on board?: ";
  cin >> _rows;
  cout << "How many columns?: " << endl;
  cin >> _columns;
  cout << "Number to win?: " << endl;
  cin >> _winningNumber;
}

/*
Drawn row by row. The placehold for the plays is
in the "column % 4 == 1"nth place.
 */
void Board::printBoard(char plays[15][15], int rows, int cols) {
  for (int row{}; row < rows; ++row) {

    printSpaces();

    cout << "||";

    for (int col{}; col < cols * 4; ++col) {
      if (col % 4 == 3) {
        cout << "|";
      } else if (col % 4 == 1) {
        int column = col * 0.25;
        cout
            << plays[row][column]; // the info here should be from players plays
      } else {
        cout << " ";
      }
    }

    cout << "|";

    if ( row + 1 < rows ) {
      cout << "\n        ||";
      for (int col{}; col < cols * 4 - 1; ++col) {
        cout << "-";
      }
      cout << "||" << endl;
    }
  }
  cout << endl;
}

void Board::printSpaces() { cout << "        "; }

int Board::getRows() { return _rows; }

int Board::getColumns() { return _columns; }

int Board::getWinningNumber() { return _winningNumber; }
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
