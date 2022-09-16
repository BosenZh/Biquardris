#ifndef __LEVELFOUR_H__
#define __LEVELFOUR_H__

#include "levelThree.h"

class LevelFour : public LevelThree {
  friend class ConcreteLevel;
  
  public:
  LevelFour( int level );
  ~LevelFour() override;
  // char blockSelector() override;
};


#endif