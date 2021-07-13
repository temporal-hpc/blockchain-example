#include "Bchain.h"

Bchain::Bchain(int d){
    this->difficulty = d;
    this->chain.push_back( Block(0, 1, "0") );
    printf("blockChain with difficulty %i\n", this->difficulty);
}

void Bchain::addBlock( Block b ){
    b.prev_hash = chain.back().hash;
    b.mineBlock(this->difficulty);
    chain.push_back(b); 
}

Block Bchain::getLastBlock(){
    return chain.back();
}

// blockChain validation code
bool Bchain::isValid(){
    // validation code
    return true;
}

void Bchain::printBlockChain(){
    printf("---BEGIN BLOCKCHAIN---\n");
    for(int i=0; i<this->chain.size(); ++i){
        chain[i].printBlock();
    }
    printf("---END BLOCKCHAIN---\n");
}
