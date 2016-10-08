#include "stdafx.h"
#include "Trie.h"

wordMaster::Trie::Trie()
{
	Root = new TrieNode();
}

wordMaster::Trie::~Trie()
{
	delete Root;
}

wordMaster::TrieNode* wordMaster::Trie::AddWord(std::string word, unsigned int id)
{
	TrieNode *LastNode = this->Root;
	std::cout << "\nRoot address: \t\t\t\t0x" << LastNode << std::endl;
	for (int i = 0; i < word.size(); i++)
	{
		if ((*LastNode)[word[i]] != nullptr)
		{
			LastNode = (*LastNode)[word[i]];
		}
		else
		{
			TrieNode *NextLetter = new TrieNode();
			NextLetter->SetPredecessor(LastNode);
			NextLetter->SetFlag(word[i]);
			(*LastNode)[word[i]] = NextLetter;
			std::cout << word[i] << ": New letter address : \t\t\t\t0x" << NextLetter << std::endl;
			LastNode = NextLetter;
		}
	}

	if (LastNode->GetId() == 0)
	{
		LastNode->SetId(id);
		std::cout << "New word added with hash: " << LastNode->GetId() << " at address \t\t\t\t" << LastNode << std::endl;

		return LastNode;
	}
	
	return NULL;
}

bool wordMaster::Trie::EraseWord(std::string word)
{
	return true;
}

int wordMaster::Trie::GetWordId(std::string word)
{
	TrieNode *LastNode = this->Root;
	for (int i = 0; i < word.size(); i++)
	{
		if ((*LastNode)[word[i]] != nullptr)
		{
			LastNode = (*LastNode)[word[i]];
		}
		else
		{
			return -1;
		}
	}
	
	return LastNode->GetId();
}

std::string wordMaster::Trie::GetTranslation(TrieNode* node)
{
	std::string recoveredTranslation;

	while (node->GetPredecessor() != NULL)
	{
		recoveredTranslation = node->GetFlag() + recoveredTranslation;
		node = node->GetPredecessor();
	}

	return recoveredTranslation;
}