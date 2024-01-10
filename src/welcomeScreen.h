#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include "Player.h"

void print_title();
void print_menu();
void gameOver(Player CurrentPlayer, int rows, int cols, int turn);
bool playAgain();

#endif
