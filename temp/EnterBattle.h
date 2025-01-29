// Pre-Processor Operations
#pragma once
#include "Charecter.h"
#include "Enemy.h"
#include "GuiFunc.h"
#include "SelectionList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void EnterBattle(Player *user) {

  // Declare vaiables
  Enemy *enemy;
  bool run = true;
  string options[] = {"Attack", "Defend", "Run"};

  srand(time(0));
  // 33% To Choose One of Three Enemies
  switch (1 + rand() % (3)) {
  case 1:
    enemy = new Cog(1);
    break;
  case 2:
    enemy = new ManOfWar(1);
    break;
  case 3:
    enemy = new Brig(1);
    break;
  }

  // Shows what enemy the player is facing
  cout << "\nA wild " << enemy->getName() << " Appeared!\n";
  pause();
  clearScreen();

  /* The fastest person goes first */
  if (enemy->getSpeed() > user->getSpeed())
    enemy->takeTurn(user);

  // Display battle until it ends
  while (run) {

    // If the enemy is dead then delete the enemy
    if (!(enemy->alive) || !(user->alive)) {
      delete enemy;
      clearScreen();
      run = false;
      break;
    }

    // Displays Battle
    cout << "- - - - - - - - - -";
    user->displayStats();
    cout << "\n- - - - vs. - - - -\n";
    enemy->displayStats();
    cout << "- - - - - - - - - -\n\n";

    // What did the player choose and option 0 is if an ERROR is thrown
    switch (selectionList(options, sizeof(options) / sizeof(options[0]), 1)) {
    case 0:
      break;
    case 1:
      // Attack
      enemy->takeHit(user->getAttack());

      if (enemy->alive)
        enemy->takeTurn(user);
      break;
    case 2:
      // Defend
      user->buffDefence(8);
      enemy->takeTurn(user);
      break;
    case 3:
      // Run
      cout << "\nYou successfully escaped!\n" << endl;
      run = false;
    }
  }
}
