#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <omp.h>

#include "Block.h"
#include "Bchain.h"

int main(int argc, char **argv){
   if(argc != 3){
       fprintf(stderr, "run as ./prog difficulty blocksToAdd\n\n");
       exit(EXIT_FAILURE);
   }
   int dif = atoi(argv[1]);
   int blocks = atoi(argv[2]);

   // (1) creando blockchain con dificultad 'dif'
   Bchain bc(dif);

   // (2) creacion de bloques, cada uno significa un minado
   for(int i=0; i<blocks; i++){
        bc.addBlock( Block(i+1, i*1000, bc.getLastBlock().hash) );
   }

   bc.printBlockChain();
}
