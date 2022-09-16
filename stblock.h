#ifndef STBLOCK__H__
#define STBLOCK__H__

#include "block.h"

class stBlock : public Block{
    public:
    stBlock(int);
    ~stBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif