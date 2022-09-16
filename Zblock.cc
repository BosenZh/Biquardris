#include "block.h"
#include "Zblock.h"
#include "cell.h"
#include <iostream>

ZBlock::ZBlock(int lab) 
    : Block{'Z', lab} {
    for(int i = 0;i < 4; i++) {
        std::vector<std::shared_ptr<Cell>> currRow;

        for(int j = 0; j < 4; j++) {
            if( i == 2 && (j == 0 || j == 1 )) {
                currRow.emplace_back( std::make_shared<Cell>( "Z", true ) );
                currRow[j]->setLabel(lab);
                // grid.at( i ).at( j )->setValue();
            } else if ( i == 3 && (j == 1 || j == 2 )) {
                currRow.emplace_back( std::make_shared<Cell>( "Z", true ) );
                currRow[j]->setLabel(lab);
                // grid.at( i ).at( j )->setValue( "Z" );
            } else {
                currRow.emplace_back( std::make_shared<Cell>() );
                // grid.at( i ).at( j )->unsetValue();
            }
        }

        grid.emplace_back( currRow );
    }
}


ZBlock::~ZBlock() { }

void ZBlock::clockwiseRotate() {
    if(rotateState == 0) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(( j == 0 && (i == 2 || i == 3 )) || ( j == 1 && (i == 1 || i == 2 ))) {
                    if(grid.at( i ).at( j )->getLabel() != 0 && i != 2 && j!= 0 && j!=1)  {
                        return;
                    }
                }
            }
        }
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( j == 0 && (i == 2 || i == 3 )) {
                    grid.at( i ).at( j )->setValue( "Z" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else if ( j == 1 && (i == 1 || i == 2 )) {
                    grid.at( i ).at( j )->setValue( "Z" );
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
                if(( i == 2 && (j == 0 || j == 1 )) || ( i == 3 && (j == 1 || j == 2 ))) {
                    if(grid.at( i ).at( j )->getLabel() != 0 && i != 2 && j!= 0 && j!=1)  {
                        return;
                    }
                }
            }
        }
        for(int i = 0;i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if( i == 2 && (j == 0 || j == 1 )) {
                    grid.at( i ).at( j )->setValue( "Z" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else if ( i == 3 && (j == 1 || j == 2 )) {
                    grid.at( i ).at( j )->setValue( "Z" );
                    grid.at( i ).at( j )->setLabel( lab );
                } else {
                    grid.at( i ).at( j )->unsetValue();
                }
            }
        }
        rotateState = 0;
    } 
}

void ZBlock::counterClockwiseRotate() {
    clockwiseRotate();
    clockwiseRotate();
    clockwiseRotate();
}
