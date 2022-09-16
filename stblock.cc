#include "block.h"
#include "stblock.h"
#include "cell.h"
#include <iostream>

stBlock::stBlock(int lab) 
    : Block{'*', lab} {
    for(int i = 0;i < 4; i++) {
        std::vector<std::shared_ptr<Cell>> currRow;

        for(int j = 0; j < 4; j++) {
            if( i == 3 && (j == 1)) {
                currRow.emplace_back( std::make_shared<Cell>("*", true) );
                currRow[j]->setLabel(lab);
            } else {
                currRow.emplace_back( std::make_shared<Cell>() );
                // grid.at( i ).at( j )->setValue( " " );
            }
        }
        grid.emplace_back( currRow );
    }
}


stBlock::~stBlock() { }

void stBlock::clockwiseRotate() {
}

void stBlock::counterClockwiseRotate() {
}
