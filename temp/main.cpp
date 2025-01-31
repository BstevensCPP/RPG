// Pre-Processor Operations
#include "Charecter.h"
#include "GuiFunc.h"
#include "StartMenu.h"

int main() {

  /* Clear Screen */
  clearScreen();

  // Create Player
  startMenu(new Player());

  return 0;
}
