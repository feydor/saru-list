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

    struct saru_dlist list;
    sdlist_init(&list, NULL);

    char str[] = "HELLOWORLD!";
    struct node n1;
    struct node n2;
    n1.data = (void *)str;
    n2.data = (void *)str;

    sdlist_inserthead(&list, &n1);
    sdlist_inserthead(&list, &n2);

    struct node *curr = list.head;

    while (curr != NULL) {
        printf("%s\n", (char *)curr->data);
        curr = curr->next; 
    }

    return 0;
}
