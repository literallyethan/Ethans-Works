#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

//NOTE: all int functions return -1 on fail, 0 on success.
//      pointer functions return NULL on fail.

//NOTE: currently, if you have 2 nodes with the same data pointer,
//      destroying the list creates a double free.
//      prevent this.
//
//      This is a problem not contained in destroy_list.
//      for now dont use dupe data until I can make a mechanism
//      to prevent this.

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

// remove a node by value. If duplicates,
// remove earliest node with given value.
int list_rm(Node** list, void* data);

// get some data
void* get_data(Node* node);

// get next node
Node* get_next(Node** node);

//set next node
int set_next(Node** node, Node* next);

// change some data

// print list.
// pass 0 to print int, pass 1 to print strings
void print_list(Node* list, int16_t arg);

// free all nodes in list, starting at the given node
int destroy_list(Node* list);

#endif
