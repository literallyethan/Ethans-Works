#include "../include/list.h"

int main() {
    Node* list = init_list();

    int* testdata = (int*)malloc(sizeof(int));
    *testdata = 10;
    int err = list_add(list, (void*)testdata);
    if (err == -1) {
        puts("failed list_add, no new node added");
        return -1;
    }

//  printf("test value in new node: %d\n", ((int*)(list->next->data))[0]);
    print_list(list, 0);


    if (destroy_list(list) == -1) {
        puts("destroy list failed, memory leak!!!!");
        return -1;
    }

    return 0;
}
















