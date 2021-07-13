#pragma once
#include "Block.h"
class Bchain{
    private:
        int difficulty;
        vector<Block> chain;

    public:
        Bchain(int d);

        void addBlock( Block b );
        Block getLastBlock();
        bool isValid();
        void printBlockChain();
};
