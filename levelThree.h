#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__

#include "nextBlock.h"

class LevelThree : public NextBlock {
  protected:
  friend class ConcreteLevel;
  
  public:
  LevelThree( int level );
  ~LevelThree() override;
  char blockSelector() override;
};


#endif