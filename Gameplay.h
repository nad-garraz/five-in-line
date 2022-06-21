#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"
#include <vector>

struct Gameplay {

public:
  Gameplay();

  int playCol(Player currentPlayer);
  bool isTie(int turn, int cols, int rows);
  void turns(int &turns, Player &CurrentPlayer, vector<Player> players);

  vector<Player> playerInstances();

  bool isWinner(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber);
  bool checkVertical(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber);
  bool checkHorizontal(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber);
  bool checkDiagonalURtoDL(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber);
  bool checkDiagonalDRtoUL(char plays[15][15], int validRow, int playedCol, int rows, int cols, int winningNumber);
  int validRow(char plays[15][15], int playedCol, int rows);

private:
};
#endif
