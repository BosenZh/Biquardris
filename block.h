#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <vector>
#include <memory>

using namespace std;
class Cell;
class Block {
  protected:
  std::string value;
  int lab;
  vector<vector<shared_ptr<Cell>>> grid;
  int rotateState = 0;

  public:
  Block( char c, int lab );
  virtual ~Block();
  void virtual clockwiseRotate() = 0;
  void virtual counterClockwiseRotate() = 0;
  std::vector<std::vector<std::shared_ptr<Cell>>>& getGrid();
  std::vector<std::vector<std::shared_ptr<Cell>>>* getGridptr();
  int getLab(){return lab;}
  // void virtual moveLeft() = 0; //az -> this function should be in Board class
  // void virtual moveRight() = 0; //az -> this function should be in Board class
};

// TODO: implement seven derived classes of block



#endif