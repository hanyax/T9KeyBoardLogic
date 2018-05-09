/*
  file: t9.c
  Purpose: Translate user input numbers into list of words based on T9 type keyboard and interact with user using interactive command line instruction.
  Shawn Xu
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "t9.h"
#include "StringListNode.h"
#include "t9TrieNode.h"

int main(int argc, char* argv[]) {
  // Check input file
  if (argc == 1) {
    fprintf(stderr, "Need to provide word file \n");
    exit(EXIT_FAILURE);
  }

  // Build Tries from file
  t9TrieNode* head = makeTrieNode("", 0);
  makeTrie(argv[1], head);
  StringListNode* curString = NULL;

  // Start interaction
  printf("Enter \"exit\" to quit. \n");
  while ( interaction(head, &curString) != 1) {};

  // free all allocation before exit
  freeTrie(head);
  exit(EXIT_SUCCESS);
}
