#ifndef SARUDLIST_H
#define SARUDLIST_H

/* datatypes */
struct node {
    struct node *next;
    struct node *prev;
    void *data;
};

struct saru_dll {
    int size;
    struct node *head;
    struct node *tail;
};

/* function prototypes */
void sdll_init(struct saru_dll *dll);
// void sdll_free(struct saru_dll *dll);
void sdll_insertafter(struct saru_dll *dll, struct node *node, 
                                            struct node *new);
void sdll_insertbefore(struct saru_dll *dll, struct node *node,
                                             struct node *new);
void sdll_inserthead(struct saru_dll *dll, struct node *n);
void sdll_inserttail(struct saru_dll *dll, struct node *n);

#endif

