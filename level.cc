#include "level.h"
#include "nextBlock.h"
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include <memory>

using namespace std;
ConcreteLevel::ConcreteLevel( ) { }
ConcreteLevel::~ConcreteLevel( ) { }
NextBlock* ConcreteLevel::createNextBlock( int level, std::string str ) {
  level = level;
  
  if ( level == 0 ) {
    tempnext = make_shared<LevelZero>(str, level);
  } else if ( level == 1 ) {
    tempnext = make_shared<LevelOne>(1);
  } else if ( level == 2 ) {
    tempnext = make_shared<LevelTwo>(1);
  } else if ( level == 3 ) {
    tempnext = make_shared<LevelThree>(3);
  } else {
    tempnext = make_shared<LevelFour>(4);
  }
  return tempnext.get();
}