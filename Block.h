#pragma once 

#include <cstdlib>
#include <vector>
#include <string>
#include <omp.h>

using namespace std;

class Block{
    public:
        int index;
        int data;
        long x;
        string hash;
        string prev_hash;
        Block(int index, int data, string prev_hash);
        string computeHash();
        void mineBlock(int d);
        void printBlock() ;
};
