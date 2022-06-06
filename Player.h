#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
  public:
    Player();
    Player(string name);
    void printName();
    string getName();

  private:
    string _name;
};

#endif
