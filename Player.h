#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class Player {
  public:
    Player();
    Player( int a );
    Player(string name, char token);
    void printName();
    string getName();
    char getToken();

  private:
    string _name;
    char _token;
};

#endif
