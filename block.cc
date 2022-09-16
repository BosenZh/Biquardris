#include <memory>
#include "block.h"
#include "cell.h"

// TODO: implement seven derived classes of block

// az的思路
// 感觉可以直接用stack做 2D array （感觉区别不大）
// 如果用heap 记得直接用unique_ptr
// cotent 会initialize 一个空的2D
// 然后根据 block的种类 然后做initialization

// rotation的感觉 要分四种情况 rotate 
// 感觉private field里面需要再加一个当前rotation的状态
Block::Block( char c, int lab ) : value{ c }, lab { lab } { }

Block::~Block() { }
std::vector<std::vector<std::shared_ptr<Cell>>>& Block::getGrid() {
  return grid;
}
std::vector<std::vector<std::shared_ptr<Cell>>>* Block::getGridptr(){
  return &grid;
}