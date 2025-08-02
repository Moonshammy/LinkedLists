#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

static Node* head;
static int list_size;

Node* new_node(int data){
    Node* newNode = calloc(1, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}

void insert_node(Node* node){
    Node* curr = head;
    if (head == NULL){
        head = node;
        list_size = 1;
    }
    else{
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
        list_size++;
    }
}

void insert_node_index(Node* node, int index){
    Node* curr = head;
    Node* prev;
    if (get_list_size() < index){
        printf("Index %d out of range\n", index);
    }
    else if (head == NULL){
        head = node;
    }
    else if (index == 0){
        node->next = curr;
        head = node;
    }
    else{
        for (int i = 0; i < index; i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = node;
        node->next = curr;
    }
}

void insert_node_sorted(Node* node){
    Node* curr = head;
    Node* prev;
    if (head == NULL){
        head = node;
        list_size++;
    }
    //If node at 0 case;
    else if(head->data > node->data){
        node->next = head;
        head = node;
        list_size++;
    }
    else {
        while (curr->data < node->data && curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        node->next = curr;
        prev->next = node;
        list_size++;
    }
}

//On success, return Node. On failure return NULL
//Any Node not re-inserted MUST BE free(node);

Node* pop_node(){
    if (head != NULL){
        Node* node = head;
        head = head->next;
        list_size--;
        return node;
    }
    return NULL;
}

//Return removed Node
Node* pop_last_node(){
    Node* curr = head;
    Node* prev;
    if (head == NULL){
        return NULL;
    }
    else if (head->next == NULL){
        head == NULL;
        list_size--;
        return NULL;
    }

    while (curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    list_size--;
    return curr;
}

Node* remove_node(Node* node){
    Node* curr = head;
    Node* prev;
    if (head != NULL){
        //Checking if head matches. There is no prev node, so the following loop wouldn't work.
        if (node == curr){
            head = curr->next;
            list_size--;
            return curr;
        }
        while (curr != NULL){
            if (node->data == curr->data){
                prev->next = curr->next;
                return curr;
            }
            prev = curr;
        }
    }
}

Node* remove_node_index(int index){
    Node* curr = head;
    Node* prev;
    if (head == NULL){
        printf("No Nodes in the list\n");
        return NULL;
    }
    else if (index == 0){
        head = head->next;
        list_size--;
        return curr;
    }
    else if (get_list_size() < index){
        printf("Index %d is out of range\n", index);
        return NULL;
    }
    for (int i = 0; i < index; i++){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    list_size--;
    return curr;
}

Node* remove_node_data(int data){
    Node* curr = head;
    Node* prev;
    if (head == NULL){
        printf("No data in list");
        return NULL;
    }
    else if(head->data == data){
        head = head->next;
        list_size--;
        return curr;
    }
    else{
        while (curr->data != data){
            prev = curr;
            curr = curr->next;
            if(curr== NULL){
                printf("Data: %d, was not in the list\n", data);
                return NULL;
            }
        }
        prev->next = curr->next;
        list_size--;
        return curr;
    }
}

int get_list_size(){
    return list_size;
}

void print_list(){
    Node* curr = head;
    int i = 0;
    while(curr != NULL){
        printf("index at %d = %d\n", i, curr->data);
        i++;
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
    int arr[10] = {2, 5, 7, 12, 4, 3, 6, 18, 20, 10};
    for (int i = 0; i < 10; i++){
        Node* new = new_node(arr[i]);
        insert_node(new);
    }

    print_list();
    free_nodes();
}