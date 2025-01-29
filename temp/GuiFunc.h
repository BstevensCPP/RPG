#pragma once
#include <iostream>
#include <limits>

void clearScreen() {
  if (system("cls"))
    system("clear");
}
void clearStream() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pause() {
  std::cout << "\n - - Press Enter to Continue - - \n";
  clearStream();
  std::cin.get();
}
