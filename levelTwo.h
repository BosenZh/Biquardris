#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__

#include "nextBlock.h"

class LevelTwo : public NextBlock {
  friend class ConcreteLevel;
  
  public:
  LevelTwo( int level );
  ~LevelTwo() override;
  char blockSelector() override;
};


#endif