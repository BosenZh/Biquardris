#ifndef SBLOCK__H__
#define SBLOCK__H__

#include "block.h"

class SBlock : public Block{
    public:
    SBlock(int);
    ~SBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif