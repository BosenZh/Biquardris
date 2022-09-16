#ifndef TBLOCK__H__
#define TBLOCK__H__

#include "block.h"

class TBlock : public Block{
    public:
    TBlock(int);
    ~TBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif