#include <string>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player() {
      cout << "Player's name: ";
      cin >> _name;
      cout << "\nWelcome " << _name << "\nChoose your token: ";
      cin >> _token;
}

Player::Player(string name, char token) {
  _name = name;
  _token = token;
}

string Player::getName() {
  return _name;
}

char Player::getToken() {
  return _token;
}

void Player::printName() {
  cout << getName() << endl;
}
