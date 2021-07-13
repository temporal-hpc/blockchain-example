# blockchain-example
A simple C++ blockchain example using a simple proof of work POW scheme.

# dependencies
-   c++ compiler
-   make
-   openssl (-lssl -lcrypto)
-   openmp (just used for timing)


# compile and run
`make`

`./prog difficulty blocks`

difficulty = the number of leading zeros in the SHA256 hash.
blocks = number of blocks to create with proof of work.
