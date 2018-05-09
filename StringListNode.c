/*
  File: StringListNode.c
  Purpose: function implementations that can be operate on StringList data strcuture
  Shawn Xu 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StringListNode.h"

// Make a single stringlistnode and return it
// Assign data to word field, assign next to next field
StringListNode* makeSLN(char* data, StringListNode* next) {
  StringListNode* n = (StringListNode*) malloc(sizeof(StringListNode));
  if (n) {
    strcpy(n->word, data);
    n->next = next;
  }
  return n;
}

// Make a stringlistnode with data as word
// and insert it to stringlist start with head
void insertSLN(char* data, StringListNode* head) {
  StringListNode* cur = head;
  if (strcmp((head->word), data) == 0) {
    return;
  }
  while (cur->next != NULL) {
    cur = cur->next;
  }
  if (strcmp((cur->word), data) == 0) {
    return;
  }
  StringListNode* n = makeSLN(data, NULL);
  cur->next = n;
}

// Free a string list with start with head from memeory
void freeList(StringListNode* head) {
  while (head != NULL) {
    StringListNode* next = head->next;
    free(head);
    head = next;
  }
}

// Helper method: print entire stringlist start from head
void printList(StringListNode* head) {
  StringListNode* cur = head;
  if (head == NULL) {
    printf("NULL \n");
  }
  while (cur != NULL) {
    printf("Node value: %s \n", cur->word);
    cur = cur->next;
  }
}
