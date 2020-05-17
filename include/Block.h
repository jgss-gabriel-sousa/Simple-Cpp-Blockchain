#pragma once

#include <string>
#include <ctime>
#include <sstream>

using namespace std;

class Block{
    public:
        Block(uint32_t indexIn, const string &dataIn);

        string prevHash;

        string GetHash();
        void MineBlock(uint32_t nDifficulty);

    private:
        uint32_t index;
        uint64_t nOnce;
        string data;
        string blockHash;
        time_t timestamp;

        string CalculateHash() const;
};
