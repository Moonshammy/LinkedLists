#include <stdio.h>
#include <stdlib.h>

#include "linked_list_tail.h"

static Node* head;
static Node* tail;
static int size;

Node* new_node(int data){
    Node* new = calloc(1, sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}
void insert_node(Node* node){
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

void insert_node_index(Node* node, int index){
    Node* curr = head;
    Node* prev;
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

void insert_node_sorted(Node* node){
    Node* curr = head;
    Node* prev;
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
Node* pop_node(){
    Node* curr = head;
    if(head == NULL){
        return NULL;
    }
    head = head->next;
    size--;
    return curr;
}

Node* remove_node(Node* node);
Node* remove_node_index(int index);
Node* remove_node_data(int data);
Node* remove_last_node();


int get_list_size(){
    return size;
}

void print_list(){
    Node* curr = head;
    for (int i = 0; i < get_list_size(); i++){
        printf("index at %d = %d\n", i, curr->data);
        curr = curr->next;
    }
}

void free_nodes(){
    Node* freeNode;
    freeNode = head;
    while (freeNode != NULL){
        freeNode = pop_node();
        free(freeNode);
    }
}

int main(){
    int arr[10] = {2, 5, 7, 12, 4, 3, 6, 18, 20};
    for (int i = 0; i < 9; i++){
        Node* new = new_node(arr[i]);
        insert_node(new);
    }

    print_list();
    printf("%d\n", get_list_size());
    free_nodes();
}