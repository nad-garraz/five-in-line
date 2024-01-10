#include "Board.h"
#include "welcomeScreen.h"

using namespace std;

int main()
{
  print_title();
  print_menu();
  bool isDone = false;

  while (!isDone)
  {
    Board Tablero;
    Tablero.playGame();
    // After GameLoop
    isDone = playAgain();
  }
  return 0;
}
