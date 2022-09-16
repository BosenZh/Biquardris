#ifndef __LEVEL_H__
#define __LEVEL_H__
#include "nextBlock.h"
#include <memory>

class Level {
  public:
  virtual NextBlock* createNextBlock( int level,std::string str = " " )  = 0;
  virtual ~Level() { }
  // virtual void setLevel() = 0;
};

class ConcreteLevel : public Level {
  int level;
  std::shared_ptr<NextBlock> tempnext;
  public:
  ~ConcreteLevel() override;
  NextBlock * createNextBlock(int level, std::string str = " " ) override;
  ConcreteLevel( );
  // void setLevel();
};


#endif