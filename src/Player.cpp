#include <string>
#include <iostream>

#include "Player.h"

Player::Player() {}

Player::Player(int a, char tokens[10]) {
 switch ( a ) {
   case ( 1 ) : {
   cout <<  "1st player's name: ";
   }; break;
   case ( 2 ) : {
     cout << "2nd player's name: ";
   }; break;
   case ( 3 ) : {
     cout << "3rd player's name: ";
   }; break;
    default : {
      cout << a << "th player's name: ";
    }; break;
 }
  cin >> _name;
  char token_tmp;
  while (1) {
    cout << "Choose your token, " << _name << ": ";
    cin >> token_tmp;
    for (int i{}; i < a; i++) {
      if ( tokens[i] == token_tmp){
        cout << "Choose another token please." << endl;
      }
      else {
        _token = token_tmp;
        tokens[a-1] = _token;
        break;
      }
    }
    break;
  } 
}

Player::Player(string name, char token) {
  _name = name;
  _token = token;
}

void Player::printName() {
  cout << getName() << endl;
}
