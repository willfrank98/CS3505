/* William Frank
 * u1067292
 * A3: Rule-of-Three and the Trie
 */

#include "Trie.h"

using namespace std;

trieNode root;

Trie::Trie()
{

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
	return false;
}

//vector<string> Trie::allWordsStartingWithPrefix(string prefix)
//{
//	return NULL;
//}

Trie::~Trie()
{
	
}

