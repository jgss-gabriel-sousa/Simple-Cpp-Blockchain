#pragma once

#include "Block.h"
#include <stack>

class Blockchain{
    public:
        Blockchain();

        void AddBlock(Block newBlock);

    private:
        uint32_t difficulty;
        stack<Block> chain;

        Block GetLastBlock() const;
};
