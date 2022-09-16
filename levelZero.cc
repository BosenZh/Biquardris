#include "nextBlock.h"
#include "levelZero.h"
#include <fstream>
#include <iostream>

LevelZero::LevelZero( std::string scriptFile, int level ):
  NextBlock{ level }, scriptFile{ scriptFile } {
    std::fstream file{ scriptFile };
    char blockShape;
    while ( file >> blockShape ) {
      blocks.emplace_back( blockShape );
  }
} 

LevelZero::~LevelZero(){}

char LevelZero::blockSelector() {
  int pos = currPosition;
  // update currPosition to the next suitable position
  if (currPosition == blocks.size() - 1 ) {
    currPosition = 0;
  } else {
    currPosition++;
  }
  return blocks[pos];
}
