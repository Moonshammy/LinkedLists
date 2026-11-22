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
    LL_Node* curr = list->head;
    for (int i = 1; i < index; i++){
        curr = curr->next;
    }
    curr->data = data;
    return 0;
}

size_t ll_get_size(Linked_List* list){
    if(!list){
        return -1;
    }
    return list->size;
}

char* ll_to_string(Linked_List* list){
    if (!list){
        return "";
    }
    if (list->head == NULL){
        return "[]";
    }
    size_t string_size = list->size * 2 + 1; //*2 adds space for commas (+1 size, use for left bracked), +1 for right bracket 
    char* string = calloc(string_size, sizeof(char));
    LL_Node* curr = list->head;
    string[0] = '[';
    for(size_t i = 1; i < string_size; i+=2){
        string[i] = curr->data+48;
        string[i+1] = ',';
        curr = curr->next; 
    }
    string[string_size - 1] = ']';
    return string;
}

void ll_destroy(Linked_List* list){
    if(!list){
        return;
    }
    LL_Node* curr = list->head;
    LL_Node* tmp;
    if (curr != NULL){
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(list);
}