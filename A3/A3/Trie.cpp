/* William Frank
* u1067292
* A3: Rule-of-Three and the Trie
*/

#include "Trie.h"
#include "trieNode.cpp"

using namespace std;

trieNode root;

Trie::Trie()
{
	root.initialize();
	root.setLetter('%');
}

//new copy cosntructor
Trie::Trie(const Trie& trie)
{

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

Trie::~Trie()
{


}


