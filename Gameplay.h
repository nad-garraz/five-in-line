#ifndef GAMEPLAY_H
#define GAMEPLAY_H

struct Gameplay {
  public:
    Gameplay();
    int validRow(int jugadaCol, char plays[15][15]);
    int playCol();
    bool isWinner(char plays[15][15]);
  private:

};
#endif
