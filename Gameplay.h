#ifndef GAMEPLAY_H
#define GAMEPLAY_H

struct Gameplay {
  public:
    Gameplay();
    int validRow(int jugadaCol, char plays[15][15], int rows);
    int playCol();
    bool isWinner(char plays[15][15], int validRow, int playedCol, int rows, int cols);
  private:

};
#endif
