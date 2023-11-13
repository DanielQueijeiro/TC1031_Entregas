#ifndef MENU_H_
#define MENU_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Functions.h"
#include "Product.h"
#include "Sorts.h"
#include "List.h"
using namespace std;


//Shows to the user what the program can do
//Complexity O(n)
//@param List<Product>, Sorts, vector<Product>, string
//@return void
void optionMenu(List<Product> list, Sorts data, vector<Product> inventory, string role) {
  int aux = 0;
  data.checkFile();
  inventory = data.loadData("Inventory.csv");
  if(role == "administrator"){
    cout << "1. Show entire inventory" << endl;
    cout << "2. Search for a product" << endl;
    cout << "3. Add product to inventory" << endl;
    cout << "4. Erase product from inventory" << endl;
    cout << "5. Update a product" << endl;
    cout << "6. Clear inventory" << endl;
    cout << "7. Exit" << endl;
    cin >> aux;
  
    switch (aux) {
    case 1: {
      if (inventory.size() == 0) {
        cout << "No products registered" << endl;
        optionMenu(list, data, inventory, role);
      } else {
        cout << "1. Show the inventory in the order it was logged" << endl;
        cout << "2. Show the inventory sorted by price" << endl;
        cout << "3. Show the inventory sorted by quantity" << endl;
        cout << "4. Return" << endl;
        cin >> aux;
  
        if (aux == 1) {
          for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i].getName() != "") {
              cout << i + 1 << ") ";
              inventory[i].getInfo();
              cout << endl;
            }
          }
        }
  
        if (aux == 2) {
          data.insertionSort(inventory, 2);
          for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i].getName() != "") {
              cout << i + 1 << ") ";
              inventory[i].getInfo();
              cout << endl;
            }
          }
        }
  
        if (aux == 3) {
          data.insertionSort(inventory, 1);
          for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i].getName() != "") {
              cout << i + 1 << ") ";
              inventory[i].getInfo();
              cout << endl;
            }
          }
        }
        optionMenu(list, data, inventory, role);
      }
    }
  
    case 2: {
      if (inventory.size() != 0) {
        string search;
        cout << "Please type the product to search" << endl;
        cin >> search;
        data.getProduct(search, inventory);
        cout << endl;
        optionMenu(list, data, inventory, role);
      } else {
        cout << "No products registered" << endl;
        optionMenu(list, data, inventory, role);
      }
    }
  
    case 3: {
      string name;
      int quantity = 0;
      float price = 0;
      cout << "Please insert the data of the product" << endl;
      cout << "Name of the product: " << endl;
      cin >> name;
      cout << "Quantity of the product: " << endl;
      cin >> quantity;
      cout << "Price of the product: " << endl;
      cin >> price;
      addData(name, quantity, price);
      optionMenu(list, data, inventory, role);
    }
    case 4: {
      string product;
      cout << "Please type the product you wish to delete" << endl;
      cin >> product;
      eraseProduct(data, inventory, product);
      optionMenu(list, data, inventory, role);
    }
  
    case 5: {
      string product;
      int choice;
      cout << "Please type the product you wish to modify" << endl;
      cin >> product;
      cout << "What do you want to modify?" << endl;
      cout << "1. Name" << endl;
      cout << "2. Quantity" << endl;
      cout << "3. Price" << endl;
      cin >> choice;
      modifyData(data, inventory, product, choice);
      optionMenu(list, data, inventory, role);
    }
  
    case 6: {
      data.clearData(inventory);
      cout << "The inventory has been cleared" << endl;
      optionMenu(list, data, inventory, role);
    }
      
    case 7: {
      cout << "Thanks for using the manager system!" << endl;
      exit(0);
    }
    }
  }
    
  else if (role == "client"){
    if(list.empty()){
      cout << "You currently do not have a shopping list" << endl;
      createList(list, inventory);
    }
    else{
      navigateList(list);
      createFile(list);
      exit(0);
    }
    optionMenu(list, data, inventory, role);
  }
}

//Begins the menu and asks the user's role.
//Complexity O(n)
//@param 
//@return string
string startMenu() {
  string role = "";
  cout << "Welcome, are you a client or an administrator?" << endl;
  cin >> role;
  for (auto &x : role) {
    x = tolower(x);
  }
  return role;
}

#endif