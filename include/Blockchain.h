#pragma once

#include "Block.h"
#include <stack>

class Blockchain{
    public:
        Blockchain(uint32_t);

        string AddBlock(Block);

    private:
        uint32_t difficulty;
        stack<Block> chain;

        Block GetLastBlock() const;
};
