#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"

struct Gameplay {
public:
  Gameplay();
  int validRow(int jugadaCol, char plays[15][15], int rows);
  int playCol(Player currentPlayer);
  bool isWinner(char plays[15][15], int validRow, int playedCol, int rows,
                int cols, int winningNumber);
  void turns(Player &Player1, Player &Player2, Player &CurrentPlayer, char token,
             bool isDone);

private:
};
#endif
