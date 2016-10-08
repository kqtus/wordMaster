#include "stdafx.h"
#include "TrieNode.h"
#include <iostream>

wordMaster::TrieNode::TrieNode()
{
	this->Predecessor = NULL;

	this->PtrArray = new TrieNode*[ALPHABET_LENGTH];

	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{
		this->PtrArray[i] = NULL;
	}

	int id = 0;
}

wordMaster::TrieNode::~TrieNode()
{
	delete[] this->PtrArray;
}

void wordMaster::TrieNode::SetId(int id)
{
	this->_id = id;
}

int wordMaster::TrieNode::GetId()
{
	return this->_id;
}

void wordMaster::TrieNode::SetPredecessor(wordMaster::TrieNode* pred)
{
	this->Predecessor = pred;
}

wordMaster::TrieNode* wordMaster::TrieNode::GetPredecessor()
{
	return Predecessor;
}

void wordMaster::TrieNode::SetFlag(char flag)
{
	this->_flag = flag;
}

char wordMaster::TrieNode::GetFlag()
{
	return this->_flag;
}

wordMaster::TrieNode*& wordMaster::TrieNode::operator[](const char letter)
{
	return *&this->PtrArray[(size_t)letter - 'a'];
}