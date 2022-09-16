#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "levelThree.h"

LevelThree::LevelThree( int level ):
  NextBlock{ level } { }

LevelThree::~LevelThree(){}
char LevelThree::blockSelector() {
  int i = rand() % 9;
  if ( i <= 1 ) {
    return 'S';
  } else if ( i <= 3 ) {
    return 'Z';
  } else if ( i == 4 ) {
    return 'I';
  } else if ( i == 5 ) {
    return 'J';
  } else if ( i == 6 ) {
    return 'L';
  } else if ( i == 7 ) {
    return 'O';
  } else {
    return 'T';
  }
}