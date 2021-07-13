#include <chrono>
#include <random>
#include "Block.h"
#include "tools.h"

Block::Block(int index, int data, string prev_hash){
    unsigned seed = index+std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);  // mt19937 is a standard mersenne_twister_engine
    this->index = index;
    this->data = data;
    this->x = gen();
    this->prev_hash = prev_hash;
    this->hash = this->computeHash();
}

// calcular hash en base a los valores
string Block::computeHash(){
    string input = std::to_string(this->index + this->data + this->x);
    return sha256(input);
}

void Block::mineBlock(int d){
    double t1, t2;
    t1 = omp_get_wtime();
    printf("Mining block......."); fflush(stdout);
    string s1 = hash.substr(0,d);
    string s2 = zeroString(d);
    //printf("%s     %s\n", s1.c_str(), s2.c_str());
    while(s1 != s2){
        this->x++;
        this->hash = this->computeHash();
        s1 = hash.substr(0,d);
        s2 = zeroString(d);
        //printf("current hash %s     \n", this->hash.c_str());
        //printf("%s     %s\n", s1.c_str(), s2.c_str());
    }
    t2 = omp_get_wtime();
    printf("done: %.3f secs\n", t2-t1); fflush(stdout);
    printf("found hash %s     \n", this->hash.c_str());
}

void Block::printBlock(){
    printf("---------------\nBlock %i\ndata      = %i\nhash      = %s\nprev_hash = %s\n---------------\n\n", this->index, this->data, this->hash.c_str(), this->prev_hash.c_str());
}
