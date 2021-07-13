#pragma once
#include <openssl/sha.h>
#include <string>
#include <cstring>

using namespace std;

string zeroString(int d){
    string acc = "";
    for(int i=0; i<d; ++i){
       acc += string("0"); 
    }
    return acc;
}


string sha256(string input){
    char *STR = (char*)input.c_str();
    char outputBuffer[65];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, STR, strlen(STR));
    SHA256_Final(hash, &sha256);
    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++){
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
    return string(outputBuffer);
}
