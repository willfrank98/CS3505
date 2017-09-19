/* William Frank
* u1067292
* A3: Rule-of-Three and the Trie
*/

#include <iostream>
#include <fstream>
#include "Trie.h"


using namespace std;

int main(int argc, char **argv)
{
	{

	Trie t;

	string word;
	ifstream dic;
	//dic.open(argv[1]);
	dic.open("text.txt");

	if (dic.is_open())
	{
		//adds every word to the trie
		while (getline(dic, word))
		{
			t.addWord(word);
		}

		dic.close();
	}
	else
	{
		cout << "Invalid file: " << argv[1];
		return 0;
	}

	ifstream query;
	//query.open(argv[2]);
	query.open("q.txt");

	if (query.is_open())
	{
		//adds every word to the trie
		while (getline(query, word))
		{
			if (t.isWord(word))
			{
				cout << word << " is found" << endl;
			}
			else
			{
				cout << word << " is not found, did you mean:" << endl;

				vector<string> words = t.allWordsStartingWithPrefix(word);

				if (words.size() == 0)
				{
					cout << "   no alternatives found" << endl;
				}
				else
				{
					for (auto s : words)
					{
						cout << "   " << s << endl;
					}
				}
			}
		}

		query.close();
	}
	else
	{
		cout << "Invalid file: " << argv[2];
		return 0;
	}

	}//makes sure everything gets cleaned up before the program exits
}
