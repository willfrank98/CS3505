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
		cout << "Invalid dictionary file";
		return 0;
	}




}
