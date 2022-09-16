#include "block.h"
#include "Iblock.h"
#include "cell.h"
#include <iostream>


IBlock::IBlock(int lab)
    : Block{ 'I', lab} { 
    for(int i = 0;i < 4; i++) {
        std::vector<std::shared_ptr<Cell>> currRow;
        for(int j = 0; j < 4; j++) {
            currRow.emplace_back( std::make_shared<Cell>() );
        }
        grid.emplace_back( currRow );
    }
    for(int i = 0; i < 4; i++) {
        grid.at( 3 ).at( i )->setValue( "I" );
        grid.at( 3 ).at( i )->setLabel( lab );
    }
}
IBlock::~IBlock() { }


void IBlock::clockwiseRotate() {
    if(rotateState == 0) {
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( j == 0) {
                    grid.at( i ).at( j )->setValue( "I" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState++;
    } else if (rotateState == 1) {
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( i == 0) {
                    grid.at( i ).at( j )->setValue( "I" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState = 0;
    } 
}


void IBlock::counterClockwiseRotate() {
    clockwiseRotate();
}
