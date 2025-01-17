#pragma once
#include <ios>
#include <iostream>
#include <limits>

using namespace std;

void startMenu(){
  int option;

  while(true){
    try{

      /* List Options */
      cout
        << "1. Return to Game\n"
        << "2. Enter Battle\n"
        << "3. Manage Inventory\n"
        << "4. Enter Shop\n"
        << "5. Talk to Someone\n"
        << "6. Quit Game\n"
        << "\nAnswer: ";

      /* Get Answer - Throw ERROR 0 if invalid */
      if(!(cin >> option)) throw(0);

      /* Run chosen function - Throw ERROR 1 if not found */
      switch(option){
        case 1:
          //returnToOverworld();
          break;
        case 2:
          //enterBattle();
          break;
        case 3:
          //manageInventory();
          break;
        case 4:
          //enterShop();
          break;
        case 5:
          //chat();
          break;
        case 6:
          //quitGame();
          break;
        default:
          throw(1);
      }
      break;
    }
    catch(int e){

      /* Clear input stream */
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      /* Display ERROR */
      switch(e){
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
