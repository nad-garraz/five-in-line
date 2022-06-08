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
  --validRow;
  return validRow;
}

int Gameplay::playCol(Player currentPlayer) {
  int col{};
  cout << currentPlayer.getName() << "'s turn. Choose column: ";
  cin >> col;
  cout << endl;
  --col; // Zero base calculations for columns in array
  return col;
}

// If last user inputs makes "winningNumber" in line return true to cut the game loop.
// For calculations:
// playedCol starts at ZERO
// validRow  starts at ZERO
bool Gameplay::isWinner(char plays[15][15], int validRow, int playedCol,
                        int rows, int cols, int winningNumber) {
  int count{};
  // Vertical check downwards
  if (validRow + winningNumber <= rows) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol]) {
        count++;
        if (count == winningNumber ) return true;
      } else {
        break;
      }
    }
  }// Horizontal check from left to right
  if (playedCol + winningNumber - 1 <= cols) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow][playedCol + i]) {
        count++;
        if (count == winningNumber)
          return true;
      } else {
        break;
      }
    }
  }// Horizontal check from right to left
  if (playedCol - (winningNumber - 1) >= 0) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow][playedCol - i]) {
        count++;
        if (count == winningNumber)
          return true;
      } else {
        break;
      }
    }
  }// Diagonal check from  upperright to lowerleft
  if (playedCol - (winningNumber - 2) >= 0 && validRow + winningNumber <= rows) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol - i]) {
        count++;
        if ( count == winningNumber ) return true;
      } else {
        break;
      }
    }
  }// Diagonal check from  upperleft to lowerright
  if (playedCol + (winningNumber - 1) <= cols && validRow + winningNumber <= rows) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol + i]) {
        count++;
        if (count == winningNumber ) return true;
      } else {
        break;
      }
    }
  }// Diagonal check from  lowerright to upperleft
  if (playedCol - (winningNumber - 1) >= 0 && validRow + winningNumber >= 0) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow - i][playedCol - i]) {
        count++;
        if (count == winningNumber)
          return true;
      } else {
        break;
      }
    }
  }// Diagonal check from  lowerleft to upperright
  if (playedCol + (winningNumber - 1) <= cols && validRow + winningNumber >= 0) {
    count = 1;
    for (int i{1}; i < winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow - i][playedCol + i]) {
        count++;
        if (count == winningNumber)
          return true;
      } else {
        break;
      }
    }
  }

  return false;
}
