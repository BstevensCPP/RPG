// Pre-Processor Operations
#pragma once
#include "Charecter.h"
#include "Enemy.h"
#include "EnterBattle.h"
#include "SelectionList.h"
#include <ios>
#include <iostream>
#include <limits>

using namespace std;

void startMenu(Player *user) {

  // Variables
  bool quit = false;
  const int size = 6;
  string options[size] = {"Return to Game",   "Enter Battle",
                          "Manage Inventory", "Enter Shop",
                          "Talke to Someone", "Quit Game"};

  // Display menu until user quits
  while (true) {
    switch (selectionList(options, size, 0)) {
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
      quit = true;
    }
    if (quit)
      break;
  }
}
