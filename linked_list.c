#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct LL_Node{
    int data;
    LL_Node* next;
} LL_Node;
typedef struct Linked_List{
    LL_Node* head;
    size_t size;
} Linked_List;

Linked_List* ll_create(void){
    Linked_List* list = calloc(1, sizeof(Linked_List));
    list->head = NULL;
    list->size = 0;
    return list;
}

Linked_List* ll_create_data(int data){
    Linked_List *list = calloc(1, sizeof(Linked_List));
    LL_Node* head = ll_new_node(data);
    list->size = 1;
    list->head = head;
    return list;
}

LL_Node* ll_new_node(int data){
    LL_Node* node = calloc(1, sizeof(Linked_List));
    node->data = data;
    node->next = NULL;
    return node;
}

int ll_push(Linked_List* list, int data){
    if (!list){
        return -1;
    }
    LL_Node* curr = list->head;
    LL_Node* node = ll_new_node(data);
    if (curr == NULL){
        list->head = node;
    }
    else{
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
    }
    list->size += 1;
    return 0;
}

int ll_insert(Linked_List* list, int index, int data){
    if(!list){
        return -1;
    }
    if (index >= (int)list->size || index < 0){
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
    LL_Node* curr = list->head;
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