#include "../include/list.h"

int main() {
    Node* list = init_list();

    int* testdata = (int*)malloc(sizeof(int));
    *testdata = 10;

    int* testdata2 = (int*)malloc(sizeof(int));
    *testdata2 = 20;

    int* testdata3 = (int*)malloc(sizeof(int));
    *testdata3 = 30;

    int err = list_add(list, (void*)testdata);
    if (err == -1) {
        puts("failed list_add, no new node added");
        return err;
    }

    err = list_add(list, (void*)testdata2);
    if (err == -1) {
        puts("failed list_add, no new node added");
        return err;
    }

    err = list_add(list, (void*)testdata3);
    if (err == -1) {
        puts("failed list_add, no new node added");
        return err;
    }

    print_list(list, 0);

    list_rm(&list, (void*)testdata);

    print_list(list, 0);

    if (destroy_list(list) == -1) {
        puts("destroy list failed, memory leak!!!!");
        return -1;
    }

    return 0;
}
















