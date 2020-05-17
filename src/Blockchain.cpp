#include "Blockchain.h"

Blockchain::Blockchain(){
    chain.push(Block(0,"Genesis"));
    difficulty = 5;
}


void Blockchain::AddBlock(Block newBlock){
    newBlock.prevHash = GetLastBlock().GetHash();
    newBlock.MineBlock(difficulty);

    chain.push(newBlock);
}


Block Blockchain::GetLastBlock() const{
    return chain.top();
}
