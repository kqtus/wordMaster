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
		bool			EraseWord(TrieNode* lastNode);
		int				GetWordId(std::string word);
		TrieNode*		GetWordHandler(std::string word);
		std::string		GetTranslation(TrieNode* node);

	private:
		TrieNode		*Root;
	};
}

#endif