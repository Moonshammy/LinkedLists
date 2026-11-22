#include <stdio.h>

#include "linked_list.h"

int main(void){
    Linked_List *list = ll_new(1);
    printf("Size: %d\n", ll_get_size(list));
    ll_print(list);
    for (int i = 0; i < 8; i++){
        ll_push(list, i);
    }
    printf("Size: %d\n", ll_get_size(list));
    ll_print(list);
}