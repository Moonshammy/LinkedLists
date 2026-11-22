#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct Linked_List Linked_List;

Linked_List* ll_create_data(int data);
Linked_List* ll_new_node(int data);
int ll_push(Linked_List* list, int data);
int ll_insert(Linked_List* list, int index, int data);

size_t ll_get_size(Linked_List* list);

void ll_print(Linked_List* list);



#endif