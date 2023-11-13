// Daniel Queijeiro Albo A01710441

#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include "exception.h"
#include "Product.h"

template <class T> class List;

template <class T> class Link {
private:
  Link(T);
  Link(T, Link<T> *);
  Link(const Link<T> &);

  T value;
  Link<T> *next;

  friend class List<T>;
};

template <class T> Link<T>::Link(T val) : value(val), next(NULL){}

template <class T> Link<T>::Link(T val, Link *nxt) {
  value = val;
  next = nxt;
}

template <class T> Link<T>::Link(const Link<T> &source) {
  value = source.value;
  next = source.next;
}

template <class T> class List {
public:
  List();
  ~List();

  int getSize() const;
  void insertionFirst(T);
  void insertion(T);
  T removeFirst();
  T deleteAt(int);
  T update(int, T);
  T searchIndex(int) const;
  T search(int) const;
  bool empty() const;
  void clear();
  float getPrice(int);
  std::string toStringName() const;
  std::string toStringInfo() const;
  std::string singleToString(int) const;
  std::string singleToStringFile(int) const;

private:
  Link<T> *head;
  int size;
};

template <class T> List<T>::List() {
  size = 0;
  head = NULL;
}

template <class T> List<T>::~List() { clear(); }
 
//Regresses size of the bound list
//Complexity O(1)
//@param 
//@return int 
template <class T>
int List<T>::getSize() const {  return size;}

//Checks if the list is empty
//Complexity O(1)
//@param 
//@return bool
template <class T> bool List<T>::empty() const {
  if (size == 0) {
    return true;
  }
  return false;
}

//Adds an element to the list in its first link
//Complexity O(1)
//@param T
//@return void
template <class T> void List<T>::insertionFirst(T val) {

  Link<T> *nuevo_nodo = new Link<T>(val);
  if (nuevo_nodo == NULL) {
    throw OutOfMemory();
  }

  nuevo_nodo->next = head;
  head = nuevo_nodo;
  size++;
}

//Adds an element to the list
//Complexity O(1)
//@param T
//@return void
template <class T> void List<T>::insertion(T val) {

  if (empty()) {
    insertionFirst(val);
  } else {
    Link<T> *nuevo_nodo = new Link<T>(val);
    if (nuevo_nodo == NULL) {
      throw OutOfMemory();
    }

    Link<T> *nodo_actual = head;
    while (nodo_actual->next != NULL) {
      nodo_actual = nodo_actual->next;
    }
    nodo_actual->next = nuevo_nodo;
    size++;
  }
}

//Removes an item from the list
//Complexity O(1)
//@param int
//@return <T>
template <class T> T List<T>::deleteAt(int index) {
  Link<T> *victima = head;
  Link<T> *aux = head;
  // When deleting the first node
  if (index == 0) {
    T result = head->value;
    result = removeFirst();
    return result;
  }

  while (victima->value != searchIndex(index)) {
    victima = victima->next;
  }
  while (aux->value != searchIndex(index - 1)) {
    aux = aux->next;
  }

  aux->next = victima->next;

  victima->next = NULL;

  T result = victima->value;

  delete victima;

  size--;
  return result;
}

//Removes the first element from the list
//Complexity O(1)
//@param 
//@return <T>
template <class T> T List<T>::removeFirst() {
  if (empty()) {
    throw NoSuchElement();
  }

  Link<T> *victima = head;
  head = victima->next;
  victima->next = NULL;

  T result = victima->value;

  delete victima;

  size--;
  return result;
}

//Changes the value of a list node
//Complexity O(1)
//@param int, T
//@return <T>
template <class T> T List<T>::update(int index, T value) {
  if (index < 0 || index >= size) {
    throw IndexOutOfBounds();
  }

  Link<T> *nodo_actual = head;
  for (unsigned int i = 0; i < index; i++) {
    nodo_actual = nodo_actual->next;
  }
  nodo_actual->value = value;
  return nodo_actual->value;
}

//Regresses the value of the node to be searched from the list
//Complexity O(n)
//@param int
//@return <T>
template <class T> T List<T>::searchIndex(int index) const {
  if (index < 0 || index >= size) {
    throw IndexOutOfBounds();
  }

  Link<T> *nodo_actual = head;

  for (unsigned int i = 0; i < index; i++) {
    nodo_actual = nodo_actual->next;
  }
  return nodo_actual->value;
}

//Find a value within the list
//Complexity O(n)
//@param int
//@return int
template <class T> T List<T>::search(int value) const {

  Link<T> *nodo_actual = head;

  for (unsigned int i = 0; i < size; i++) {
    if (nodo_actual->value == value) {
      return i;
    }
    nodo_actual = nodo_actual->next;
  }
  return -1;
}

//Clears a list
//Complexity O(n)
//@param 
//@return void
template <class T> void List<T>::clear() {
  while (!empty()) {
    removeFirst();
  }
}

//Regresses the value of a node in the list
//Complexity O(n)
//@param int
//@return float
template <class T>
float List<T>::getPrice(int index) {
  Link<T>* p = head; 
  for(int i = 0; i < index; i++){
    if (p == nullptr){ throw NoSuchElement();}
    p = p->next;
  }
  return p->value.getPrice();
}

//Turns the list's elements into a string
//Complexity O(n)
//@param 
//@return string
template <class T>
std::string List<T>::toStringInfo() const {
    std::stringstream aux;
    Link<T>* p;

    p = head;
    aux << "[";
    while (p != nullptr) {
      aux << "(";
      aux << p->value.getName() << "\t";
      aux << "Price: " << p->value.getPrice() << "\t";
      aux << "Quantity: " << p->value.getQuantity();
      aux << ")" << endl;
        if (p->next != nullptr) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

//Returns the name of each list element
//Complexity O(n)
//@param 
//@return string
template <class T>
std::string List<T>::toStringName() const {
    std::stringstream aux;
    Link<T>* p;

    p = head;
    aux << "[";
    while (p != nullptr) {
        aux << p->value.getName();
        if (p->next != nullptr) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

//Returns the information of a single element of the list
//Complexity O(n)
//@param int
//@return string
template <class T>
std::string List<T>::singleToString(int index) const {
    std::stringstream aux;
    Link<T>* p;

    p = head;
    for(int i = 0; i < index; i++){
      if (p == nullptr){ throw NoSuchElement();}
      p = p->next;
    }
    aux << "[";
    aux << p->value.getName() << "\t";
    aux << "Price: " << p->value.getPrice() << "\t";
    aux << "Quantity: " << p->value.getQuantity();
    aux << "]";
    return aux.str();
}

//Returns the name and price of each element in the list
//Complexity O(n)
//@param int
//@return string
template <class T>
std::string List<T>::singleToStringFile(int index) const {
    std::stringstream aux;
    Link<T>* p;

    p = head;
    for(int i = 0; i < index; i++){
      if (p == nullptr){ throw NoSuchElement();}
      p = p->next;
    }
    aux << "[";
    aux << p->value.getName() << "\t";
    aux << "Price: " << p->value.getPrice() << "\t";
    aux << "]";
    return aux.str();
}

#endif /* LIST_H_ */