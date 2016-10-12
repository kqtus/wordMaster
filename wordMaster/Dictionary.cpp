#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>

wordMaster::Dictionary::Dictionary()
{
	OriginalWords = new Trie();
	TranslatedWords = new Trie();
	WordsHashGenerator = new GuidGenerator();
}

wordMaster::Dictionary::~Dictionary()
{
	delete OriginalWords;
	delete TranslatedWords;
	delete WordsHashGenerator;
}

bool wordMaster::Dictionary::AddWord(std::string word, std::string translatedWord)
{
	int phraseHash = this->WordsHashGenerator->GetHash();

	std::cout << "Adding word " << word << " to original dict...\n" << std::endl;
	wordMaster::TrieNode* originalEndNode = OriginalWords->AddWord(word, phraseHash);
	std::cout << "originalEndNode address: \t\t\t\t0x" << originalEndNode << std::endl;

	std::cout << "Adding word " << translatedWord << " to translation dict...\n" << std::endl;
	wordMaster::TrieNode* translatedEndNode = TranslatedWords->AddWord(translatedWord, phraseHash);
	std::cout << "translatedEndNode address: \t\t\t\t0x" << translatedEndNode << std::endl << std::endl;

	this->IdHashesUMap[phraseHash] = std::make_pair(originalEndNode, translatedEndNode);
	
	return true;
}

bool wordMaster::Dictionary::RemoveWord(std::string word)
{
	int idOriginalDict = this->OriginalWords->GetWordId(word);
	int idTranslatedDict = this->TranslatedWords->GetWordId(word);

	if (idOriginalDict != WORD_NOT_FOUND)
	{
		this->OriginalWords->EraseWord(this->IdHashesUMap[idOriginalDict].first);
		this->TranslatedWords->EraseWord(this->IdHashesUMap[idOriginalDict].second);
		this->WordsHashGenerator->FreeHash(idOriginalDict);
		this->IdHashesUMap.erase(idOriginalDict);
		std::cout << "Successfully erased word : " << word << std::endl;
		return true;
	}
	else if (idTranslatedDict != WORD_NOT_FOUND)
	{
		this->OriginalWords->EraseWord(this->IdHashesUMap[idTranslatedDict].first);
		this->TranslatedWords->EraseWord(this->IdHashesUMap[idTranslatedDict].second);
		this->WordsHashGenerator->FreeHash(idTranslatedDict);
		this->IdHashesUMap.erase(idTranslatedDict);
		std::cout << "Successfully erased word : " << word << std::endl;
		return true;
	}

	std::cout << "Nothing to erase..." << std::endl;
	return false;
}

std::string wordMaster::Dictionary::GetTranslation(std::string word)
{
	int idOriginalDict = this->OriginalWords->GetWordId(word);
	int idTranslatedDict = this->TranslatedWords->GetWordId(word);

	if (idOriginalDict != WORD_NOT_FOUND)
	{
		std::cout << "Translation found with endNode address: \t\t0x" << this->IdHashesUMap[idOriginalDict].second << std::endl;
		return this->OriginalWords->GetTranslation(this->IdHashesUMap[idOriginalDict].second);
	}
	else if (idTranslatedDict != WORD_NOT_FOUND)
	{
		std::cout << "Translation found with endNode address: \t\t0x" << this->IdHashesUMap[idTranslatedDict].first << std::endl;
		return this->TranslatedWords->GetTranslation(this->IdHashesUMap[idTranslatedDict].first);
	}

	std::cout << "Translation not found..." << std::endl;
	return "";
}

