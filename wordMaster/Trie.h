#pragma once

#ifndef TRIE
#define TRIE

#include <iostream>
#include <string>
#include "TrieNode.h"
#include "GuidGenerator.h"

namespace wordMaster 
{
	class Trie 
	{
	public:
		Trie();
		~Trie();

		TrieNode*		AddWord(std::string word, unsigned int id);
		bool			EraseWord(std::string word);
		int				GetWordId(std::string word);
		std::string		GetTranslation(TrieNode* node);

	private:
		TrieNode		*Root;
	};
}

#endif