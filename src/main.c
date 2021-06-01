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
    sdlist_pushback(list, str1);
    sdlist_pushback(list, "STRING3HERE");
    sdlist_pushfront(list, str2);

    printf("first traversal:\n");
    struct node *curr = sdlist_begin(list);
    while (curr != NULL) {
        printf("%s\n", (char *)curr->data);
        curr = curr->next; 
    }

    // _sdlist_remove(&list, n1);

    printf("second traversal:\n");
    for (curr = list.head; curr != NULL; curr = curr->next)
        printf("%s\n", sdlist_at(char, curr));

    sdlist_destroy(&list);

    return 0;
}
