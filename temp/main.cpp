// Pre-Processor Operations
#include "Charecter.h"
#include "StartMenu.h"

using namespace std;

int main() {

  /* Clear Screen */
  if (system("cls"))
    system("clear");

  // Create Player
  Player *user = new Player();
  startMenu(user);

  return 0;
}
