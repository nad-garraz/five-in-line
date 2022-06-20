#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"
#include <vector>

struct Gameplay {

public:
  Gameplay();
  int validRow(int jugadaCol, char plays[15][15], int rows);
  int playCol(Player currentPlayer);
  bool isWinner(char plays[15][15], int validRow, int playedCol, int rows,
                int cols, int winningNumber);
  bool isTie(int turn, int cols, int rows);
  void turns(int &turns, Player &CurrentPlayer, vector<Player> players);

private:
};
#endif
