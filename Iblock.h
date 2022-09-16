#ifndef IBLOCK__H__
#define IBLOCK__H__

#include "block.h"

class IBlock : public Block {

    public:
    IBlock(int);
    ~IBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
    // void print () override;
};


#endif