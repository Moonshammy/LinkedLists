#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct LL_Node LL_Node;
typedef struct Linked_List Linked_List;

Linked_List* ll_create(void);
Linked_List* ll_create_data(int data);
LL_Node* ll_new_node(int data);
int ll_push(Linked_List* list, int data);
int ll_pop(Linked_List* list, int *out);
int ll_insert(Linked_List* list, size_t index, int data);
int ll_get_data(Linked_List* list, size_t index, int* out);


size_t ll_get_size(Linked_List* list);
char* ll_to_string(Linked_List* list);

void ll_destroy(Linked_List* list);
#endif