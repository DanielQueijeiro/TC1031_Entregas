// Daniel Queijeiro Albo A01710441
// Avance 2
#include <fstream>
#include <iostream>
#include <vector>
#include "List.h"
#include "Menu.h"
#include "Product.h"
#include "Sorts.h"

using namespace std;


int main() {
  bool menu = true;

  vector<Product> inventory;
  Sorts data;
  List<Product> list;

  while (menu) {
    string role = startMenu();
    optionMenu(list, data, inventory, role);
  }
}