#ifndef ZBLOCK__H__
#define ZBLOCK__H__

#include "block.h"

class ZBlock : public Block{
    public:
    ZBlock(int);
    ~ZBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif