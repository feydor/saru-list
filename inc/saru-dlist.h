#ifndef SARUDLIST_H
#define SARUDLIST_H

/* datatypes */
struct node {
    struct node *next;
    struct node *prev;
    void *data;
};

struct saru_dlist {
    int size;
    struct node *head;
    struct node *tail;
    void (*destroy)(void *data);
};

/* function prototypes */
void sdlist_init(struct saru_dlist *dll, void (*destroy)(void *data));
void sdlist_insertafter(struct saru_dlist *dll, struct node *node, 
                                                struct node *new_node);
void sdlist_insertbefore(struct saru_dlist *dll, struct node *node,
                                                 struct node *new_node);
void sdlist_inserthead(struct saru_dlist *dll, struct node *node);
void sdlist_inserttail(struct saru_dlist *dll, struct node *node);

#endif

