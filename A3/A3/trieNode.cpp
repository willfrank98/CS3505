/* William Frank
 * u1067292
 * A3: Rule-of-Three and the Trie
 */

//#include <vector>
#include <string>

using namespace std;

class trieNode
{
private:

	trieNode* chars;

public:

	bool exists;

	trieNode()
	{
		exists = false;
	}

	//prevents infinite recursive calls
	void initialize()
	{
		chars = new trieNode[26];
	}

	void addWord(string word)
	{
		exists = true;
		char c = word[0];
		int pos = (int)c;

		string newWord = word.substr(1, word.length() - 1);

		if (newWord.length() > 0)
		{
			word.substr(1, word.length() - 1);
		}
	}


	~trieNode()
	{
		delete[] chars;
	}

};