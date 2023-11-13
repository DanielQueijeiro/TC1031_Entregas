#ifndef SORTS_H_
#define SORTS_H_
#include "Product.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Sorts {
private:
  void swap(vector<Product> &, int, int);

public:
  void checkFile();
  vector<Product> loadData(const string &);
  vector<Product> insertionSort(vector<Product> &, int);
  void writeData(vector<Product>);
  void clearData(vector <Product>);
  void getProduct(string, vector<Product>);
};

//Customer and administrator function
//Checks that an inventory csv file exists and if it does not exist, creates it.
//Complexity O(1)
//@param 
//@return void
void Sorts::checkFile() {
  ifstream infile("Inventory.csv");
  if (!infile.is_open()) {
    // The file does not exist, so create it.
    ofstream outfile("Inventory.csv");

    // Write the header row to the CSV file.
    outfile << "Name,Quantity,Price";

    // Close the CSV file.
    outfile.close();
    cout << "No inventory file found, a blank one has been created" << endl;
  }
}

//Customer and administrator function
//Reads inventory csv data and saves it in a vector<Product>.
//Complexity O(n)
//@param string
//@return vector<Product>
vector<Product> Sorts::loadData(const string &file) {
  ifstream File(file);
  string skipline;
  string name;
  int quantity;
  float price;
  vector<Product> inventory;

  if (File.is_open()) {
    getline(File, skipline);
    string temp;
    while (File.good()) {
      getline(File, name, ',');

      getline(File, temp, ',');
      quantity = stoi(temp);

      getline(File, temp, '\n');
      price = stof(temp);

      Product aux(name, quantity, price);
      inventory.push_back(aux);
    }
  }
  File.close();
  return inventory;
}

//Administrator function
//Write inventory vector<Product> to a csv
//Complexity O(n)
//@param vector<Product>
//@return void
void Sorts::writeData(vector<Product> inventory){
  ofstream outfile("Inventory.csv");

    // Write the header row to the CSV file.
    outfile << "Name,Quantity,Price" << endl;
    for (int i = 0; i < inventory.size(); i++){
      if (i == inventory.size() - 1){
        outfile << inventory[i].getName() << ",";
        outfile << inventory[i].getQuantity() << ",";
        outfile << inventory[i].getPrice();
      } else {
        outfile << inventory[i].getName() << ",";
        outfile << inventory[i].getQuantity() << ",";
        outfile << inventory[i].getPrice() << endl;
      }
    }
}

//Administrator function
//Vaid the inventory vector<Product>.
//Complexity O(1)
//@param vector<Product>
//@return void 
void Sorts::clearData(vector<Product> inventory){
    ofstream outfile("Inventory.csv");
    outfile << "Name,Quantity,Price";
}

//Administrator function
//Serves for insertionSort function
//Complexity O(1)
//@param vector<Product>, int, int
//@return void
void Sorts::swap(vector<Product> &v, int i, int j) {
  Product aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}
//Administrator function 
//Algorithm for sorting insertion sort
//Complexity O(n^2)
//@param vector<Product>, int
//@return vector<Product>
vector<Product> Sorts::insertionSort(vector<Product> &v, int choice) {
  switch (choice) {
  case 1:
    for (int i = 1; i < v.size(); i++) {
      for (int j = i; j > 0 && v[j].getQuantity() < v[j - 1].getQuantity();
           j--) {
        swap(v, j, j - 1);
      }
    }
    return v;

  case 2:
    for (int i = 1; i < v.size(); i++) {
      for (int j = i; j > 0 && v[j].getPrice() < v[j - 1].getPrice(); j--) {
        swap(v, j, j - 1);
      }
    }
    return v;
  }
  return v;
}

//Administrator function 
//Find object based on parameter string and print its information
//Complexity O(n)
//@param string, vector<Product>
//@return void
void Sorts::getProduct(string search, vector<Product> inventory){
  for (int i = 0; i < inventory.size(); i++){
    string product = inventory[i].getName();   
    for (auto& x : product) {
      x = tolower(x);
    }
    if (product == search || inventory[i].getName() == search){
      inventory[i].getInfo();
    }
  }
}

#endif