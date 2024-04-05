#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

//NOTE: all int functions return -1 on fail, 0 on success.
//      pointer functions return NULL on fail.

// initialize a list, creating a head with empty data
Node* init_list();

// add a node.
// user is expected to know what data type goes into each void*,
// as this function does not cast data at all.
// make sure that the value you make data is an allocated
// pointer of a type, and that you cast it back into the
// expected type on use.
// when you pass a pointer into this function, you need to cast it to void.
int list_add(Node* list, void* data);

// remove a node

// get some data

// change some data

// print list.
// pass 0 to print int, pass 1 to print strings
void print_list(Node* list, int16_t arg);

// free all nodes in list, starting at the given node
int destroy_list(Node* list);

#endif
