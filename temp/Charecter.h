#pragma once
#include <iostream>

using namespace std;

class Charecter {
protected:
  string name;
  int hp;
  int def;
  int spd;
  int atk;
  int defBuff = 0;
  int lvl = 1;

public:
  Charecter(string name, int hp, int def, int spd, int atk, int lvl) {
    this->name = name;
    this->hp = hp + lvl - 1;
    this->def = def + lvl - 1;
    this->spd = spd + lvl - 1;
    this->atk = atk + lvl - 1;
    this->lvl = lvl;
  }

  void displayStats() {
    cout << "\n\t" << name << "\n\thp: " << hp << "\n\tdef: " << def
         << "\n\tspd: " << spd << "\n\tatk: " << atk << endl;
  }

  int getHp() { return hp; }
  int getDefence() { return def + defBuff; }
  int getSpeed() { return spd; }
  int getAttack() { return atk; }
  string getName() { return name; }

  void buffDefence(int x) { defBuff += x; }
  void clearBuff() { defBuff = 0; }

  void takeHit(int val) {
    val -= this->getDefence() * 0.25;
    if (val < 0)
      val = 0;
    this->hp -= val;

    cout << "\n" << this->name << " took " << val << " Damage!\n";
  }

  void levelUp() {
    hp += 1;
    def += 1;
    spd += 1;
    atk += 1;
  }
  virtual ~Charecter() {};
};

class Player : public Charecter {
public:
  Player() : Charecter("Player", 50, 15, 20, 10, 1) {};
};
