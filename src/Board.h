#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "Gameplay.h"
#include "welcomeScreen.h"


#include <iostream>
#include <vector>


using namespace std;


struct Board {
public:
  Board();
  int getRows() { return _rows; }
  int getCols() { return _cols; }
  int getWinningNumber() { return _winningNumber; }

  void setWinningNumber(int winningNumber);
  void printBoard(int rows, int cols);
  void printSpaces();
  void printSeparationLines(int rows, int cols, int row);
  void cleanBoard(int rows, int cols);
  void playGame();
  
  int validRow(int playedCol, int rows);
  bool isWinner(int validRow, int playedCol, int rows, int cols, int winningNumber);

private:
  int _rows;
  int _cols;
  int _winningNumber;
  char _plays[15][15]; // Max size of board
};

#endif
