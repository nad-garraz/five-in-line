#ifndef BOARD_H
#define BOARD_H

struct Board {
public:
  Board();
  int getRows();
  int getColumns();
  int getWinningNumber();

  void setWinningNumber(int winningNumber);
  void printBoard(char plays[15][15], int rows, int cols);
  void printBoardBase();

private:
  int _rows;
  int _columns;
  int _winningNumber;
};

#endif
