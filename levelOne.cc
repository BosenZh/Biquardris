#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "levelOne.h"

LevelOne::LevelOne( int level ):
  NextBlock{ level } { 
}

LevelOne::~LevelOne(){}

char LevelOne::blockSelector() {
  int i = rand() % 12;
  if ( i == 0 ) {
    return 'S';
  } else if ( i == 1 ) {
    return 'Z';
  } else if ( i <= 3 ) {
    return 'I';
  } else if ( i <= 5 ) {
    return 'J';
  } else if ( i <= 7 ) {
    return 'L';
  } else if ( i <= 9 ) {
    return 'O';
  } else {
    return 'T';
  }
}