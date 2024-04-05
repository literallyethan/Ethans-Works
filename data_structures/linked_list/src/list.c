#include "../include/list.h"

struct Node {
    void* data; // void* for data type flexibility
    Node* next;
};

Node* init_list() {
    // malloc space for the head of a node with empty data
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        puts("init_list failed to malloc.");
        return NULL;
    }

    head->data = NULL;
    head->next = NULL;

    return head;
}

int list_add(Node* list, void* data) {
    // malloc a new node
    // set data for new node
    // set next to null

    if (list == NULL) {
        puts("Given list is NULL.");
        return -1;
    }

    if (data == NULL) {
        puts("Given data is NULL.");
        return -1;
    }

    Node* current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (Node*)malloc(sizeof(Node));
    if (list->next == NULL) {
        puts("list_add malloc failed");
        return -1;
    }

    current->next->data = data;
    current->next->next = NULL;

    return 0;
}

int list_rm(Node** node) {
    if (node == NULL) {
        puts("node cannot be null.");
        return -1;
    }

    if (*node == NULL) {
        puts("node cannot be null.");
        return -1;
    }

    if ((*node)->next == NULL) {
        //the only node, or the last node
        free(node);
        node = NULL;
        return 0;
    }

    Node* next_node = (*node)->next;
    free(*node);
    *node = next_node;

    return 0;
}
/*
Node* get_next(Node* node) {
    if (node == NULL) {
        puts("node cannot be null.");
        return NULL;
    }

    if (node->next == NULL) {
        puts("next node cannot be NULL");
        return NULL;
    }

    return node->next;
}

int set_next(Node** node, Node* next) {
    if (node == NULL) {
        puts("node cannot be null.");
        return -1;
    }

    if (*node == NULL) {
        puts("node cannot be null.");
        return -1;
    }

    if (next == NULL) {
        puts("next node cannot be NULL, you tryna memory leak??");
        return -1;
    }

    (*node)->next = next;

    return 0;
}
*/
void print_list(Node* list, int16_t arg) {
    if (list == NULL) {
        puts("cannot print a null list.");
        return;
    }

    Node* current = list;
    uint64_t node_num = 0;

    while (current != NULL) {
        if (arg == 0 && current->data != NULL) {
            printf("Node #%d\n\tdata: %d\n", node_num++, *((int*)(current->data)));
        } else {
            printf("Node #%d\n\tdata: %s\n", node_num++, current->data);
        }

        current = current->next;
    }
    printf("\n\n");
}

int destroy_list(Node* list) {
    if (list == NULL) {
        puts("Given list is NULL.");
        return -1;
    }

    // free nodes until current node is NULL
    Node* next_tracker = NULL;
    Node* current = list; // starts at given list node

    // if current node is NULL, stop
    while (current != NULL) {
        next_tracker = current->next;
        if (current->data != NULL) free(current->data);
        free(current);
        current = next_tracker;
    }

    puts("List destroyed from given node.");

    return 0;
}







































































