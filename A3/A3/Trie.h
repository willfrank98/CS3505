/* William Frank
* u1067292
* A3: Rule-of-Three and the Trie
*/


#ifndef HARU_H
#define HARU_H

#include <string>
#include <vector>
#include "trieNode.cpp"

class Trie
{
private:

public:

	trieNode root;

	Trie();

	Trie(const Trie& trie);

	void addWord(std::string word);

	bool isWord(std::string word);

	std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);

	std::vector<std::string> wordsWithWildcardPrefix(std::string word);

	Trie& operator=(Trie other);

	~Trie();
};

#endif