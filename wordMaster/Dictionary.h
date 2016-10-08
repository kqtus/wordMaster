#pragma once

#ifndef DICTIONARY
#define DICTIONARY

#include "Trie.h"
#include <unordered_map>

namespace wordMaster
{
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		bool				AddWord(std::string word, std::string translatedWord);
		std::string			GetTranslation(std::string word);
	private:
		const static int	WORD_NOT_FOUND = -1;
		Trie				*OriginalWords;
		Trie				*TranslatedWords;
		GuidGenerator		*WordsHashGenerator;
		std::unordered_map<int, std::pair<TrieNode*, TrieNode*> >	IdHashesUMap;
	};
}
#endif
