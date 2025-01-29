#pragma once
#include "Charecter.h"
#include "Enemy.h"
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>

using namespace std;

void EnterBattle(Player *user) {
  srand(time(0));
  Enemy *enemy;
  int option;
  bool quit = false;

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
    cout << "what?\n";
  }

  cout << "\nA wild " << enemy->getName() << " Appeared!\n";
  cout << "\n - - Press Enter to Continue - - \n";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();

  if (system("cls"))
    system("clear");
  if (enemy->getSpeed() > user->getSpeed())
    enemy->takeTurn(user);

  while (true) {
    if (!(enemy->alive)) {
      delete enemy;
      if (system("cls"))
        system("clear");
      break;
    }
    try {
      cout << "- - - - - - - - - -";
      user->displayStats();
      cout << "\n- - - - vs. - - - -\n";
      enemy->displayStats();
      cout << "- - - - - - - - - -\n\n";
      /* List Options */

      cout << "1. Attack\n"
           << "2. Defend\n"
           << "3. Run\n"
           << "\nAnswer: ";

      /* Get Answer - Throw ERROR 0 if invalid */
      if (!(cin >> option))
        throw(0);
      if (system("cls"))
        system("clear");
      /* Run chosen function - Throw ERROR 1 if not found */
      switch (option) {
      case 1:
        // Attack
        enemy->takeHit(user->getAttack());
        break;
      case 2:
        // Defend
        user->buffDefence(8);
        break;
      case 3:
        // Run
        cout << "\nYou successfully escaped!\n" << endl;
        quit = true;
        break;
      default:
        throw(1);
      }

      if (quit) {
        if (system("cls"))
          system("clear");
        break;
      }

      enemy->takeTurn(user);
    } catch (int e) {

      /* Clear input stream */
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      /* Display ERROR */
      switch (e) {
      case 0:
        cout << "\n\nNUMBERS ONLY!!!\n";
        break;
      case 1:
        cout << "\n\nNUMBER OUT OF RANGE!!!\n";
        break;
      }
    }
  }
}
