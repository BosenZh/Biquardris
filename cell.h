#ifndef __CELL_H__
#define __CELL_H__

#include <string>
#include <memory>
#include "block.h"
using namespace std;


class Cell {
  string value;
  int x,y;
  int label = 0;
  shared_ptr<Cell> left;
  shared_ptr<Cell> right;
  shared_ptr<Cell> bot;
  bool valueSet;
  bool bd = false;

  public:
  Cell( const string & str = " ", bool value_set = false  );
  ~Cell();
  string getValue() const;
  shared_ptr<Cell> getLeft();
  shared_ptr<Cell> getRight();
  shared_ptr<Cell> getBot();
  int getX();
  int getY();
  int getLabel();
  bool getbd(){return bd;}

  // TODO: setValue() method
  void setLeft(shared_ptr<Cell>);
  void setRight(shared_ptr<Cell>);
  void setBot(shared_ptr<Cell>);
  void setValue( const string & );
  void setX(int);
  void setY(int);
  void setLabel(int);
  void cellMove(Cell *);
  void unsetValue();//also unsets the block
  void setbd(bool b){bd = b;}
};


#endif