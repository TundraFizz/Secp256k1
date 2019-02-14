# Secp256k1

```
sudo yum -y install git gcc-c++
git clone https://github.com/TundraFizz/Secp256k1
cd Secp256k1
g++ -std=c++11 -O3 -s main.cpp -L . -l :libsecp256k1.a -o main
./main
```

#### Todo: Build it yourself

Here's some commands that will help

```
sudo yum -y install git gcc gcc-c++ libtool
sudo yum -y install automake
git clone https://github.com/bitcoin-core/secp256k1
cd secp256k1
./autogen.sh
./configure
make
./tests

I'd rather use the static .a library that run "install"
sudo make install
```
