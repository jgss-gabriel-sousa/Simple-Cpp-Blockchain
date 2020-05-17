#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t indexIn, const string &dataIn) : index(indexIn),data(dataIn){
    nOnce = -1;
    timestamp = time(nullptr);
}


string Block::GetHash(){
        return blockHash;
}


void Block::MineBlock(uint32_t difficulty){
    char cstr[difficulty+1];

    for(uint32_t i = 0; i < difficulty; i++)
        cstr[i] = '0';
    cstr[difficulty] = '\0';

    string str(cstr);

    do{
        nOnce++;
        blockHash = CalculateHash();
    }while(blockHash.substr(0,difficulty) != str);
}


inline string Block::CalculateHash() const{
    stringstream ss;
    ss<<index<<timestamp<<data<<nOnce<<prevHash;

    return sha256(ss.str());
}
