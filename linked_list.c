#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct Linked_List{
    int data;
    Linked_List* next;
    size_t* size;
} Linked_List;

static Linked_List* head;
static int list_size;

Linked_List* ll_new(int data){
    Linked_List *head = calloc(1, sizeof(Linked_List));
    size_t *size_location = calloc(1, sizeof(size_t));
    head->size = size_location;
    *head->size = 1;
    head->next = NULL;
    head->data = data;
    return head;
}

Linked_List* ll_new_node(int data){
    Linked_List* new_node = calloc(1, sizeof(Linked_List));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int ll_push(Linked_List* list, int data){
    if (!list){
        return -1;
    }
    Linked_List* curr = list;
    Linked_List* node = ll_new_node(data);
    node->size = list->size;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = node;
    *list->size += 1;
    return 0;
}

int ll_insert(Linked_List* list, int index, int data){
    if(!list){
        return -1;
    }
    if (index >= (int)*list->size || index < 0){
        return -1;
    }
    if (index || data){}
    return -1;
}

size_t ll_get_size(Linked_List* list){
    return list->size;
}

void ll_print(Linked_List* list){
    if (!list){
        return;
    }
    Linked_List* curr = list;
    printf("[");
    while(curr != NULL){
        if (curr->next == NULL){
            printf("%d", curr->data);
        }
        else{
            printf("%d,", curr->data);
        }
        curr = curr->next;
    }
    printf("]\n");
}