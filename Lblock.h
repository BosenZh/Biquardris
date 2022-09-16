#ifndef LBLOCK__H__
#define LBLOCK__H__

#include "block.h"

class LBlock : public Block{
    public:
    LBlock(int);
    ~LBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif