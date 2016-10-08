#pragma once

#ifndef GUID_GENERATOR
#define GUID_GENERATOR

namespace wordMaster
{
	class GuidGenerator
	{
	public:
		GuidGenerator();
		~GuidGenerator();

		int					GetHash();
		bool				FreeHash(int hashNumber);
		void				ResetHashes();
	private:
		const static int	BASE = (1 << 20);
		const static int	TREE_SIZE = (1 << 21);
		const static int	INF = (1 << 31) - 1;
		int					*IntervalTree;

		void				UpdateAllNodes(int _node = 1, int _from = 1, int _to = BASE);
		void				UpdateUpsideFromNode(int hashNumber);
	};
}

#endif
