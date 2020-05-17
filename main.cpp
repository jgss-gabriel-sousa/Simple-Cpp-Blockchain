#include <cstdlib>
#include <iostream>

#include "Blockchain.h"

using namespace std;

int main(){
    Blockchain blockchain = Blockchain();

    for(int i = 0; i < 5; i++){
        cout<<"Mining Block "<<i<<endl;
        blockchain.AddBlock(Block(1,"Contract "+i));
    }
    return 0;
}
