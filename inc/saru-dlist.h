#ifndef SARUDLIST_H
#define SARUDLIST_H

/* datatypes */
typedef struct node {
    struct node *next;
    struct node *prev;
    void *data;
} SDNode;

typedef struct saru_dlist {
    int size;
    struct node *head;
    struct node *tail;
    void (*destroy)(void *data);
} SDList;

/* public interface */
void sdlist_init(struct saru_dlist *dll, void (*destroy)(void *data));
struct node *sdlist_to_node(void *data);
int sdlist_append(struct saru_dlist *dll, struct node *node);
void  sdlist_destroy(struct saru_dlist *dll);

/* private functions */
int sdlist_insertafter(struct saru_dlist *dll, struct node *node, 
                                                struct node *new_node);
int sdlist_insertbefore(struct saru_dlist *dll, struct node *node,
                                                 struct node *new_node);
int sdlist_inserthead(struct saru_dlist *dll, struct node *node);
int sdlist_inserttail(struct saru_dlist *dll, struct node *node);

void sdlist_remove(struct saru_dlist *dll, struct node *node);

#endif

