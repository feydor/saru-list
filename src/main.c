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

    SDList list;
    sdlist_init(&list, NULL); // turn off element destructor

    char str1[] = "HELLOWORLD!";
    char str2[] = "GOODBYEWORLD!";
    struct node *n1 = sdlist_to_node((void *)str1);
    struct node *n2 = sdlist_to_node((void *)str2);

    sdlist_append(&list, n1);
    sdlist_append(&list, n2);
    sdlist_append(&list, sdlist_to_node((void *)"STRING3HERE"));

    printf("first traversal:\n");
    struct node *curr = list.head;
    while (curr != NULL) {
        printf("%s\n", (char *)curr->data);
        curr = curr->next; 
    }

    sdlist_remove(&list, n1);

    printf("second traversal:\n");
    for (curr = list.head; curr != NULL; curr = curr->next)
        printf("%s\n", (char *)curr->data);

    sdlist_destroy(&list);

    return 0;
}
