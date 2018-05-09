/*
  File: t9TrieNode.c
  Purpose: Header file for t9TrieNode, define t9TrieNode data structure, provide function prototype
  Shawn Xu 
*/

#ifndef T9TRIENODE_H
#define T9TRIENODE_H

#include "StringListNode.h"

typedef struct t9TrieNode {
  StringListNode* words;
  struct t9TrieNode** children;
} t9TrieNode;

// functions implemented for t9Trie
void makeTrie(char* fileName, t9TrieNode* head);
t9TrieNode* makeTrieNode(char* word, int charIndex);
void insertWord(char* word, t9TrieNode* head);
void freeTrie(t9TrieNode* head);

#endif
