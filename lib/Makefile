FLAGS = --todo

all:
	make clean
	# TODO: make build
	make precompiled

build:
	# TODO
	#
	# sudo yum -y install git gcc gcc-c++ libtool
	# sudo yum -y install automake
	# git clone https://github.com/bitcoin-core/secp256k1
	# cd secp256k1
	# ./autogen.sh
	# ./configure
	# make
	# ./tests
  #
	# I'd rather use the static .a library then run "install"
	# sudo make install

precompiled:
	g++ -std=c++11 -O3 -s ../test-pre.cpp -L ../precompiled -l :libsecp256k1.a -o ../test-pre
	valgrind --leak-check=yes --quiet ../test-pre
	# 64c9992d70d56cf60383b86dcba395ee0ccdb780b13d1b52803b010ae62574b68ebc46f0b25acf3721da182a180b985500669ec8541244752ec1331ea61aacee
	../test-pre
	# 64c9992d70d56cf60383b86dcba395ee0ccdb780b13d1b52803b010ae62574b68ebc46f0b25acf3721da182a180b985500669ec8541244752ec1331ea61aacee

CreateObjectFiles:
	# TODO

CreateArchive:
	# TODO

clean:
	rm -f *.a *.o ../test ../test-pre
	clear
