#pragma once
#include "Charecter.h"
#include <cstdlib>
#include <ctime>
#include <limits>

class Enemy : public Charecter {
protected:
  int bounty;

public:
  bool alive = true;
  Enemy(string name, int hp, int def, int spd, int atk, int lvl, int min,
        int max)
      : Charecter(name, hp, def, spd, atk, lvl) {
    srand(time(0));
    this->bounty = min + rand() % (max - min + 1);
  }

  void takeTurn(Player *user) {
    srand(time(0));
    switch (1 + rand() % (10)) {
    case 1:
    case 2:
    case 3:
    case 4:
      // Attack
      user->takeHit(getAttack());
      break;
    case 5:
    case 6:
    case 7:
      // Defend
      buffDefence(8);
      break;
    case 8:
    case 9:
    case 10:
      cout << "\n" << this->name << " ran away!\n" << endl;
      cout << "\n - - Press Enter to Continue - - \n";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();

      alive = false;
      // Run

      break;
    default:
      cout << "what?\n";
    }

    cout << "\nEnemy took turn!\n";
  }
};

class Cog : public Enemy {
public:
  Cog(int lvl) : Enemy("Cog", 40, 20, 30, 5, lvl, 500, 1000) {}
};
class ManOfWar : public Enemy {
public:
  ManOfWar(int lvl) : Enemy("Man of War", 50, 30, 5, 20, lvl, 2000, 3000) {}
};
class Brig : public Enemy {
public:
  Brig(int lvl) : Enemy("Brig", 50, 15, 20, 10, lvl, 1000, 2000) {}
};
