#include "cell.h"
#include <string>
#include <memory>
using namespace std;

Cell::Cell( const string & str , bool value_set ) : 
    value{ str }, valueSet{ value_set } { }

Cell::~Cell(){}
string Cell::getValue() const {
  if ( valueSet == true ) {
    return value; 
  } else {
    return " ";
  }
}

shared_ptr<Cell> Cell::getLeft(){
  return left;
}

shared_ptr<Cell> Cell::getRight() {
  return right;
}

shared_ptr<Cell> Cell::getBot() { 
  return bot;
}

int Cell::getX(){
  return x;
}

int Cell::getY(){
  return y;
}

int Cell::getLabel() {
  return label;
}

void Cell::setLeft(shared_ptr<Cell> l){
  left = l;
}
void Cell::setRight(shared_ptr<Cell> r){
  right = r;
}
void Cell::setBot(shared_ptr<Cell> b){
  bot = b;
}

void Cell::setValue( const string & str ) {
  value = str;
  valueSet = true;
}

void Cell::setX(int i){
  x = i;
}

void Cell::setY(int j){
  y = j;
}

void Cell::setLabel(int l){
  label = l;
}

void Cell::cellMove(Cell* C){
  this->setValue(C->getValue());
  this->setLabel(C->getLabel());
  if(this->getValue() ==" "){
    this->unsetValue();
  }  
  C->unsetValue();

}

void Cell::unsetValue() {
  value = " ";
  label = 0;
  valueSet = false;
}

// TODO: setValue() method
// when a block is constructed, it will initialize a 2D array of cells
// each cell does not contain any value
// therefore, the block constructors will loop through each cell and 
// using the setValue method to assign value to each cell

// method 2:
// or using the cell constructor directly