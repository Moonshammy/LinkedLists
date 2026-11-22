#include <stdio.h>
#include <stdlib.h>

#include "linked_list_tail.h"

typedef struct Linked_List{
    int data;
    struct Linked_List* next;
} Linked_List;

static Linked_List* head;
static Linked_List* tail;
static int size;

Linked_List* ll_new_node(int data){
    Linked_List* new = calloc(1, sizeof(Linked_List));
    new->data = data;
    new->next = NULL;
    return new;
}
void insert_node(Linked_List* node){
    if (head == NULL){
        head = node;
        tail = node;
        size=1;
    }
    else{
        tail->next = node;
        tail = node;
        node->next = NULL;
        size++;
    }
}

void insert_node_index(Linked_List* node, int index){
    Linked_List* curr = head;
    Linked_List* prev;
    if (index > get_list_size()){
        printf("Index out of range\n");
    }   
    else if (head == NULL){
        head = node;
        tail = node;
        size=1;
    }
    else if (index == 0){
        node->next = head;
        head = node;
        size++;
    }
    else if (index == get_list_size()){
        tail->next = node;
        tail = node;
        node->next = NULL;
        size++;
    }
    else{
        for (int i = 0; i < index; i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
        size++;
    }
}

void insert_node_sorted(Linked_List* node){
    Linked_List* curr = head;
    Linked_List* prev;
    if (head == NULL){
        head = node;
        tail = node;
    }
    else if (head->data >= node->data){
        node->next = head;
        head = node;
    }
    else{
        while (curr->data < node->data && curr != tail){
                prev = curr;
                curr = curr->next;
        }
        if (curr == tail && curr->data < node->data){
            tail->next = node;
            tail = node;
        }
        else{
            node->next = curr;
            prev->next = node;
        }
    }
    size++;
}

//On success, return Node. On failure return NULL
Linked_List* pop_node(){
    Linked_List* curr = head;
    if(head == NULL){
        return NULL;
    }
    head = head->next;
    size--;
    return curr;
}

Linked_List* pop_last_node(){
    Linked_List* curr = head;
    Linked_List* prev;
    if(head == NULL){
        printf("Error: Cannot pop, no nodes in list");
        return NULL;
    }
    if (head == tail){
        head == NULL;
        tail == NULL;
        size--;
        return NULL;
    }
    while(curr != tail){
        prev = curr;
        curr = curr->next; 
    }
    tail = prev;
    tail->next = NULL;
    size--;
    return curr;
}

Linked_List* remove_node(Linked_List* node){
    Linked_List* curr = head;
    Linked_List* prev;
    if (head == NULL){
        printf("Error: Cannot remove Node, no nodes in list");
        return NULL;
    }
    else if (head == node){
        head = head->next;
        size--;
        return curr;
    }
    else if (head == tail){
        head == NULL;
        tail == NULL;
        size--;
        return curr;
    }
    while (curr != node && curr!= tail){
        prev = curr;
        curr = curr->next;
    }
    if(curr == tail){
        tail = prev;
        tail->next = NULL;
        size--;
        return curr;
    }
    prev->next = curr->next;
    size--;
    return curr;
}


//TODO
Linked_List* remove_node_index(int index){
    if (head == NULL){

    }
    else if (index > get_list_size()){
        printf("Error: Index out of range for remove node index");
        return NULL;
    }
}

//TODO
Linked_List* remove_node_data(int data);


int get_list_size(){
    return size;
}

void print_list(){
    Linked_List* curr = head;
    for (int i = 0; i < get_list_size(); i++){
        printf("index at %d = %d\n", i, curr->data);
        curr = curr->next;
    }
}

void free_nodes(){
    Linked_List* freeNode;
    freeNode = head;
    while (freeNode != NULL){
        freeNode = pop_node();
        free(freeNode);
    }
}