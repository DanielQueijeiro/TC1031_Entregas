#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
  string name;
  int quantity;
  float price;

public:
  Product(string, int, float);
  void addProduct(string, int, float);
  string getName();
  int getQuantity();
  float getPrice();
  void getInfo();
  void setPrice(float);
  void setQuantity(int);
};

//Creates a Product variable
//Complexity O(1)
//@param string, int, float
//@return Product
Product::Product(string _name, int _quantity, float _price) {
  name = _name;
  quantity = _quantity;
  price = _price;
}

//Returns the name of the Product
//Complexity O(1)
//@param 
//@return string
string Product::getName() { return name; }

//Returns the quantity of the Product
//Complexity O(1)
//@param 
//@return int
int Product::getQuantity() { return quantity; }

//Returns the price of the Product
//Complexity O(1)
//@param 
//@return float
float Product::getPrice() { return price; }

//Prints the name, price and quantity of the Product
//Complexity O(1)
//@param 
//@return void
void Product::getInfo(){
  cout << getName() << endl;
  cout << "Price: $" << getPrice() << endl;
  cout << "Quantity: " << getQuantity() << endl;
}

//Modifies the price of the Product
//Complexity O(1)
//@param float
//@return void
void Product::setPrice(float _price) { price = _price; }

//Modifies the quantity of the Product
//Complexity O(1)
//@param int
//@return void
void Product::setQuantity(int _quantity) {quantity = _quantity;}
#endif