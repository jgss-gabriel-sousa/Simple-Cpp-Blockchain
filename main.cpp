#include <cstdlib>
#include <iostream>
#include <time.h>

#include "include/Blockchain.h"

using namespace std;

int main(){
    Blockchain blockchain = Blockchain(3);

    string blockContent, blockHash;
    clock_t startTime, endTime;

    for(int i = 0; i < 50; i++){
        cout<<"Mining Block "<<i<<endl;

        blockContent = "Contract number "+to_string(i);

        startTime = clock();
        blockHash = blockchain.AddBlock(Block(i, blockContent));
        endTime = clock();

        cout<<"Content: "<<blockContent<<endl;
        cout<<"Hash: "<<blockHash<<endl;
        cout<<"Mined in "<<static_cast<float>((endTime - startTime) / 1000.0F )<<" s"<<endl;
        cout<<endl;
    }
    return 0;
}
