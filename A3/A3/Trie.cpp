/* William Frank
* u1067292
* A3: Rule-of-Three and the Trie
*/

#include "Trie.h"

using namespace std;

trieNode root;

Trie::Trie()
{
	root.initialize();
	root.setLetter('%');
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

Trie & Trie::operator=(Trie other)
{
	Trie temp(other);
	other.root = root;
	root = temp.root;

	return *this;
}

Trie::~Trie()
{
	//no pointer resources used
}


