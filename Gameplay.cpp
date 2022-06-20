#include <iostream>
#include <vector>

#include "Gameplay.h"
#include "Player.h"

using namespace std;

Gameplay::Gameplay(){

};


void Gameplay::turns(int &turns, Player &CurrentPlayer, vector<Player> players) {
  int next_player = turns % players.size();
  CurrentPlayer = players[next_player];
  turns++;
}

int Gameplay::validRow(int playedCol, char plays[15][15], int rows) {
  int validRow{rows};
  if (plays[validRow][playedCol] != ' ') { cout << "Noup, columna llena" << endl; }
  while (plays[validRow][playedCol] == ' ' and validRow > 0) {
    --validRow;
  };
  ++validRow;
  return validRow;
}

int Gameplay::playCol(Player currentPlayer) {
  int col{};
  cout << currentPlayer.getName() << "'s turn. Choose column: ";
  cin >> col;
  cout << endl;
  return col;
}

// If last user inputs makes "winningNumber" in line return true to cut the game loop.
// For calculations:
// playedCol starts at one
// validRow  starts at one??
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
  }
  // Horizontal check from left to right
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
  }
  // Horizontal check from right to left
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

  }
// Diagonal check  "\"
    count = 1;
    bool notToLeft = true;
    bool notToRight = true;
    for (int i{1}; i <= winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol - i] && notToLeft) {
        count++;

        if ( count == winningNumber ) return true;

      }
      else {
        notToLeft = false;
      }

      if (plays[validRow][playedCol] == plays[validRow - i][playedCol + i] && notToRight) {
        count++;
        if ( count == winningNumber ) return true;
      } 
      else {
        notToRight = false;
      }
  }
  // Diagonal check  "/"
    count = 1;
    notToLeft = true;
    notToRight = true;
    for (int i{1}; i <= winningNumber; i++) {
      if (plays[validRow][playedCol] == plays[validRow + i][playedCol + i] && notToRight) {
        count++;
        if ( count == winningNumber ) return true;
      }
      else {
        notToRight = false;
      }

      if (plays[validRow][playedCol] == plays[validRow - i][playedCol - i] && notToLeft) {
        count++;
        if ( count == winningNumber ) return true;
      } 
      else {
        notToLeft = false;
      }
  }
  return false;
}
