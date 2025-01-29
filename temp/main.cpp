// Pre-Processor Operations
#include "Charecter.h"
#include "GuiFunc.h"
#include "StartMenu.h"

using namespace std;

int main() {

  /* Clear Screen */
  clearScreen();

  // Create Player
  Player *user = new Player();
  startMenu(user);

  return 0;
}
