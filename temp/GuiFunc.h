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
