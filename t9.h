/*
  File: t9.h
  Purpose: header file for t9Functions, provide needed file conncection and fuction declearation
  Shawn Xu 
*/

#include "StringListNode.h"
#include "t9TrieNode.h"

#ifndef T9_H
#define T9_H

// interact with user and find/present list of word
int interaction(t9TrieNode* head, StringListNode** cur);

#endif


