#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class Player {
  public:
    Player();
    Player( int a, char tokens[10]);
    Player(string name, char token);
    void printName();

    string getName() { return _name;}
    char getToken() {return _token;}

  private:
    string _name;
    char _token;
};

#endif
