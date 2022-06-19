#include <iostream>

#include "Board.h"

using namespace std;

Board::Board() {
  cout << "How many rows on board?: ";
  cin >> _rows;
  cout << endl;
  cout << "How many columns?: ";
  cin >> _columns;
  cout << endl;
  cout << "Number to win?: ";
  cin >> _winningNumber;
  cout << endl;
}

/*
Drawn row by row. The placehold for the plays is
in the "column % 4 == 1"nth place.
 */
void Board::printBoard(char plays[15][15], int rows, int cols) {
  for (int row{rows}; row > 0; --row) {

    cout << "||";

    for (int col{1}; col <= cols * 4; ++col) {
      if (col % 4 == 0) {
        cout << "|";
      } else if (col % 4 == 2) {
        int column = col * 0.25 + 0.5;
        cout << plays[row][column]; // the info here should be from players plays
      } else {
        cout << " ";
      }
    }

    cout << "|";

    if ( row > 0 ) {
      cout << "\n||";
      for (int col{1}; col < cols * 4; ++col) {
        cout << "-";
      }
      cout << "||" << endl;
    }
  }
  cout << endl;
}

void Board::printSpaces() { cout << "        "; }

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
