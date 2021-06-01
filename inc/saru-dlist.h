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
void sdlist_destroy(struct saru_dlist *dll);

#define sdlist_size(list) (list.size)
#define sdlist_begin(list) list.head
#define sdlist_tail(list) (list.tail)

#define SDLIST_INIT(list, destroy) \
    struct saru_dlist list; \
    sdlist_init(&list, destroy)

#define sdlist_pushback(list, item) \
    _sdlist_pushback(&list, sdlist_to_node((void *)&item))

#define sdlist_pushfront(list, item) \
    _sdlist_pushfront(&list, sdlist_to_node((void *)&item))

#define sdlist_next(itr) \
    _sdlist_next(itr)

#define sdlist_at(type, itr) (type *)itr->data

/* private functions */
void _sdlist_next(struct node *node);
int _sdlist_pushfront(struct saru_dlist *dll, struct node *node);
int _sdlist_pushback(struct saru_dlist *dll, struct node *node);
int _sdlist_insertafter(struct saru_dlist *dll, struct node *node, 
                                                struct node *new_node);
int _sdlist_insertbefore(struct saru_dlist *dll, struct node *node,
                                                 struct node *new_node);
int _sdlist_inserthead(struct saru_dlist *dll, struct node *node);
int _sdlist_inserttail(struct saru_dlist *dll, struct node *node);

void _sdlist_remove(struct saru_dlist *dll, struct node *node);

#endif

