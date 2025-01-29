#include "Charecter.h"
#include "StartMenu.h"

using namespace std;

int main() {
  if (system("cls"))
    system("clear");

  Player *user = new Player();
  startMenu(user);

  return 0;
}
