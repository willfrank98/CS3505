/* William Frank
* u1067292
* A3: Rule-of-Three and the Trie
*/

#include "Trie.h"

using namespace std;

trieNode root;

Trie::Trie()
{
	root.setLetter('%');	//for testing purposes only
	root.setExists(true);
}

//new copy cosntructor
//creates a deep copy
Trie::Trie(const Trie& trie)
{
	root = trie.root;
}

void Trie::addWord(string word)
{
	root.addWord(word);
}

bool Trie::isWord(string word)
{
	return root.isWord(word);
}

vector<string> Trie::allWordsStartingWithPrefix(string prefix)
{
	return root.findEndOfPrefix(prefix, 0);
}

std::vector<std::string> Trie::wordsWithWildcardPrefix(std::string word)
{
	return std::vector<std::string>();
}

Trie & Trie::operator=(Trie other)
{
	trieNode temp = other.root;
	other.root = root;
	root = temp;

	//root = other.root;

	other.root.chars = nullptr;

	//swap(root, other.root);

	return *this;
}

Trie::~Trie()
{
	//no pointer resources created
}


