#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include <memory>
#include "block.h"


using namespace std;
class pushdErr{};
class pushlErr{};
class pushrErr{};

class Cell;
class Board {
  vector < vector<shared_ptr< Cell > > >content;
  public:
  Board();
  ~Board();
  vector < vector<shared_ptr< Cell > > > getContent();
  void insertBlock(Block *);
  void insertMid(Block *);
  void pushBack(Block *); // throws an exception pushdErr if cannot push
  void pushLeft(Block *); // throws an exception pushlErr if cannot push
  void pushRight(Block *); // throws an exception pushrErr if cannot push
  int clearLine();
}; 

ostream& operator<<( ostream&, Board * );
#endif