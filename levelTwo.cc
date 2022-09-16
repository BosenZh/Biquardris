#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "levelTwo.h"

LevelTwo::LevelTwo( int level ):
  NextBlock{ level } { }

LevelTwo::~LevelTwo(){}
char LevelTwo::blockSelector() {
  int i = rand() % 7;
  if ( i == 0 ) {
    return 'S';
  } else if ( i == 1 ) {
    return 'Z';
  } else if ( i == 2 ) {
    return 'I';
  } else if ( i == 3 ) {
    return 'J';
  } else if ( i == 4 ) {
    return 'L';
  } else if ( i == 5 ) {
    return 'O';
  } else {
    return 'T';
  }
}