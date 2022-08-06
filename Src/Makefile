out: Main.o
	g++ Main.o -o out

Main.o: Main.cpp
	g++ -g -c -std=c++17 Main.cpp

all:
	g++ -g -std=c++17 Main.cpp -o main
	g++ -g -std=c++17 Brut.cpp -o brut

clean:
	rm *.o out

clean-all:
	rm -rf *.o In/* Expected_Out/* Given_Out/* Trie.dot Trie.dot.svg
