#include <iostream>
#include <vector>

#include "Gameplay.h"
#include "Player.h"

using namespace std;

Gameplay::Gameplay(){

};

vector<Player> Gameplay::playerInstances() {
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
  return players;
}

void Gameplay::turns(int &turns, Player &CurrentPlayer,
                     vector<Player> players) {
  int next_player = turns % players.size();
  CurrentPlayer = players[next_player];
  turns++;
}

int Gameplay::playCol(Player currentPlayer) {
  int col{};
  cout << currentPlayer.getName() << "'s turn. Choose column: ";
  cin >> col;
  cout << endl;
  return col;
}

// If last user inputs makes "winningNumber" in line return true to cut the game
// loop. For calculations: playedCol starts at one validRow  starts at one??
bool Gameplay::isTie(int turn, int cols, int rows) {
  return (turn == cols * rows) ? true : false;
}

bool Gameplay::checkVertical(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber) {
  // Vertical check downwards
  int count{1};
  for (int i{1}; i <= winningNumber && i <= validRow; ++i) {
    if (plays[validRow][playedCol] == plays[validRow - i][playedCol]) {
      count++;
      if (count == winningNumber){return true;}
    } else {
      break;
    }
  }
  return false;
}

bool Gameplay::checkHorizontal(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber) {
  int count{1};
  bool notToLeft, notToRight = true;
  for (int i{1}; i <= winningNumber; i++) {
    if (plays[validRow][playedCol] == plays[validRow][playedCol + i] && notToRight) {
      ++count;
    } else {notToRight = false;} 
    if (plays[validRow][playedCol] == plays[validRow][playedCol - i] && notToLeft) {
      ++count;
    } else {notToLeft = false;} 
    if (count >= winningNumber) {return true;}
  }
  return false;
}

bool Gameplay::checkDiagonalURtoDL(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber) {
  // Diagonal check  "\"
  int count{1};
  bool notToLeft{true}, notToRight{true};
  for (int i{1}; i <= winningNumber; i++) {
    if (plays[validRow][playedCol] == plays[validRow - i][playedCol + i] && notToRight) {
      ++count;
    } else {notToRight = false;} 
    if (plays[validRow][playedCol] == plays[validRow + i][playedCol - i] && notToLeft) {
      ++count;
    } else {notToLeft = false;} 
    if (count >= winningNumber) {return true;}
  }
  return false;
}

bool Gameplay::checkDiagonalDRtoUL(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber) {
  // Diagonal check  "/"
  int count{1};
  bool notToLeft{true}, notToRight{true};
  for (int i{1}; i <= winningNumber; i++) {
    if (plays[validRow][playedCol] == plays[validRow + i][playedCol + i] && notToRight) {
      ++count;
    } else {notToRight = false;} 
    if (plays[validRow][playedCol] == plays[validRow - i][playedCol - i] && notToLeft) {
      ++count;
    } else {notToLeft = false;} 
    if (count >= winningNumber) {return true;}
  }
  return false;
}

bool Gameplay::isWinner(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber) {
  if (checkVertical(plays, validRow, playedCol, rows, cols, winningNumber) ||
      checkHorizontal(plays, validRow, playedCol, rows, cols, winningNumber) ||
      checkDiagonalURtoDL(plays, validRow, playedCol, rows, cols, winningNumber) || checkDiagonalDRtoUL(plays, validRow, playedCol, rows, cols, winningNumber)) {
    return true;
  }
  else {
    return false;
  }
}

int Gameplay::validRow(char plays[15][15], int playedCol, int rows) {
  int validRow{rows};
  if (plays[validRow][playedCol] != ' ') {
    cout << "Noup, columna llena" << endl;
  }
  while (plays[validRow][playedCol] == ' ' && validRow > 0) {
    --validRow;
  };
  ++validRow;
  return validRow;
}
