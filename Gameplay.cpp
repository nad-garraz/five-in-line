#include <iostream>

#include "Gameplay.h"

using namespace std;

Gameplay::Gameplay(){

};

int Gameplay::validRow(int playedCol, char plays[15][15], int rows) {
  int validRow{};
  while (plays[validRow][playedCol] == ' ' and validRow < rows) {
    ++validRow;
  };
  validRow--;
  return validRow;
}

int Gameplay::playCol() {
  int col{};
  cout << "Columna?: ";
  cout << endl;
  cin >> col;
  col--;
  return col; // So in starts at 1
}

// Hay que controlar que la última jugada no tenga 5 token iguales consecutivos
bool Gameplay::isWinner(char plays[15][15], int validRow, int playedCol,
                        int rows, int cols) {
  int count{};

// Vertical check downwards
  if (validRow + 4 <= rows) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol]) {
        count++;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

// Horizontal check from left to right
  if (playedCol + 4 <= cols) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow][playedCol + i]) {
        count++;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

// Horizontal check from right to left
  if (playedCol - 4 >= 0) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow][playedCol - i]) {
        count++;
        cout << count << endl;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

// Diagonal check from  upperright to lowerleft
  if ( playedCol - 4 >= 0 && validRow + 4 <= rows ) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol - i]) {
        count++;
        cout << count << endl;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

// Diagonal check from  upperleft to lowerright
  if ( playedCol + 4 <= cols && validRow + 4 <= rows ) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol + i]) {
        count++;
        cout << count << endl;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

// Diagonal check from  lowerright to upperleft
  if ( playedCol - 4 >= 0 && validRow + 4 >= 0 ) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow - i][playedCol - i]) {
        count++;
        cout << count << endl;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

// Diagonal check from  lowerleft to upperright
  if ( playedCol + 4 <= cols && validRow + 4 >= 0 ) {
    count = 1;
    for (int i{1}; i < 5; i++) {
      if (plays[validRow][playedCol] == plays[validRow - i][playedCol + i]) {
        count++;
        cout << count << endl;
        if ( count == 5 ) return true;
      } else {
        break;
      }
    }
  }

  return false;
}
