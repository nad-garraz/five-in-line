#include <iostream>

#include "welcomeScreen.h"

using namespace std;

void print_title() {
  cout << "\x1B[31m        __  __     _             _ _                \033[0m"  << endl;
  cout << "\x1B[31m        \\ \\/ /    (_)_ __       | (_)_ __   ___   \033[0m" << endl;
  cout << "\x1B[31m         \\  /_____| | '_ \\ _____| | | '_ \\ / _ \\   \033[0m" << endl; 
  cout << "\x1B[31m         /  \\_____| | | | |_____| | | | | |  __/   \033[0m" << endl;
  cout << "\x1B[31m        /_/\\_\\    |_|_| |_|     |_|_|_| |_|\\___|  \033[0m" << endl;
  }

void print_menu(){
cout << "        TODO menu" << endl;
}


void gameOver(Player CurrentPlayer, int rows, int cols, int turn){
  if (turn ==  rows * cols) {
    cout << "\n*** It is a tie game ***" << endl;
  } else {
    cout << "\n***The Winner is " << CurrentPlayer.getName() << "*** " << endl;
  }

}

bool playAgain() {
  char ans;
  cout << "What to play again?: [Y/n]: ";
  cin >> ans;
  cout << endl;
  if ( ans != 'n' ) {
    return false;
  } else {
    return true;
  } 
}
