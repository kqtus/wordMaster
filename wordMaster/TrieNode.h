#pragma once

#ifndef TRIE_NODE
#define TRIE_NODE

namespace wordMaster 
{
	class TrieNode 
	{
	public:
		TrieNode();
		~TrieNode();

		void				SetId(int id);
		int					GetId();
		void				SetPredecessor(TrieNode* pred);
		TrieNode*			GetPredecessor();
		void				SetFlag(char flag);
		char				GetFlag();
		void				IncThickness();
		void				DecThickness();
		int					GetThickness();
		TrieNode*&			operator[](const char letter);
	private:
		const static int	ALPHABET_LENGTH = 32;
		int					_id;
		int					_thickness;
		char				_flag;
		TrieNode			**PtrArray;
		TrieNode			*Predecessor;
	};
}
#endif
