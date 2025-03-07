// Pre-Processor Operations
#pragma once
#include "GuiFunc.h"
#include <iostream>
#include <limits>

using namespace std;

class Charecter {
protected:
  // Stats
  string name;
  int hp;
  int def;
  int spd;
  int atk;
  int defBuff = 0;
  int lvl = 1;

public:
  bool alive = true;

  // Constructor
  Charecter(string name, int hp, int def, int spd, int atk, int lvl) {
    this->name = name;
    this->hp = hp + lvl - 1;
    this->def = def + lvl - 1;
    this->spd = spd + lvl - 1;
    this->atk = atk + lvl - 1;
    this->lvl = lvl;
  }

  // Used to display stats durring battle
  virtual void displayStats() {
    cout << "\n\t" << name << "\n\thp: " << hp << "\n\tdef: " << def
         << "\n\tspd: " << spd << "\n\tatk: " << atk << endl;
  }

  // Used to get values durring battle
  int getHp() { return hp; }
  int getDefence() { return def + defBuff; }
  int getSpeed() { return spd; }
  int getAttack() { return atk; }
  string getName() { return name; }

  // Buffing defence reduces damage by 2
  void buffDefence(int x) {
    defBuff += x;

    cout << endl << this->getName() << " Armored up!\n";
    pause();
    clearScreen();
  }

  // Gets attack damage from other Charecter and reduces it based off defence
  void takeHit(int val) {
    val -= this->getDefence() * 0.25;
    if (val < 0)
      val = 0;
    this->hp -= val;

    cout << "\n" << this->name << " took " << val << " Damage!\n";
    pause();
    if (this->hp <= 0) {
      clearScreen();
      cout << endl << this->getName() << " HAS DIED!!!\n";
      this->alive = false;
      pause();
    }
    clearScreen();
  }
  // Deconstructor
  virtual ~Charecter() {};
};

// Player is type of Charecter with predefined stats
class Player : public Charecter {
  int xp = 0;

public:
  Player() : Charecter("Player", 50, 15, 20, 15, 1) {};

  void levelUp() {
    lvl += 1;
    hp += 1;
    def += 1;
    spd += 1;
    atk += 1;

    clearScreen();
    cout << "\nLEVEL UP!!!" << endl;
    pause();
    clearScreen();
  }

  void gainXp(int xp) {
    this->xp += xp;
    int ceiling = 50 * (1 + 0.1 * (this->lvl - 1));
    if (this->xp >= ceiling) {
      this->xp -= ceiling;
      levelUp();
    }
  }

  void clearBuff() { defBuff = 0; }

  void displayStats() override {
    Charecter::displayStats();

    cout << "\txp: " << this->xp << endl;
  }
};
