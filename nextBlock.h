#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <string>
#include <vector>
#include <memory>

class Block;

class NextBlock {
  protected:
  int level;
  std::vector<char> blocks;

  public:
  NextBlock( int level );
  virtual ~NextBlock();
  virtual char blockSelector() = 0;
  // virtual void assignProb() = 0;
  std::vector<char>& getBlocks() { return blocks;};
  int getLevel();
};



#endif