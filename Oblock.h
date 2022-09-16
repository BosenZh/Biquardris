#ifndef OBLOCK__H__
#define OBLOCK__H__

#include "block.h"

class OBlock : public Block{
    public:
    OBlock(int);
    ~OBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif