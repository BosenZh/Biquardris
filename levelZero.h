#ifndef __LEVELZERO_H__
#define __LEVELZERO_H__

#include "nextBlock.h"

class LevelZero : public NextBlock {
  friend class ConcreteLevel;
  long unsigned int currPosition = 0;
  std::string scriptFile;
  
  
  public:
  ~LevelZero() override;
  LevelZero( std::string scriptFile, int level );
  char blockSelector() override;
};


#endif