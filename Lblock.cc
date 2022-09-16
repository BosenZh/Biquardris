#include "block.h"
#include "Lblock.h"
#include "cell.h"
#include <iostream>

LBlock::LBlock(int lab)
    : Block{ 'L', lab} {
    for(int i = 0;i < 4; i++) {
        std::vector<std::shared_ptr<Cell>> currRow;

        for(int j = 0; j < 4; j++) {
            if( i == 2 && j == 2) {
                currRow.emplace_back( std::make_shared<Cell>("L", true) );
                currRow[j]->setLabel(lab);
            } else if ( i == 3 && (j == 0 || j == 1 || j == 2 )) {
                currRow.emplace_back( std::make_shared<Cell>("L", true) );
                currRow[j]->setLabel(lab);
            } else {
                currRow.emplace_back( std::make_shared<Cell>() );
            }
        }
        grid.emplace_back( currRow );
    }
}


LBlock::~LBlock() { }

void LBlock::clockwiseRotate() {
    if(rotateState == 0) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(( i == 3 && j == 1) || ( j == 0 && (i == 1 || i == 2 || i == 3))) {
                    if(grid.at( i ).at( j )->getLabel() != 0 && i != 3 && j != 1 && j != 0) {
                        return;
                    }
                }
            }
        }
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( j == 0 && (i == 1 || i == 2 || i == 3)) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else if ( i == 3 && j == 1) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState++;
    } else if (rotateState == 1) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(( i == 3 && j == 0) || ( i == 2 && (j == 0 || j == 1 || j == 2))) {
                    if(grid.at( i ).at( j )->getLabel() != 0 && i != 3 && j != 0 && i != 2) {
                        return;
                    }
                }
            }
        }
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( i == 2 && (j == 0 || j == 1 || j == 2)) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else if ( i == 3 && j == 0) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState++;
    } else if (rotateState == 2) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(( i == 1 && j == 0)  || ( j == 1 && (i == 1 || i == 2 || i == 3))) {
                    if(grid.at( i ).at( j )->getLabel() != 0 && i != 2 && j != 1) {
                        return;
                    }
                }
            }
        }
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( j == 1 && (i == 1 || i == 2 || i == 3)) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else if ( i == 1 && j == 0) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState++;
    } else if (rotateState == 3) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(( i == 2 && j == 2)  || ( i == 3 && (j == 0 || j == 1 || j == 2))) {
                    if(grid.at( i ).at( j )->getLabel() != 0 && i !=3 && j != 1) {
                        return;
                    }
                }
            }
        }
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( i == 3 && (j == 0 || j == 1 || j == 2)) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else if ( i == 2 && j == 2) {
                    grid.at( i ).at( j )->setValue( "L" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState = 0;
    }
}

void LBlock::counterClockwiseRotate() {
    rotateState += 2;
    if(rotateState >= 3) {
        rotateState -= 3;
    }
    clockwiseRotate();
}