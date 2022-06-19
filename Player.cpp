#include <string>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player() {}

Player::Player(int a) {
 switch ( a ) {
   case ( 1 ) : {
   cout << "First player's name: ";
   }; break;
   case ( 2 ) : {
     cout << "Second player's name: ";
   }; break;
 }
      cin >> _name;
      cout << "Choose your token, " << _name << ": ";
      cin >> _token;
}

Player::Player(string name, char token) {
  _name = name;
  _token = token;
}

void Player::printName() {
  cout << getName() << endl;
}
