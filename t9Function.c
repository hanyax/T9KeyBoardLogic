/*
  File: t9Function.c
  Purpose: function implementations for t9.c 
  Shawn Xu 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "t9.h"

int findBound(char* input);

// Take pre-build Trie and interact with user/ find the words
int interaction(t9TrieNode* head, StringListNode** curString) {
  printf("Enter Key Sequence (or \"#\" for next word): \n");
  char input[MAX_CHAR];
  scanf("%s", input);
  if ( feof(stdin) || (strcmp(input, "exit") == 0) ) {
    return 1;
  } else {
    // input start with # -> load previous
    if (input[0] == '#') {
      if (*curString == NULL) {
        printf("There are no more t9onyums \n");
        return 0;
      } else {
        for (int i = 0; i < strlen(input)-1; i++) {
          if ( (input[i] == '#')  && ((*curString)->next != NULL) ) {
            *curString=(*curString)->next;
          } else {
            printf("There are no more T9onyums \n");
            return 0;
          }
      }
        printf("%s \n", (*curString)->word);
        *curString=(*curString)->next;
      }
      // input start with number -> load new cur
    } else {
      if ( input[0] < '0' || input[0] > '9' ) {
        printf("Please enter a number \n");
        return 0;
      }

      int bound = findBound(input);
      t9TrieNode* curTrie = head;
      for (int i = 0; i < bound; i++) {
        if ((curTrie->children)[(input[i]-'0')] != NULL) {
          curTrie=(curTrie->children)[(input[i]-'0')];
        } else {
          printf("Not found in current dictionary. \n");
          return 0;
        }
      }

      // load new cur string;
      if (curTrie->words == NULL) {
        printf("Not found in current dictionary. \n");
        return 0;
      }

      *curString = curTrie->words;
      for (int j = bound; j < strlen(input); j++) {
        if ((*curString)->next != NULL) {
          (*curString)=(*curString)->next;
        } else {
          printf("There are no more T9noyms \n");
          (*curString) = NULL;
          return 0;
        }
      }

      printf("%s \n", (*curString)->word);
      (*curString)=(*curString)->next;
    }
    return 0;
  }
}

// Return the index of the first '#' in the input
int findBound(char* input) {
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == '#') {
      return i;
    }
  }
  return strlen(input);
}



