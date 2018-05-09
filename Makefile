# CSE 374 Makefile exampmle for the talk/speak/shout program.

# The compiler: gcc for C programs
CC = gcc

# Compiler flags:
# -Wall for debugger warnings
# -std=c11 for updated standards
# -g for debugging info
CFLAGS = -Wall -std=c11 -g

# The name of the program that we are producing.
TARGET = t9

# When we just run "make", what gets built? This is a "phony" target
# that just tells make what other targets to build.
all: $(TARGET)

# All the .o files we need for our executable.
OBJS = t9.o t9Function.o StringListNode.o t9TrieNode.o 

# The executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o t9 $(OBJS)

# Individual source files
t9.o: t9.c t9.h t9Function.c StringListNode.c StringListNode.h t9TrieNode.c t9TrieNode.h
	$(CC) $(CFLAGS) -c t9.c

t9Function.o: t9Function.c t9.h StringListNode.h t9TrieNode.h
	$(CC) $(CFLAGS) -c t9Function.c

StringListNode.o: StringListNode.c StringListNode.h
	$(CC) $(CFLAGS) -c StringListNode.c

t9TrieNode.o: t9TrieNode.c StringListNode.h t9TrieNode.h
	$(CC) $(CFLAGS) -c t9TrieNode.c


# A "phony" target to remove built files and backups
clean:
	rm -f *.o t9 *~
