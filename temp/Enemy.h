// Pre-Processor operations
#pragma once
#include "Charecter.h"
#include <cstdlib>
#include <ctime>
#include <limits>

// Enemy is type of Charecter
class Enemy : public Charecter {
protected:
  // Enemys have bountys duh
  int bounty;

public:
  // Constructor
  Enemy(string name, int hp, int def, int spd, int atk, int lvl, int min,
        int max)
      : Charecter(name, hp, def, spd, atk, lvl) {

    // Generate Bounty Size
    srand(time(0));
    this->bounty = min + rand() % (max - min + 1);
  }

  // Enemy needs address of player to do damage
  void takeTurn(Player *user) {
    srand(time(0));
    switch (1 + rand() % (9)) {
    // 40% chance to attack
    case 1:
    case 2:
    case 3:
    case 4:
      // Attack
      user->takeHit(getAttack());
      break;
    // 30% chance to buff defence
    case 5:
    case 6:
    case 7:
      // Defend
      buffDefence(8);
      cout << endl << this->name << " Armored Up!\n" << endl;
      break;
    // 20% chance to run
    case 8:
    case 9:
      // Run
      cout << "\n" << this->name << " ran away!\n";
      cout << "\n - - Press Enter to Continue - - \n";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
      alive = false;
      break;
    default:
      cout << "what?\n";
    }
  }
};

// Enemy 1 : Cog
class Cog : public Enemy {
public:
  Cog(int lvl) : Enemy("Cog", 40, 20, 30, 5, lvl, 500, 1000) {}
};

// Enemy 2 : Man of War
class ManOfWar : public Enemy {
public:
  ManOfWar(int lvl) : Enemy("Man of War", 50, 30, 5, 20, lvl, 2000, 3000) {}
};

// Enemy 3 : Brig
class Brig : public Enemy {
public:
  Brig(int lvl) : Enemy("Brig", 50, 15, 20, 10, lvl, 1000, 2000) {}
};
