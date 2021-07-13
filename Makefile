all:
	g++ -O3 -fopenmp -lssl -lcrypto main.cpp Bchain.cpp Block.cpp -o prog
