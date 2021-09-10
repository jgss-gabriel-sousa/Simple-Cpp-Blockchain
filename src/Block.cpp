#include "../include/Block.h"
#include "../include/sha256.h"

Block::Block(uint32_t index, const string &data){
    this->index = index;
    this->data = data;

    nOnce = -1;
    timestamp = time(nullptr);
}


string Block::GetHash(){
    return blockHash;
}


string Block::MineBlock(uint32_t difficulty){
    char cstr[difficulty+1];

    for(uint32_t i = 0; i < difficulty; i++)
        cstr[i] = '0';
    cstr[difficulty] = '\0';

    string str(cstr);

    do{
        nOnce++;
        blockHash = CalculateHash();
    }while(blockHash.substr(0,difficulty) != str);

    return blockHash;
}


inline string Block::CalculateHash() const{
    stringstream ss;
    ss<<index<<timestamp<<data<<nOnce<<prevHash;

    return sha256(ss.str());
}
