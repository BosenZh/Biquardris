#ifndef JBLOCK__H__
#define JBLOCK__H__

#include "block.h"

class JBlock : public Block{
    public:
    JBlock(int);
    ~JBlock();
    void clockwiseRotate() override;
    void counterClockwiseRotate() override;
};


#endif