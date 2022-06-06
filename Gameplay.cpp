#include <iostream>

#include "Gameplay.h"

using namespace std;

Gameplay::Gameplay(){

};

int Gameplay::validRow(int playedCol, char plays[100][100]) {
  int validRow{};
  while ( plays[validRow][playedCol] == ' ' ) {
    ++validRow;
    cout << "FLAG" << endl;
  };
  return validRow;
}

int Gameplay::playCol() {
  int col;
  cout << "Columna?: ";
  cout << endl;
  cin >> col;
  return col - 1; // So in starts at 1
}
