// Pre-Processor Operations
#pragma once
#include <iostream>
#include <limits>

using namespace std;

int selectionList(string *list, int size, int style) {
  int option;

  while (true) {
    try {

      /* List Options */
      for (int row = 0; row < size; row++)
        cout << row + 1 << ". " << list[row] << endl;
      cout << "\nAnswer: ";

      /* Check for ERRORs */
      if (!(cin >> option))
        throw(0);
      if (1 > option || option > size)
        throw(1);

      /* Clear Screen */
      if (system("cls"))
        system("clear");

      break;
    } catch (int e) {

      /* Clear input stream */
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      /* Clear Screen */
      if (system("cls"))
        system("clear");

      /* Display ERROR */
      switch (e) {
      case 0:
        cout << "NUMBERS ONLY!!!\n";
        break;
      case 1:
        cout << "NUMBER OUT OF RANGE!!!\n";
        break;
      }

      // If Non-Repeating on ERROR
      if (style == 1) {
        if (system("cls"))
          system("clear");
        return 0;
      }
    }
  }
  return option;
}
