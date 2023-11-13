#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Product.h"
#include "Sorts.h"
#include "List.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Administrator function
//Function to add a product to the inventory csv
//Complexity O(1)
//@param string, int, float
//@return void
void addData(string name, int quantity, float price) {
  // Open the CSV file in append mode.
  ofstream File("Inventory.csv", ios::app);

  // Write the new data to the file.
  File << endl << name << "," << quantity << "," << price;

  // Close the file.
  File.close();
}

//Administrator function
//Function for removing a product from the inventory vector
//Complexity O(n)
//@param Sorts, vector<Product>, string
//@return void
void eraseProduct(Sorts data, vector<Product> inventory, string victim) {
  for (int i = 0; i < inventory.size(); i++) {
    string lowercase = inventory[i].getName();
    for (auto &x : lowercase) {
      x = tolower(x);
    }
    if (lowercase == victim || inventory[i].getName() == victim) {
      inventory.erase(inventory.begin() + i);
    }
  }
  data.writeData(inventory);
}

//Administrator function
//Function to modify a product of the inventory vector
//Complexity O(n)
//@param Sorts, vector<Product>, string
//@return void
void modifyData(Sorts data, vector<Product> inventory, string victim, int choice) {
  if (choice == 1) {
    string newName;
    cout << "Please type the new name" << endl;
    cin >> newName;
    for (int i = 0; i < inventory.size(); i++) {
      string lowercase = inventory[i].getName();
      for (auto &x : lowercase) {
        x = tolower(x);
      }
      if (lowercase == victim || inventory[i].getName() == victim) {
        int auxq = inventory[i].getQuantity();
        float auxp = inventory[i].getPrice();
        Product aux(newName, auxq, auxp);
        inventory[i] = aux;
      }
    }
  }

  if (choice == 2) {
    int newQuantity;
    cout << "Please type the new quantity" << endl;
    cin >> newQuantity;
    for (int i = 0; i < inventory.size(); i++) {
      string lowercase = inventory[i].getName();
      for (auto &x : lowercase) {
        x = tolower(x);
      }
      if (lowercase == victim || inventory[i].getName() == victim) {
        string auxn = inventory[i].getName();
        float auxp = inventory[i].getPrice();
        Product aux(auxn, newQuantity, auxp);
        inventory[i] = aux;
      }
    }
  }
  if (choice == 3) {
    float newPrice;
    cout << "Please type the new quantity" << endl;
    cin >> newPrice;
    for (int i = 0; i < inventory.size(); i++) {
      string lowercase = inventory[i].getName();
      for (auto &x : lowercase) {
        x = tolower(x);
      }
      if (lowercase == victim || inventory[i].getName() == victim) {
        string auxn = inventory[i].getName();
        float auxq = inventory[i].getQuantity();
        Product aux(auxn, auxq, newPrice);
        inventory[i] = aux;
      }
    }
  }
  data.writeData(inventory);
}

//Customer function
//Displays the inventory vector and creates shopping list for the customer to select the products
//Complexity O(n)
//@param List<Product>, vector<Product>
//@return void
void createList(List<Product> &list, vector<Product> inventory){ 
  int auxItem = 0;
  float auxPrice = 0;
  bool exit = false;
  while (!exit){
    cout << "Store's available products" << endl;
    for(int i = 0; i < inventory.size(); i++){
      cout << i + 1 << ") " << inventory[i].getName() << endl;
    }
    cout << "Current shopping list: " << endl;
    cout << list.toStringName() << endl;
    cout << "Current bill: $" << auxPrice << endl;
    
    cout << "Please select the items that you wish to add to your shopping list" << endl;
    cout << "Or if you have completed your shopping list, please type -1" << endl;
    cin >> auxItem;
    if(auxItem == -1){
      exit = true;
    }
    else if(auxItem == 0 || auxItem > inventory.size()){ cout << "That product does not exist" << endl; }
    else{
      list.insertion(inventory[auxItem - 1]);
      cout << "Item added succesfully" << endl;
      auxPrice += inventory[auxItem - 1].getPrice();
    }
  }
}

//Customer function
//Displays the list created by the client and allows you to browse the list.
//Complexity O(n)
//@param List<Product>
//@return void
void navigateList(List<Product> &list){
  int auxIndex = 0;
  int auxNavigate = 0;
  bool exit = false;
  
  cout << endl << "Detailed view of shopping list" << endl;
  while(!exit){
    if (auxIndex >= list.getSize()){
      cout << "You have reached the end of the shopping list" << endl;
      auxIndex--;
    }
    else if(auxIndex == 0){
      cout << auxIndex + 1 << "° item: " << endl;
      cout << list.singleToString(auxIndex) << endl;
      cout << "Type 1 to continue to the next item" << endl;
      cout << "Type -1 to create a file containing the shopping list and exit" << endl;
      cin >> auxNavigate;
      if(auxNavigate == -1){ exit = true;}
      auxIndex++;
    }
    else{
      cout << endl << "Current shopping list: " << endl;
      cout << list.toStringName() << endl;
      //cout << "Total bill: $" << auxPrice << endl;
      cout << auxIndex + 1 << "° item: " << endl;
      cout << list.singleToString(auxIndex) << endl;
      cout << "Type 1 to continue to the next item" << endl;
      cout << "Type 0 to continue to the previous item" << endl;
      cout << "Type -1 to create a file containing the shopping list and exit" << endl;
      cin >> auxNavigate;
      if(auxNavigate == -1){ exit = true;}
      else if(auxNavigate == 1){ auxIndex++;}
      else if(auxNavigate == 0){ auxIndex--;}
    }
  }   
}

//Customer function
//Create txt file with customer's purchase list
//Complexity O(n)
//@param List<Product>
//@return void
void createFile(List<Product> &list) {
  int auxIndex = 0;
  float auxPrice = 0;
  ofstream outputFile("ShoppingList.txt");
    if (outputFile.is_open()) {
      while(auxIndex < list.getSize()){
        // Write some text into the file
        outputFile << list.singleToStringFile(auxIndex) << endl;
        auxPrice += list.getPrice(auxIndex);
        auxIndex++;
      }
      outputFile << "Total bill: $" << auxPrice;
      // Close the file
      outputFile.close();
      cout << "The list has been created succesfully." << endl;
    }
}
#endif