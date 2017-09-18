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

	bool exists_;
	bool validEnd_;
	char letter; //for testing purposes only

public:

	trieNode* chars;

	trieNode()
	{
		exists_ = false;
		validEnd_ = false;
	}

	//prevents infinite recursive calls
	void initialize()
	{
		chars = new trieNode[26];
		exists_ = true;
	}

	void addWord(string word)
	{
		char c = word[0];
		int pos = (int)c - 97;

		//while more letters exist that need to be added to the trie
		if (word.length() > 0)
		{
			string newWord = word.substr(1, word.length() - 1);

			//if a node "exists" then it is part of a word
			if (!chars[pos].doesExist())
			{
				chars[pos].initialize();
			}

			chars[pos].setLetter(c);	//for testing purposes only
			chars[pos].addWord(newWord);
		}
		else
		{
			validEnd_ = true;
		}
	}

	bool isWord(string word)
	{
		char c = word[0];
		int pos = (int)c - 97;

		//is true when the end of the given word is reached
		if (word.length() < 1)
		{
			return validEnd_;
		}

		//recurses in a similar manner to addWord
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

		if ((int)prefix.length() == n)
		{
			return wordsWithPrefix(prefix);
		}

		char c = prefix[n];
		int pos = (int)c - 97;

		//gets to the end of the given prefix recursively
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

		//finds all posible words with a given prefix
		for (int i = 0; i < 26; i++)
		{
			//creates a new prefix for each additional letter
			//when isValidEnd is true we know this prefix is a complete word
			if (chars[i].doesExist())
			{
				string newPrefix = prefix + (char)(i + 97);

				if (chars[i].isValidEnd())
				{
					words.push_back(newPrefix);
				}

				for (string s : chars[i].wordsWithPrefix(newPrefix))
				{
					words.push_back(s);
				}
			}
		}

		return words;
	}

	bool doesExist()
	{
		return exists_;
	}

	bool isValidEnd()
	{
		return validEnd_;
	}

	//for testing purposes only
	void setLetter(char c)
	{
		letter = c;
	}

	char getLetter()
	{
		return letter;
	}

	trieNode& operator=(trieNode other)
	{
		initialize();
		validEnd_ = other.isValidEnd();
		letter = other.getLetter();	//for testing purposes only

		for (int i = 0; i < 26; i++)
		{
			if (other.chars[i].doesExist())
			{
				chars[i] = other.chars[i];
			}
		}

		return *this;
	}

	~trieNode()
	{
		if (exists_)
		{
			//exists_ = false;
			delete[] chars;
		}
	}

};