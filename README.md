# blockchain-example
A simple C++ blockchain example using a proof of work (POW) scheme.

# dependencies
-   c++ compiler
-   make
-   openssl (-lssl -lcrypto)
-   openmp (just used for timing)


# compile and run
`make`

`./prog difficulty blocks`

- difficulty: number of leading zeros in the SHA256 hash.
- blocks: number of blocks to create with proof of work.


# example execution
```
➜  blockchain-example git:(main) ✗ ./prog 4 2                               
blockChain with difficulty 4
Mining block.......done: 0.155 secs
found hash 0000143cc907b0a6329b7524d912e9a2627a3e499403101ddd6bc41dd76de771     
Mining block.......done: 0.143 secs
found hash 0000c997ff86c7448944c88def5a752e23c2d32a952bab0c58604893a478d944     
---BEGIN BLOCKCHAIN---
---------------
Block 0
data      = 1
hash      = f68fa2993da5f3df56d02e5534f2d647d056eb92c401c4ae9ec718c9d1e37647
prev_hash = 0
---------------

---------------
Block 1
data      = 0
hash      = 0000143cc907b0a6329b7524d912e9a2627a3e499403101ddd6bc41dd76de771
prev_hash = f68fa2993da5f3df56d02e5534f2d647d056eb92c401c4ae9ec718c9d1e37647
---------------

---------------
Block 2
data      = 1000
hash      = 0000c997ff86c7448944c88def5a752e23c2d32a952bab0c58604893a478d944
prev_hash = 0000143cc907b0a6329b7524d912e9a2627a3e499403101ddd6bc41dd76de771
---------------

---END BLOCKCHAIN---
```
