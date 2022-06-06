#include <string>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player() {}

Player::Player(string name) { _name = name; }

string Player::getName() {
  return _name;
}

void Player::printName() {
  cout << getName() << endl;
}
