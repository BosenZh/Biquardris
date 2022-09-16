#ifndef __LEVELONE_H__
#define __LEVELONE_H__

#include "nextBlock.h"

class LevelOne : public NextBlock {
  friend class ConcreteLevel;
  
  public:
  LevelOne( int level );
  ~LevelOne() override;
  char blockSelector() override;
  // void assignProb() override;
};


#endif