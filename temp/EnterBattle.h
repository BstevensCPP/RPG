// Pre-Processor Operations
#pragma once
#include "Charecter.h"
#include "Enemy.h"
#include "SelectionList.h"
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>

using namespace std;

void EnterBattle(Player *user) {

  // Seed random & declare vaiables
  srand(time(0));
  Enemy *enemy;
  int option;
  bool quit = false;
  const int size = 3;
  string options[size] = {"Attack", "Defend", "Run"};

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
  default:
    // I don't know how this would ever happen and I would be baffled if it did
    cout << "what?\n";
  }

  // Shows what enemy the player is facing
  cout << "\nA wild " << enemy->getName() << " Appeared!\n";
  cout << "\n - - Press Enter to Continue - - \n";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();

  /* Clear Screen */
  if (system("cls"))
    system("clear");

  /* The fastest person goes first */
  if (enemy->getSpeed() > user->getSpeed())
    enemy->takeTurn(user);

  // Display battle until it ends
  while (true) {

    // If the enemy is dead then delete the enemy
    if (!(enemy->alive)) {
      delete enemy;
      if (system("cls"))
        system("clear");
      break;
    }

    // Displays Battle
    cout << "- - - - - - - - - -";
    user->displayStats();
    cout << "\n- - - - vs. - - - -\n";
    enemy->displayStats();
    cout << "- - - - - - - - - -\n\n";

    // What did the player choose and option 0 is if an ERROR is thrown
    switch (selectionList(options, size, 1)) {
    case 0:
      break;
    case 1:
      // Attack
      enemy->takeHit(user->getAttack());

      // If Enemy's health is 0 then it DIES
      if (enemy->getHp() <= 0) {
        cout << "\n ENEMY HAS DIED!!!\n";
        enemy->alive = false;
        cout << "\n - - Press Enter to Continue - - \n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
      }
      break;
    case 2:
      // Defend
      user->buffDefence(8);
      break;
    case 3:
      // Run
      cout << "\nYou successfully escaped!\n" << endl;
      quit = true;
    }
    if (quit)
      break;

    // Enemies turn
    enemy->takeTurn(user);
  }
}
