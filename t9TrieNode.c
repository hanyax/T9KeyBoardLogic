/*
  File: t9TrieNode.c
  Purpose: function implementations that can be operate on Trie data strcuture
  Shawn Xu 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include "t9TrieNode.h"
#include "StringListNode.h"

void wordToDigit(char* word, char* digit);
void freeHelper(t9TrieNode* node);
int checkNode(t9TrieNode* node);
FILE* fr;

/*
  Make and return a TrieNode contains words and a 10 member array 
  with all NULL value
*/
t9TrieNode* makeTrieNode(char* word, int charIndex) {
  t9TrieNode* n = (t9TrieNode*) malloc(sizeof(t9TrieNode));
  if (n) {
    n->words = NULL;
    t9TrieNode** array = malloc(10*sizeof(t9TrieNode));
    for (int i = 0; i < 10; i++) {
      array[i] = NULL;
    }
    n->children= array;
  }
  return n;
}

/*
  Make a new t9TrieNode and insert it into the Trie with root head
*/
void insertWord(char* word, t9TrieNode* head) {
  t9TrieNode* cur = head;
  char* digit = (char*) malloc((strlen(word) + 1) * sizeof(char));
  wordToDigit(word, digit);

  for (int i = 0; i < strlen(word); i++) {
    int index =  digit[i] - '0';
    t9TrieNode** array = cur->children;
    if (array[index] == NULL) {
      array[index] = makeTrieNode(word, i);
    }
    cur = array[index];
  }
  if (cur->words != NULL) {
    insertSLN(word, cur->words);
  } else {
    cur->words = makeSLN(word, NULL);
  }
  free(digit);
}

// Helper mathod to print all non-null children ov a t9TrieNode
void printTrie(t9TrieNode* node) {
  t9TrieNode** array = node->children;
  for (int i = 0; i < 10; i++) {
    if (array[i] != NULL) {
      printf("index: %d ", i);
    }
  }
  printf("done\n");
}

// Helper method to translate a word into digit based on T9 rules
void wordToDigit(char* word, char* digit) {
  for (int i = 0; i < (strlen(word)); i++) {
    if (word[i] <= 'c') {
      digit[i] = '2';
    } else if (word[i] <= 'f') {
      digit[i] = '3';
    } else if (word[i] <= 'i') {
      digit[i] = '4';
    } else if (word[i] <= 'l') {
      digit[i] = '5';
    } else if (word[i] <= 'o') {
      digit[i] = '6';
    } else if (word[i] <= 's') {
      digit[i] = '7';
    } else if (word[i] <= 'v') {
      digit[i] = '8';
    } else {
      digit[i] = '9';
    }
  }
  digit[strlen(word)] = '\0';
}

// Build a entire Trie from a file
void makeTrie(char* fileName, t9TrieNode* head) {
  if (access(fileName, F_OK) != 0) {
    fprintf(stderr, "Word file does not exist. \n");
    exit(EXIT_FAILURE);
  }

  // Open File
  fr = fopen(fileName, "r");
  char input[MAX_CHAR];
  while (fgets(input, MAX_CHAR, fr) != NULL) {
    input[strlen(input)-1] = '\0';
    insertWord(input, head);
  }
  fclose(fr);
}

// Free a entire Trie start from head from memery
void freeTrie(t9TrieNode* head) {
  freeHelper(head);
}

// Free helper to free the t9Trienode and its children from memory
void freeHelper(t9TrieNode* node) {
  if (node == NULL) {
    return;
  } else {
    for (int i = 0; i < 10; i++) {
      freeHelper((node->children)[i]);
    }
    freeList(node->words);
    free(node->children);
    free(node);
  }
}
