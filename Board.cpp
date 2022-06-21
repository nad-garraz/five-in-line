#include <iostream>

#include "Board.h"

using namespace std;

// Get info on size and rules
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
in the "column % 4 == 2"nth place.
 */
void Board::printBoard(char plays[15][15], int rows, int cols) {
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
        cout
            << plays[row][column]; // the info here should be from players plays
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
