DIC = "text.txt"
QUERY = "q.txt"
FLAGS = -std=c++11 -Wall -g

Trie.o: Trie.cpp Trie.h
	g++ -c Trie.cpp $(FLAGS)

trieNode.o: trieNode.cpp
	g++ -c trieNode.cpp $(FLAGS)

TrieTest.o: TrieTest.cpp Trie.h
	g++ -c TrieTest.cpp $(FLAGS)

TrieTest: Trie.o trieNode.o TrieTest.o
	g++ -o TrieTest Trie.o trieNode.o TrieTest.o $(FLAGS)

test: TrieTest
	./TrieTest $(DIC) $(QUERY)

clean:
	rm *.o TrieTest
