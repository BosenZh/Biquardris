#include "block.h"
#include "Oblock.h"
#include "cell.h"
#include <iostream>

OBlock::OBlock(int lab) 
    : Block{'O', lab} {
    for(int i = 0;i < 4; i++) {
        std::vector<std::shared_ptr<Cell>> currRow;

        for(int j = 0; j < 4; j++) {
            if( i == 2 && (j == 0 || j == 1)) {
                currRow.emplace_back( std::make_shared<Cell>("O", true) );
                currRow[j]->setLabel(lab);
                // grid.at( i ).at( j )->setValue(  );
            } else if ( i == 3 && (j == 0 || j == 1)) {
                currRow.emplace_back( std::make_shared<Cell>("O", true) );
                currRow[j]->setLabel(lab);
                // grid.at( i ).at( j )->setValue( "O" );
            } else {
                currRow.emplace_back( std::make_shared<Cell>() );
                // grid.at( i ).at( j )->setValue( " " );
            }
        }
        grid.emplace_back( currRow );
    }
}


OBlock::~OBlock() { }

void OBlock::clockwiseRotate() {
}

void OBlock::counterClockwiseRotate() {
}
