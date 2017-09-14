/* William Frank
* u1067292
* A3: Rule-of-Three and the Trie
*/

#include <vector>
#include <string>

using namespace std;

class trieNode
{
private:

	trieNode* chars;
	bool exists;
	bool validEnd;
	char letter; //for testing purposes only

public:

	trieNode()
	{
		exists = false;
	}

	//prevents infinite recursive calls
	void initialize()
	{
		chars = new trieNode[26];
		exists = true;
		validEnd = false;
	}

	void addWord(string word)
	{
		char c = word[0];
		int pos = (int)c - 97;

		if (word.length() > 0)
		{
			string newWord = word.substr(1, word.length() - 1);

			if (!chars[pos].doesExist())
			{
				chars[pos].initialize();
			}

			chars[pos].setLetter(c);	//for testing purposes only
			chars[pos].addWord(newWord);
		}
		else
		{
			validEnd = true;
		}
	}

	bool isWord(string word)
	{
		char c = word[0];
		int pos = (int)c - 97;

		if (word.length() < 1)
		{
			return validEnd;
		}

		string newWord = word.substr(1, word.length() - 1);

		if (chars[pos].doesExist())
		{
			return chars[pos].isWord(newWord);
		}
		else
		{
			return false;
		}
	}

	vector<string> findEndOfPrefix(string prefix, int n)
	{
		vector<string> words;

		if (prefix.length() == n)
		{
			return wordsWithPrefix(prefix);
		}

		char c = prefix[n];
		int pos = (int)c - 97;

		if (chars[pos].doesExist())
		{
			return chars[pos].findEndOfPrefix(prefix, n + 1);
		}
		else
		{
			//this should always return an empty vector
			return words;
		}
	}

	vector<string> wordsWithPrefix(string prefix)
	{
		vector<string> words;

		for (int i = 0; i < 26; i++)
		{
			if (chars[i].doesExist())
			{
				string newPrefix = prefix + (char)(i + 97);

				if (chars[i].isValidEnd())
				{
					words.push_back(newPrefix);
				}

				for each (string s in chars[i].wordsWithPrefix(newPrefix))
				{
					words.push_back(s);
				}
			}
		}

		return words;
	}

	bool doesExist()
	{
		return exists;
	}

	bool isValidEnd()
	{
		return validEnd;
	}

	void setLetter(char c)
	{
		letter = c;
	}


	~trieNode()
	{
		if (exists)
		{
			delete[] chars;
		}
	}

};