/*
  File: StringListNode.h
  Purpose: Header file for StringListNode: define StringListNode, provide fucntion prototype and define constant 
  Shawn Xu 
*/

#ifndef STRINGLISTNODE_H
#define STRINGLISTNODE_H

#define MAX_CHAR 100

typedef struct StringListNode {
  char word[MAX_CHAR];
  struct StringListNode* next;
} StringListNode;

// fuctions implemented for StringListNode
StringListNode* makeSLN(char* word, StringListNode* next);
void insertSLN(char* data, StringListNode* head);
void freeList(StringListNode* head);

#endif
