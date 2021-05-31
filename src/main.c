#include <stdio.h>
#include <stdlib.h>
#include "saru-dlist.h"

#define PROJECT_NAME "saru-list"

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);

    struct saru_dll list;
    sdll_init(&list);

    char str[] = "HELLOWORLD!";
    struct node node;
    node.data = (void *)str;

    sdll_inserthead(&list, &node);

    struct node *curr = list.head;

    while (curr != NULL) {
        printf("%s\n", (char *)curr->data);
        curr = curr->next; 
    }

    return 0;
}
