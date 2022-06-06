#include <iostream>

#include "Gameplay.h"

using namespace std;

Gameplay::Gameplay(){

};

int Gameplay::validRow(int playedCol, char plays[15][15]) {
  int validRow{};
  while ( plays[validRow][playedCol] == ' ' ) {
    ++validRow;
  };
  return validRow - 1;
}

int Gameplay::playCol() {
  int col;
  cout << "Columna?: ";
  cout << endl;
  cin >> col;
  return col - 1; // So in starts at 1
}

bool Gameplay::isWinner(char plays[15][15]){
  return false;
}
