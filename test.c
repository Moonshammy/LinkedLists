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
    int value = ll_insert(NULL, 0, 0);
    test_bad_input(-1, value);
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    value = ll_insert(list, -1, 0);
    test_bad_input(-1, value);
    value = ll_insert(list, 11, 0);
    free(list);
}

void test_insert(void){
    Linked_List *list = ll_create_data(0);
    for (int i = 1; i < 10; i++){
        ll_push(list, i);
    }
    ll_insert(list, 5, -1);
    size_t size = ll_get_size(list);
    char* values = ll_to_string(list);
    printf("\nTESTING: test_value_one_list\n");
    test_size(10u, size);
    test_string("[0,1,2,3,-1,5,6,7,8,9]", values);
    free(list);
}

int main(void){
    test_empty_list();
    test_value_one_list();
    test_ten_values_initial_zero();
    test_insert_bad_inputs();
    test_insert();
}