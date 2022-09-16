#include <fstream>
#include "nextBlock.h"


NextBlock::NextBlock( int level ): 
  level{ level } { }

NextBlock::~NextBlock(){}
int NextBlock::getLevel() {
  return level;
}
