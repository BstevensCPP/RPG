// Pre-Processor Operations
#pragma once
#include "Charecter.h"
#include "EnterBattle.h"
#include "SelectionList.h"
#include <limits>

void startMenu(Player *user) {

  // Variables
  bool run = true;
  string options[] = {"Return to Game", "Enter Battle",     "Manage Inventory",
                      "Enter Shop",     "Talke to Someone", "Quit Game"};

  // Display menu until user quits
  while (run) {
    switch (selectionList(options, sizeof(options) / sizeof(options[0]), 0)) {
    case 1:
      // returnToOverworld();
      break;
    case 2:
      EnterBattle(user);
      break;
    case 3:
      // manageInventory();
      break;
    case 4:
      // enterShop();
      break;
    case 5:
      // chat();
      break;
    case 6:
      // QUIT
      run = false;
    }
  }
}
