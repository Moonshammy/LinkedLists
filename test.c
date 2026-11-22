#include <stdio.h>
#include <string.h>

#include "linked_list.h"

void test_size(size_t expected, size_t actual){
    printf("  size: ");
    if (actual == expected){
        printf("Passed\n");
    }
    else{
        printf("Failed expected %zu actual: %zu\n", expected, actual);
    }
}

void test_string(char* expected, char* actual){
    printf("  Testing list values: ");
    if (!strcmp(expected, actual)){
        printf("Passed\n");
    }
    else{
        printf("Failed, expected %s actual: %s\n", expected, actual);
    }
}

void test_bad_input(int expected, int actual){
    printf("  Testing bad input: ");
    if (expected == actual){
        printf("Passed\n");
    }
    else{
        printf("Failed expected %d actual: %d\n", expected, actual);
    }
}

void test_value(int expected, int actual){
    printf("  Testing value: ");
    if (expected == actual){
        printf("Passed\n");
    }
    else{
        printf("Failed, expected %d actual: %d\n", expected, actual);
    }
}

void test_empty_list(void){
    printf("\nTESTING test_empty_list\n");
    Linked_List *list = ll_create();
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    test_size(0u, size);
    test_string("[]", values);
    free(list);
}

void test_value_one_list(void){
    Linked_List *list = ll_create_data(1);
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    printf("\nTESTING: test_value_one_list\n");
    test_size(1u, size);
    test_string("[1]", values);
    free(list);
}

void test_ten_values_initial_zero(void){
    Linked_List *list = ll_create();
    for (int i = 0; i < 10; i++){
        ll_push(list, i);
    }
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    printf("\nTESTING: test_ten_values_initial_zero\n");
    test_size(10u, size);
    test_string("[0,1,2,3,4,5,6,7,8,9]", values);
    free(list);
}

void test_ten_values_initial_value(void){
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    printf("\nTESTING: test_ten_values_initial_value\n");
    test_size(10u, size);
    test_string("[0,1,2,3,4,5,6,7,8,9]", values);
    free(list);
}

void test_insert_bad_inputs(void){
    printf("\nTESTING: test_insert_bad_inputs\n");
    int value = ll_insert(NULL, 0u, 0);
    test_bad_input(-1, value);
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    value = ll_insert(list, 11u, 0);
    free(list);
}

void test_insert(void){
    printf("\nTESTING: test_value_one_list\n");
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    ll_insert(list, 5u, 9);
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    test_size(10u, size);
    test_string("[0,1,2,3,9,5,6,7,8,9]", values);
    free(list);
}

void test_insert_head(void){
    printf("\nTESTING: test_value_insert_head\n");
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    ll_insert(list, 0u, 9);
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    test_size(10u, size);
    test_string("[9,1,2,3,4,5,6,7,8,9]", values);
    free(list);
}

void test_insert_end(void){
    printf("\nTESTING: test_value_insert_end\n");
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    ll_insert(list, 10u, 9);
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    test_size(11u, size);
    test_string("[0,1,2,3,4,5,6,7,8,9,9]", values);
    free(list);
}

void test_get_data(void){
    printf("\nTESTING: test_get_data\n");
    int x = 0;
    int* value = &x;
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    ll_get_data(list, 4, value);
    test_value(4, *value);
    ll_get_data(list, 0, value);
    test_value(0, *value);
    ll_get_data(list, 9, value);
    test_value(9, *value);
    size_t size = ll_get_size(list);
    test_size(10u, size);
}

void test_pop(void){
    printf("\nTESTING: test_pop\n");
    int x = 0;
    int* value = &x;
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    ll_pop(list, value);
    test_value(9, *value);
    size_t size = ll_get_size(list);
    test_size(9u, size);
    for (int i = 0; i < 8; i++){
        ll_pop(list, value);
    }
    size = ll_get_size(list);
    test_size(1u, *value);
    test_value(1, *value);

    ll_pop(list, value);
    size = ll_get_size(list);
    test_size(0u, size);
    test_value(0, *value);
    x = ll_pop(list, value);
    test_bad_input(-1, x);
    x = ll_pop(NULL, value);
    test_bad_input(-1, x);
}


int main(void){
    test_empty_list();
    test_value_one_list();
    test_ten_values_initial_zero();
    test_insert_bad_inputs();
    test_insert();
    test_insert_head();
    test_insert_end();
    test_get_data();
    test_pop();
}