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

    char str1[] = "HELLOWORLD!";
    char str2[] = "GOODBYEWORLD!";
    struct node n1;
    struct node n2;
    n1.data = (void *)str1;
    n2.data = (void *)str2;

    sdlist_inserthead(&list, &n1);
    sdlist_insertafter(&list, &n1, &n2);

    printf("first traversal:\n");
    struct node *curr = list.head;
    while (curr != NULL) {
        printf("%s\n", (char *)curr->data);
        curr = curr->next; 
    }

    sdlist_remove(&list, &n1);

    printf("second traversal:\n");
    for (curr = list.head; curr != NULL; curr = curr->next)
        printf("%s\n", (char *)curr->data);

    return 0;
}
