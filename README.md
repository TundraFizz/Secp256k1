# Secp256k1

LD_LIBRARY_PATH=/usr/lib
LD_RUN_PATH=/usr/lib
export LD_LIBRARY_PATH
export LD_RUN_PATH

g++ -std=c++11 -O3 -s main.cpp -L/usr/local/lib -l secp256k1 -o main
./main
valgrind --leak-check=yes --quiet ./main
