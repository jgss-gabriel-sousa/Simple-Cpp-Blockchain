#include "../include/Blockchain.h"

Blockchain::Blockchain(uint32_t difficulty){
    this->difficulty = difficulty;

    chain.push(Block(0,"Genesis"));
}


string Blockchain::AddBlock(Block newBlock){
    newBlock.prevHash = GetLastBlock().GetHash();
    string blockHash = newBlock.MineBlock(difficulty);

    chain.push(newBlock);

    return blockHash;
}


Block Blockchain::GetLastBlock() const{
    return chain.top();
}
