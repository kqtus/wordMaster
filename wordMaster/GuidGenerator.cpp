#include "stdafx.h"
#include "GuidGenerator.h"
#include <iostream>
#include <algorithm>

wordMaster::GuidGenerator::GuidGenerator()
{
	IntervalTree = new int[TREE_SIZE];
	this->ResetHashes();
}

wordMaster::GuidGenerator::~GuidGenerator()
{
	delete[] this->IntervalTree;
}

int wordMaster::GuidGenerator::GetHash()
{
	int newHash = this->IntervalTree[1];
	this->IntervalTree[BASE + newHash - 1] = INF;
	this->UpdateUpsideFromNode(newHash);
	return newHash;
}

bool wordMaster::GuidGenerator::FreeHash(int hashNumber)
{
	this->IntervalTree[BASE + hashNumber - 1] = hashNumber;
	this->UpdateUpsideFromNode(hashNumber);
	return true;
}

void wordMaster::GuidGenerator::ResetHashes()
{
	for (int i = 0; i < TREE_SIZE; i++)
	{
		this->IntervalTree[i] = INF;
	}

	this->UpdateAllNodes();
}

void wordMaster::GuidGenerator::UpdateAllNodes(int _node, int _from, int _to)
{
	if (_from > _to)
	{
		return;
	}
	
	if (_from == _to)
	{
		this->IntervalTree[_node] = _from;
		return;
	}
	this->UpdateAllNodes(_node * 2, _from, (_from + _to) / 2);
	this->UpdateAllNodes(_node * 2 + 1, (_from + _to) / 2 + 1, _to);

	this->IntervalTree[_node] = std::min(this->IntervalTree[_node * 2], this->IntervalTree[_node * 2 + 1]);
}

void wordMaster::GuidGenerator::UpdateUpsideFromNode(int hashNumber)
{
	int _base = (hashNumber + BASE - 1) / 2;

	while (_base > 0)
	{
		this->IntervalTree[_base] = std::min(this->IntervalTree[_base * 2], this->IntervalTree[_base * 2 + 1]);
		_base /= 2;
	}
}